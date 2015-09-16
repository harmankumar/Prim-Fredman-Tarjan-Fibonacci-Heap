import os

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

# Make a zip, unzip etc...