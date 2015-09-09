#include <bits/stdc++.h>
#include <boost/heap/d_ary_heap.hpp>

using namespace std;

struct vertex{
	char name;
	int key;
};

struct comparator
{
	bool operator() (const pair<char,int>& a, const pair<char,int>& b) const
	{
		return a.second > b.second;
	}
};

vector<char> vertices;
unordered_map<char, vector<pair<char,int> > > adj_lis;
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


}

int main()
{
	ifstream f;
	f.open("graphFile.txt");
	char name;
	vertex myvertex;

	// Taking Input from the file.
	while(1)
	{
		vertex myvertex;
		f>>name;
		if(name == '#')
			break;
		cout<<"A vertex Encountered "<<name<<endl;
		//myvertex.mame = name;
		//myvertex.key = numeric_limits<int>::max()
		//vertices.push_back(myvertex);
	}
	char v1,v2;
	int weight;
	
	while( !f.eof() )
	{
		f>>v1>>v2>>weight;
		cout<<"An edge encountered "<<v1<<" "<<v2<<" "<<weight<<endl;;
	}
	// Input taken.
	prim();
	return 0;
}