import os
from helper import *
import subprocess
import zipfile
from timeit import timeit



def main():
	# Compiling the programs.

	merge()

	str1 = "g++ -o0 -I C:\Users\harman\Desktop\\" + "boost_1_55_0\\" + "boost_1_55_0 -std=c++11 prim_binary_heap.cpp -o prim"
	str2 = "g++ -o0 -I C:\Users\harman\Desktop\\" + "boost_1_55_0\\" + "boost_1_55_0 -std=c++11 fredman-tarjan_fibonacci_heap.cpp -o tarjan"

	subprocess.call(str1)
	subprocess.call(str2)

	# Compiled.


		
	# mytime = timeit(stmt = "subprocess.call('prim')", setup = "import subprocess", number = 1)
	# print mytime;

	finale()

if __name__ == '__main__':
	main()