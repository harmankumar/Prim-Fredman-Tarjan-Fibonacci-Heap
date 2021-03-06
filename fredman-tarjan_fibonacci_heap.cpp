#include "util.h"

//class implementing Union Find Data Structure with Path Compression
class UF    
{

public:
    int cnt; 
    unordered_map<string, int> sz;
    unordered_map<string, string> mapping;
	// Create an union find data structure with N isolated sets.
    UF(set<string> str)   
    {
    	int N = str.size();
        cnt = N;
		// id = new int[N];
		// sz = new int[N];
        for(auto it = str.begin(); it != str.end(); it++)	
        {
            mapping[*it] = *it;
            // id[i] = i;
	    	sz[*it] = 1;
		}
    }
    
    ~UF()	
    {
		// delete [] id;
		// delete [] sz;
    }
	// Return the id of component corresponding to object p.
    string find(string p)	
    {
        string root = mapping[p];
        while (root.compare(mapping[root]) != 0)
            root = mapping[root];

        string p1 = mapping[p];
        while (p1.compare(root) != 0) 
        {
            string newp = mapping[p1];
            mapping[p1] = root;
            p1 = newp;
        }
        return root;
    }
	// Replace sets containing x and y with their union.
    void merge(string x, string y)	{
        string i = find(x);
        string j = find(y);
        if (i.compare(j) == 0) 
        {	
        	return;
		}
		// make smaller root point to larger one
        if(sz[i] < sz[j])	
        { 
			mapping[i] = j; 
			sz[j] += sz[i]; 
		} 
		else	
		{ 
			mapping[j] = i; 
			sz[i] += sz[j]; 
		}
        cnt--;
    }
	// Are objects x and y in the same set?
    bool connected(string x, string y)    
    {
        return (find(x).compare(find(y)) == 0);
    }
	// Return the number of disjoint sets.
    int count() 
    {
        return cnt;
    }
};

int counter = 0;
int num_edges = 0;
int num_vertices = 0;
int heapSize = 0;
set<string> vertices;	// Contains names of all the vertices.
unordered_map<string, unordered_map<string,int> > adj_lis;	// This is graph represented in the form of an adjacency list.
unordered_map<string, string> parent;	// This would contain the edges that form the MST, after the prim() subroutine has been applied on the graph.
long long mst_weight = 0;	// This is the weight of the MST.

