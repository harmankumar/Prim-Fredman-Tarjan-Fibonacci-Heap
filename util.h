#include <bits/stdc++.h>
#include <boost/heap/fibonacci_heap.hpp>
#include <boost/heap/d_ary_heap.hpp>

#define INF numeric_limits<int>::max()

using namespace std;

struct comparator
{
	bool operator() (const pair<string,int>& a, const pair<string,int>& b) const
	{
		return a.second > b.second;
	}
};

typedef boost::heap::fibonacci_heap< pair<string,int>,  boost::heap::compare< comparator >, boost::heap::mutable_<true> > fib;
typedef boost::heap::d_ary_heap< pair<string,int>, boost::heap::arity<2>,  boost::heap::compare< comparator >, boost::heap::mutable_<true> > bin_heap;
typedef boost::heap::d_ary_heap< pair<string,int>, boost::heap::arity<2>,  boost::heap::compare< comparator >, boost::heap::mutable_<true> >::handle_type bin_handle;
typedef boost::heap::fibonacci_heap< pair<string,int>, boost::heap::compare< comparator >, boost::heap::mutable_<true> >::handle_type fib_handle;

