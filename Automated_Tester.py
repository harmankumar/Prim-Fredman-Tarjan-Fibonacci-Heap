import os
from helper import *
import subprocess
from os.path import isfile, join
from timeit import timeit
from random import randint
import shlex


# Checking if all the required files are present or not.
def initializer():
	onlyfiles = [ f for f in os.listdir('.') if isfile(f) ]
	if(not("prim_binary_heap.cpp" in onlyfiles)):
		print "prim_binary_heap.cpp NOT FOUND"
	if(not("Random_Graph.cpp" in onlyfiles)):
		print "Random_Graph.cpp NOT FOUND"
	if(not("fredman-tarjan_fibonacci_heap.cpp" in onlyfiles)):
		print "fredman-tarjan_fibonacci_heap.cpp NOT FOUND"
	merge()

def main():

	initializer()
	# Compiling the programs.
	str1 = "g++ -o0 -I C:\Users\harman\Desktop\\" + "boost_1_55_0\\" + "boost_1_55_0 -std=c++11 prim_binary_heap.cpp -o prim"
	str2 = "g++ -o0 -I C:\Users\harman\Desktop\\" + "boost_1_55_0\\" + "boost_1_55_0 -std=c++11 fredman-tarjan_fibonacci_heap.cpp -o tarjan"
	str3 = "g++ -o3 -std=c++11 Random_Graph.cpp -o random"
	subprocess.call(str1)
	subprocess.call(str2)
	subprocess.call(str3)
	# Compiled.
	process()

	# Dense Graphs.
	i = 100
	j = 125
	for k in range(10000000):
		if(i > 100000000):
			break
		ran1 = randint(i,j)
		ran2 = randint(ran1,min((ran1*(ran1-1)/2),2000000000))
		print str(ran1) + " " + str(ran2)

		con = open("config.txt","w")
		con.write(str(ran1) + " " + str(ran2))
		con.close()

		subprocess.call("random")
		print "Done"
		subprocess.call("prim.exe")
		print "Prim Done"
		subprocess.call("tarjan.exe")
		print "Tarjan Done"

		pr = open("prim_timing.txt")
		fr = open("tarjan_timing.txt")
		vertices = 0
		edges = 0		
		time_pr = 0
		time_fr = 0
		for line in pr:
			words = line.split()
			vertices = words[0]
			edges = words[1]
			time_pr = words[2]
			break
		for line in fr:
			words = line.split()
			time_fr = words[2]
			break
		pr.close()
		fr.close()
		strin = vertices + " " + edges + " " + time_pr + " " + time_fr 
		res = open("Results.txt", "a")
		res.write(strin)
		res.write("\n")
		res.close()
		i = j
		j *= 1.25
		j = int(j)	

	# Sparse Graphs.
	i = 100
	j = 125
	for k in range(10000000):
		if(i > 100000000):
			break
		ran1 = randint(i,j)
		ran2 = randint(ran1,min(ran1*10,2000000000))
		print str(ran1) + " " + str(ran2)

		con = open("config.txt","w")
		con.write(str(ran1) + " " + str(ran2))
		con.close()

		subprocess.call("random")
		print "Done"
		subprocess.call("prim.exe")
		print "Prim Done"
		subprocess.call("tarjan.exe")
		print "Tarjan Done"

		pr = open("prim_timing.txt")
		fr = open("tarjan_timing.txt")
		vertices = 0
		edges = 0		
		time_pr = 0
		time_fr = 0
		for line in pr:
			words = line.split()
			vertices = words[0]
			edges = words[1]
			time_pr = words[2]
			break
		for line in fr:
			words = line.split()
			time_fr = words[2]
			break
		pr.close()
		fr.close()
		strin = vertices + " " + edges + " " + time_pr + " " + time_fr 
		res = open("Results.txt", "a")
		res.write(strin)
		res.write("\n")
		res.close()
		i = j
		j *= 1.25
		j = int(j)
	
	# mytime = timeit(stmt = "subprocess.call('prim')", setup = "import subprocess", number = 1)
	# print mytime;

	
if __name__ == '__main__':
	main()