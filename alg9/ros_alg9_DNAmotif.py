#!/usr/bin/python

import re
import pprint
import sys
from Bio import SeqIO

class sequence:
	name = ''
	bases = ''

seqs = list()
regx = re.compile("^>[^\\n]+", re.I)
myF = open("./fastaseqs.fa")
next_seq = sequence()

# gets fasta sequences from file and puts them into seq object for manip
# look at using biopython class here..
while 1:
	line = myF.readline()
	if not line:
		store_seq = sequence()
		store_seq.name = next_seq.name
		store_seq.bases = next_seq.bases
		seqs.append(store_seq)
		break
	if regx.search(line):
		if next_seq.name:
			store_seq = sequence()
			store_seq.name = next_seq.name
			store_seq.bases = next_seq.bases
			seqs.append(store_seq)
		next_seq.bases = ''
		next_seq.name = line.rstrip()
	else:
		next_seq.bases = next_seq.bases + line.rstrip()


#check all sequences are the same length
length = len(seqs[0].bases)
for z in seqs:
	if length != len(z.bases):
		sys.exit("all sequences need to be same length!\n")


Aprofile = list()
Cprofile = list()
Gprofile = list()
Tprofile = list()

profile = list()
for pos in range(0, length-1):
	a = c = g = t = 0
	for seq in seqs:
		if seq.bases[pos] == 'A':
			a = a+1
		elif seq.bases[pos] == 'C':
			c = c+1
		elif seq.bases[pos] == 'G':
			g = g+1
		elif seq.bases[pos] == 'T':
			t = t+1
	Aprofile.append(a)
	Cprofile.append(c)
	Gprofile.append(g)
	Tprofile.append(t)

print "A: ",
for i in range(0, length-1):
	print Aprofile[i],
print "\nC: ",
for i in range(0, length-1):
	print Cprofile[i],
print "\nG: ",
for i in range(0, length-1):
	print Gprofile[i],
print "\nT: ",
for i in range(0, length-1):
	print Tprofile[i],

for seq_record in SeqIO.parse("./fastaseqs.fa", "fasta"):
    print seq_record.id
    print seq_record.seq
    print(len(seq_record))