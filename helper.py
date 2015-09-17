import os
import subprocess
import shutil
import zipfile

def merge():
	shutil.copyfile( "util.h", "util1.h")
	with zipfile.ZipFile('src1.zip', "r") as z:
		z.extractall()
	f = open("util.h","w")
	h = open("count.txt","r")

	for num in h:
		count = int(num)
		break

	h.close()

	for k in range(count):
		mystr = "src1/" + "file_" + str(k+1)
		g = open(mystr,"r")
		for line in g:
			f.write(line)
		g.close()
		count += 1
		# print "In the loop"

	f.close()

def split():

	f = open("util.h","r")
	count = 1

	for line in f:
		mystr = "src1/" + "file_" + str(count)
		g = open(mystr,"w")
		g.write(line)
		g.close()
		count += 1

	f.close()
	h = open("count.txt","w")
	h.write(str(count-1))
	h.close()	
	shutil.rmtree('src1')

def process():
	shutil.copyfile("util1.h", "util.h")
	os.remove("util1.h")
	shutil.rmtree('src1')