void fredman_tarjan(UF disjoint_set)
{
	if(heapSize == 0)	// First iteration
	{	
		heapSize = num_edges/num_vertices;	
	}
	else
	{
		heapSize = pow(2,heapSize);
	}
	
	set<string> visited;	// Set of explored vertices.

	for(auto iter = vertices.begin(); iter != vertices.end(); iter++)
	{	
		if(visited.find(disjoint_set.find(*iter)) == visited.end())	// The vertex has not yet been explored
		{
			fib pq; 
			auto edgeit1 = adj_lis[*iter];
			unordered_map< string , fib_handle > pointer;	// This contains pointer to a vertex to it's location in the binary heap.
			pair<string,int> somepair; 
			fib_handle pos;
			for(auto vecit1 = edgeit1.begin(); vecit1 != edgeit1.end(); vecit1++)
			{
				somepair = make_pair((*vecit1).first, (*vecit1).second);
				pos = pq.emplace(somepair);
				pointer[(vecit1)->first] = pos;
			}

			while(!pq.empty())
			{
				auto it = (pq.top());
				if((pq.size() > heapSize) || (visited.find(it.first) != visited.end()) || (disjoint_set.connected(it.first, *iter) ) )	// Size of the heap is too large or the node popped is a part of some other MST.
				{
					break;
				}
				
				visited.insert(*iter);
				visited.insert(it.first);

				pq.pop();
				mst_weight += it.second;	// Adding the cost of the edge to the weight of the MST
				visited.insert(it.first);	// Adding the vertex to the set of explored vertices. 
					

				disjoint_set.merge(it.first,*iter);
			    
			    counter++;

				auto edgeit = adj_lis[it.first];
				fib_handle loophandler;

				for(auto vecit = edgeit.begin(); vecit != edgeit.end(); vecit++)
				{
					if( ((*vecit).first).compare(*iter) == 0)
						continue;
					if(pointer.find((*vecit).first) == pointer.end())	// The vertex is not present in the heap.
					{
						somepair = make_pair((*vecit).first, (*vecit).second);
						pos = pq.emplace(somepair);
						pointer[(*vecit).first] = pos;
					}
					else
					{
						if(visited.find((*vecit).first) == visited.end())
						{
							loophandler = pointer[(*vecit).first];
							if( (*loophandler).second > (*vecit).second )
							{
								somepair = make_pair( (*vecit).first, (*vecit).second);
								pq.update(loophandler, somepair);
								pq.update(loophandler);
							}
						}
					}
				}
			}
		}
	}

	// All vertices have been visited.
	if(disjoint_set.cnt == 1)	// The MST has been computed.
		return;

	//If the MST has not yet been computed, perform a contraction and run it again.
	unordered_map<string, unordered_map<string,int> > new_adj_lis;
	set<string> newvertices;

/*
The contraction is performed as follows:
	1) Relabel the vertices based on the component they belong to.
	2) The edges between vertices belonging to the same set are removed. 
	3) Only the min-cost edge joining two different sets is kept.
*/
	for(auto it = vertices.begin(); it != vertices.end(); it++)
	{	
		string set_of = disjoint_set.find(*it);
		if(newvertices.find(set_of) == newvertices.end())
		{
			newvertices.insert(set_of);
		}
	}
	vertices = newvertices;	// Updated the vertices.

	unordered_map<string,int> mymap;
	for(auto it = newvertices.begin(); it != newvertices.end(); it++)
		new_adj_lis[*it] = mymap;


	for(auto it = adj_lis.begin(); it != adj_lis.end(); it++)
	{
		for (auto vecit = ((*it).second).begin(); vecit != ((*it).second).end(); vecit++)
		{
			if( ! disjoint_set.connected( (*it).first,(*vecit).first ) )	// The vertices lie in different components.
			{
				if( (new_adj_lis[disjoint_set.find((*it).first)] ).find((*vecit).first) == (new_adj_lis[(*it).first]).end() )
					new_adj_lis[disjoint_set.find((*it).first)][disjoint_set.find((*vecit).first)] = (*vecit).second;

				else if(new_adj_lis[disjoint_set.find((*it).first)][disjoint_set.find( (*vecit).first)] > (*vecit).second)
					new_adj_lis[disjoint_set.find((*it).first)][disjoint_set.find( (*vecit).first)] = (*vecit).second;
			}
		}
	}

	adj_lis = new_adj_lis;

	fredman_tarjan(disjoint_set);
}

int main()
{
	time_t start_time,end_time;
	ifstream f;
	f.open("graphFile.txt");
	string name;

/// Reading the vertices from the file and storing them in a vector.
	while(1)
	{

		f>>name;
		if(name.compare("#") == 0)
			break;
		num_vertices++;
		vertices.insert(name);
	}
// Read the vertices.

	string v1,v2;
	int weight;

///	Reading the edges from the file and creating the adjacency list. 
	while( !f.eof() )
	{
		num_edges++;
		f>>v1>>v2>>weight;
		adj_lis[v1][v2] = weight;
		adj_lis[v2][v1] = weight;
	}
	f.close();
// Edges read, adjacency list created.
//	Calculating the MST of the garph by running prim's algorithm on it.
	
	UF disjoint_set(vertices);	// Creating a disjoint set on the vector of vertices.
	start_time = time(NULL);
	fredman_tarjan(disjoint_set);
	end_time = time(NULL);
	// cout<<"Good Luck "<<num_edges<<endl;

// Done.
	// cout<<"The weight of the MST is "<<mst_weight<<endl;
	// cout<<"Time taken is "<<difftime(end_time,start_time)<<endl;
	cout<<difftime(end_time,start_time);
/*
	cout<<"The Edges of the MST are:"<<endl;
	for(auto hashit = parent.begin(); hashit != parent.end(); ++hashit)
	{
		cout<<hashit->first<<" "<<hashit->second<<endl;
	}
*/
	return 0;
}
