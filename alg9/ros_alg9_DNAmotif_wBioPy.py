#!/usr/bin/python

import sys
from Bio import SeqIO


seqs = list()
for seq_record in SeqIO.parse("./fastaseqs.fa", "fasta"):
    seqs.append(seq_record)

#check all sequences are the same length
length = len(seqs[0].seq)
for z in seqs:
	if length != len(z.seq):
		sys.exit("all sequences need to be same length!\n")


Aprofile = list()
Cprofile = list()
Gprofile = list()
Tprofile = list()

profile = list()
for pos in range(0, length-1):
	a = c = g = t = 0
	for seq in seqs:
		if seq.seq[pos] == 'A':
			a = a+1
		elif seq.seq[pos] == 'C':
			c = c+1
		elif seq.seq[pos] == 'G':
			g = g+1
		elif seq.seq[pos] == 'T':
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

