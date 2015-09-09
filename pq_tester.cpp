#include <bits/stdc++.h>
#include <boost/heap/d_ary_heap.hpp>
#include <boost/heap/fibonacci_heap.hpp>

using namespace std;

struct comparator
{
	bool operator() (const pair<char,int>& a, const pair<char,int>& b) const
	{
		return a.second > b.second;
	}
};

int main()
{
	unordered_map<char , boost::heap::d_ary_heap< pair<char,int>, boost::heap::arity<2>, comparator ,boost::heap::mutable_<true> >::iterator > mymap;
	
	boost::heap::d_ary_heap< pair<char,int>, boost::heap::arity<2>,  boost::heap::compare< comparator >, boost::heap::mutable_<true> > pq; 
  	// boost::heap::compare<std::greater<int> > pair<char,int>   
  	pair<char,int> mypair;

  	mypair = make_pair('h',10);

	// (*handle).handle = handle; // store handle in node
  	boost::heap::d_ary_heap< pair<char,int>, boost::heap::arity<2>,  boost::heap::compare< comparator >, boost::heap::mutable_<true> >::handle_type handle1 = pq.emplace(make_pair('h',10)); 
 
   	mypair = make_pair('s',2);
  	boost::heap::d_ary_heap< pair<char,int>, boost::heap::arity<2>,  boost::heap::compare< comparator >, boost::heap::mutable_<true> >::handle_type handle2 = pq.emplace(make_pair('s',2)); 
	
  	cout<<(pq.top()).first<<endl;
  	cout<<(*handle1).second<<endl;
  	cout<<(*handle2).second<<endl;
  	mypair = make_pair('s',100);
  	pq.update(handle1, mypair);
  	pq.update(handle1);
  	cout<<"dsfd"<<endl;

  	while( !pq.empty() )
  	{
 		cout<<(pq.top()).first<<" "<<(pq.top()).second<<endl;
 		pq.pop();
  	}

/*	for (auto it2 = pq.ordered_begin(); it2 != pq.ordered_end(); ++it2)
    {	
    	std::cout << (*it2).first << '\n';	
	}
*/
	return 0;
}

/*


void decrease(handle_type handle, const_reference v);

Effects: Assigns v to the element handled by handle & updates the priority queue.

Complexity: Logarithmic.

Note: The new value is expected to be less than the current one

Requirement: data structure must be configured as mutable


*/

/*

    static handle_type s_handle_from_iterator(iterator const & it);

    Effects: Casts an iterator to a node handle.

    Complexity: Constant.

    Requirement: data structure must be configured as mutable
*/