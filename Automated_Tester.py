import os
import subprocess
from timeit import timeit

def main():
	str = "g++ -I C:\Users\harman\Desktop\\" + "boost_1_55_0\\" + "boost_1_55_0 -std=c++11 prim_binary_heap.cpp -o prim"
	subprocess.call(str)
	mytime = timeit(stmt = "subprocess.call('prim')", setup = "import subprocess", number = 1)
	print mytime
	#call("mkdir harman")
if __name__ == '__main__':
	main()