template <class V> class FibonacciHeap {
protected:
	node<V>* heap;	//Pointer to the min node.

public:

	FibonacciHeap()	// Constructor 
	{
		heap=NULL;
	}
	
	~FibonacciHeap() //Destructor
	{
		if(heap) 
		{
			clear_all(heap);	// Recursively deletes all nodes in the heap.
		}
	}
	node<V>* insert(V value) // Inserts a node in the heap with value V.
	{

	}
	
	void merge_lazy(FibonacciHeap& other) // Links the two heaps together and updates the min pointer.
	{

	}

	bool isEmpty() // Tells whether the heap is empty.
	{

	}

	V top() // Returns the value of the smallest element of the heap.
	{

	}

	V pop() // Removes the smallest element of the heap
	{

	}

	void decreaseKey(node<V>* n, V value) // Decreases the value of the node pointed by n to the new value. 
	{

	}
