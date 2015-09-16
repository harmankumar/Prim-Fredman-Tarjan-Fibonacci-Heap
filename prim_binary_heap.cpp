#include "util.h"

using namespace std;

vector<string> vertices;	// Contains names of all the vertices.
unordered_map<string, unordered_map<string,int> > adj_lis;	// This is graph represented in the form of an adjacency list.
unordered_map<string, string> parent;	// This would contain the edges that form the MST, after the prim() subroutine has been applied on the graph.
unordered_map< string , bin_handle > pointer;	// This contains pointer to a vertex to it's location in the binary heap.
long long mst_weight = 0;	// This is the weight of the MST.

/// Prim's algorithm in pseudocode. 
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
	set<string> visited;
	bin_heap pq; 

///	Initializing the heap.	
	for(auto vit = vertices.begin(); vit != vertices.end(); ++vit)
	{
		parent[*vit] = *vit;
		pair<string,int> somepair = make_pair(*vit , INF);
		bin_handle pos = pq.emplace(somepair);
		pointer[*vit] = pos;
	}


	pair<string,int> mypair = make_pair(vertices[0] , 0);

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
		bin_handle loophandler;

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

int main(int argc, char** argv)
{
	string filename("graphFile.txt");
	// string filename = argv[1];
	time_t start_time,end_time;
	ifstream f;
	f.open(filename);
	string name;

/// Reading the vertices from the file and storing them in a vector.
	while(1)
	{
		f>>name;
		if(name.compare("#") == 0)
			break;

		vertices.push_back(name);
	}
// Read the vertices.

	string v1,v2;
	int weight;

///	Reading the edges from the file and creating the adjacency list. 
	while( !f.eof() )
	{
		f>>v1>>v2>>weight;
		adj_lis[v1][v2] = weight;
		adj_lis[v2][v1] = weight;
	}
	f.close();
// Edges read, adjacency list created.
//	Calculating the MST of the garph by running prim's algorithm on it.
	start_time = time(NULL);
	prim();
	end_time = time(NULL);
// Done.
	// cout<<"The weight of the MST is "<<mst_weight<<endl;
	// cout<<"Time taken is "<<difftime(end_time,start_time)<<endl;
	cout<<difftime(end_time,start_time);
// If the Edges of the MST have to be printed, Uncomment the following part
/*
	cout<<"The Edges of the MST are:"<<endl;

	for(auto hashit = parent.begin(); hashit != parent.end(); ++hashit)
	{
		cout<<hashit->first<<" "<<hashit->second<<endl;
	}
*/
	return 0;
}