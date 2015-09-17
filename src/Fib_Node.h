template <class V> struct node 
{

public:
	// Data members.

	node<V>* prev;	// Pointer to previous sibling
	node<V>* next;	// Pointer to the next sibling.
	node<V>* child;	// Pointer to a child.
	node<V>* parent;	// Pointer to the parent.
	V value;	// Key, Value pair in the node.
	int degree;	//Degree of the node.
	bool marked;	// For cascading cuts, to check whether the node is marked or not.

	// Get functions.

	node<V>* getPrev() {return prev;}
	node<V>* getNext() {return next;}
	node<V>* getChild() {return child;}
	node<V>* getParent() {return parent;}
	V getValue() {return value;}
	bool isMarked() {return marked;}
	bool hasChildren() {return child;}
	bool hasParent() {return parent;}
};
