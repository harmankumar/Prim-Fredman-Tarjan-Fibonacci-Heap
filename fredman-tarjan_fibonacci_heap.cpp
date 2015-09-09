#include <bits/stdc++.h>
#include <boost/heap/fibonacci_heap.hpp>

using namespace std;

#define INF numeric_limits<int>::max()

struct comparator
{
	bool operator() (const pair<char,int>& a, const pair<char,int>& b) const
	{
		return a.second > b.second;
	}
};


vector<char> vertices;	// Contains names of all the vertices.
unordered_map<char, vector<pair<char,int> > > adj_lis;	// This is graph represented in the form of an adjacency list.
unordered_map<char, char> parent;	// This would contain the edges that form the MST, after the prim() subroutine has been applied on the graph.
unordered_map< char , boost::heap::fibonacci_heap< pair<char,int>, boost::heap::arity<2>,  boost::heap::compare< comparator >, boost::heap::mutable_<true> >::handle_type > pointer;	// This contains pointer to a vertex to it's location in the binary heap.
long long mst_weight = 0;	// This is the weight of the MST.

/*
Q ← PQinit()
for each vertex v in graph G
	key(v) ←∞ 
	pred(v) ← nil
	PQinsert(v, Q) 
	key(s) ← 0
while (!PQisempty(Q))
	v = PQdelmin(Q)
for each edge v-w s.t. w is in Q
if key(w) > c(v,w)
	PQdeckey(w, c(v,w), Q)
	pred(w) ← v
*/
void prim()
{
	set<char> visited;
	boost::heap::fibonacci_heap< pair<char,int>, boost::heap::arity<2>,  boost::heap::compare< comparator >, boost::heap::mutable_<true> > pq; 

///	Initializing the heap.	
	for(auto vit = vertices.begin(); vit != vertices.end(); ++vit)
	{
		parent[*vit] = *vit;
		pair<char,int> somepair = make_pair(*vit , INF);
		boost::heap::fibonacci_heap< pair<char,int>, boost::heap::arity<2>,  boost::heap::compare< comparator >, boost::heap::mutable_<true> >::handle_type pos = pq.emplace(somepair);
		pointer[*vit] = pos;
	}


	pair<char,int> mypair = make_pair(vertices[0] , 0);

  	pq.update(pointer[vertices[0]], mypair);
  	pq.update(pointer[vertices[0]]);	

	while(!pq.empty())
	{
		// cout<<"In the loop "<<pq.size()<<endl;	
		// for (auto shit = pq.ordered_begin(); shit != pq.ordered_end(); ++shit)
		// cout << (*shit).first <<" "<< (*shit).second <<'\n';

		auto it = (pq.top());
		pq.pop();
		mst_weight += it.second;	// Adding the cost of the edge to the weight of the MST
		visited.insert(it.first);	// Adding the vertex to the set of explored vertices. 

		auto edgeit = adj_lis[it.first];
		boost::heap::fibonacci_heap< pair<char,int>, boost::heap::arity<2>,  boost::heap::compare< comparator >, boost::heap::mutable_<true> >::handle_type loophandler;

		for(auto vecit = edgeit.begin(); vecit != edgeit.end(); vecit++)
		{
			if(visited.find((*vecit).first) == visited.end())
			{
				loophandler = pointer[(*vecit).first];
				if( (*loophandler).second > (*vecit).second )
				{
					// cout<<"Changing Priority "<<(*vecit).first<<" "<<(*vecit).second<<endl;
					// The priority has to be modified.
					parent[(*vecit).first] = it.first;
					mypair = make_pair( (*vecit).first, (*vecit).second);
					pq.update(loophandler, mypair);
					pq.update(loophandler);
				}
			}
		}
		
	
	}
}

int main()
{
	ifstream f;
	f.open("graphFile.txt");
	char name;

/// Reading the vertices from the file and storing them in a vector.
	while(1)
	{
		f>>name;
		if(name == '#')
			break;

		vertices.push_back(name);
	}
// Read the vertices.

	char v1,v2;
	int weight;

///	Reading the edges from the file and creating the adjacency list. 
	while( !f.eof() )
	{
		f>>v1>>v2>>weight;

	    auto it = adj_lis.find(v1);
	    auto it1 = adj_lis.find(v2);
	    pair< char, int> temp = make_pair(v2 , weight);
	    pair< char, int> temp1 = make_pair(v1 , weight);
	    if(it == adj_lis.end())
	    {
	    	vector< pair< char , int > > tempvec;
	    	tempvec.push_back(temp);
	    	adj_lis[v1] = tempvec;
	    }
	    else
	    {
	    	(it->second).push_back(temp);			    	
	    }

	    if(it1 == adj_lis.end())
	    {
	    	vector< pair< char , int > > tempvec;
	    	tempvec.push_back(temp1);
	    	adj_lis[v2] = tempvec;
	    }
	    else
	    {
	    	(it1->second).push_back(temp1);			    	
	    }
	}
// Edges read, adjacency list created.
//	Calculating the MST of the garph by running prim's algorithm on it.
	prim();
// Done.
	cout<<"The weight of the MST is "<<mst_weight<<endl;
	cout<<"The Edges of the MST are:"<<endl;

	for(auto hashit = parent.begin(); hashit != parent.end(); ++hashit)
	{
		cout<<hashit->first<<" "<<hashit->second<<endl;
	}

	return 0;
}