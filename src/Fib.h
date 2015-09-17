template <class V> class FibonacciHeap {
protected:
	node<V>* heap;	//Pointer to the min node.

public:

	FibonacciHeap()	// Constructor 
	{
		heap = NULL;
	}
	
	node<V>* emplace(V value) // Inserts a node in the heap with value V.
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

	void decreaseKey(node<V>* n, V value) // Modifies the value of the node pointed by n to the new value. 
	{

	}
