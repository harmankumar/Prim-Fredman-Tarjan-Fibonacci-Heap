class UF    
{
    int cnt;	//count of the number of disjoint sets. 
    unordered_map<string, int> sz;	// Size of a set.
    unordered_map<string, string> mapping;	// For parent relation.

public:
    UF(set<string> str)	// Create an union find data structure with N isolated sets.
            
    ~UF()	// Destructor.

    string find(string p)	// Return the id of component corresponding to object p.

    void merge(string x, string y)	// Replace sets containing x and y with their union.
    
    bool connected(string x, string y)   // Are objects x and y in the same set?

    int count()		// Return the number of disjoint sets.

};