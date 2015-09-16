#include <bits/stdc++.h>
 
using namespace std;

int main(int argc, char** argv){
 
	vector< vector<int> > adj_lis;

	long long num_vert = stoll(argv[1]);
	long long num_edges = stoll(argv[2]);
/*
	int num_vert = 10;
	int num_edges = 20;
*/
	int pres_edges = 0;
	int max_weight = 30;
    srand ( time(NULL) );

    adj_lis.resize(num_vert);
    // A spanning tree is generated in order to make sure that the graph is a connected one.
    // THE GENERATED GRAPH IS GUARANTEED TO BE A CONNECTED ONE.
    for(int i=1; i<num_vert; i++)
    {
    	int random_vertex = rand()%i;
    	// adj_lis[i].push_back(random_vertex);
    	adj_lis[random_vertex].push_back(i);
    	pres_edges++;
    }
    // Done with the creation of a spanning tree.
    // Now addition of random edges has to be done.

    long long max_edges = num_vert*num_vert;
    long long counter = 0;
    
    // Two vertices are randomly generated, if they are not connected, they are connected.
    while((counter < max_edges) && (pres_edges < num_edges))
    {
    	int v1 = rand()%num_vert;
    	int v2 = rand()%num_vert;

    	if(v1 > v2)
    		swap(v1,v2);

    	if( (!(v1==v2)) && (find(adj_lis[v1].begin(), adj_lis[v1].end(), v2) == adj_lis[v1].end()) )
    	{
    		// An Edge connecting v1 and v2 does not exist.
	     	adj_lis[v1].push_back(v2);
	    	//adj_lis[v2].push_back(v1);
	    	pres_edges++;   		
    	}
    	counter++;
    }
/*
    cout<<num_vert<<" "<<pres_edges<<endl;

    for(int i = 0; i<num_vert; i++){
    	cout<<i<<": ";
    	for(int j=0; j< (adj_lis[i]).size(); j++)
    		cout<<adj_lis[i][j]<<" ";
    	cout<<endl;
    }
*/
    string count;
    ifstream read;
    read.open("counter.txt");
    read>>count;
    read.close();

    ofstream erase;
    erase.open("counter.txt");
    erase<<(stoi(count) + 1);
    erase.close();

    ofstream f;
    string s("Test/output_graph_");
    s += count;
    s += ".txt";
    f.open(s);

    bool first = true;

    cout<<"Writing"<<endl;

    // Writing the names of the vertices in the file.
    for(int i = 0; i < num_vert; ++i)
    {
    	if(first)
    	{
    		f<<i;
    		first = false;
    	}
    	else
    		f<<endl<<i;
    }

    f<<endl<<"#";
    
    // Writing the edges in the file.
    for(int i = 0; i<num_vert; i++)
    {
    	for(int j=0; j< (adj_lis[i]).size(); j++)
    	{
    		int weight = (rand() % max_weight) + 1;
    		f<<endl<<i<<" "<<adj_lis[i][j]<<" "<<weight;
    	}
    }

    f.close();

    return 0;
}