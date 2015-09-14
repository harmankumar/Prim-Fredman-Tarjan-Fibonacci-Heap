#include <bits/stdc++.h>

using namespace std;

class UF    
{
public:
    int cnt; 
    unordered_map <string, int> sz;
    unordered_map <string, string> mapping;
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
        	return;
		
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

int main()
{
    set<string> arr;
    arr.insert("a");   
    arr.insert("b");
    arr.insert("c");
    arr.insert("d");
    arr.insert("e");

    UF dis_set(arr);

    cout<<dis_set.count()<<endl;

    cout<<dis_set.connected("a" , "b")<<endl;

    dis_set.merge("a" , "b");
    cout<<dis_set.count()<<endl;

    cout<<dis_set.connected("a" , "b")<<endl;

    cout<<dis_set.find("a")<<endl;

    for(auto itx = dis_set.sz.begin(); itx != dis_set.sz.end(); itx++)
        cout<<itx->first<<" "<<itx->second<<endl;

    for(auto itx = dis_set.mapping.begin(); itx != dis_set.mapping.end(); itx++)
        cout<<itx->first<<" "<<itx->second<<endl;

    return 0;
}