import os

f = open("util1.h","w")
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

f.close()