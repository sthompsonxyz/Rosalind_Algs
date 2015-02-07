#!/usr/bin/python

import sys
dnaseq = sys.argv[1]
aa = gg = cc = tt = 0

for base in dnaseq:
	if base == 'A':
		aa+=1
	if base == 'G':
		gg+=1
	if base == 'C':
		cc+=1
	if base == 'T':
		tt+=1

print "As: ", aa, "\n", "Cs: ", cc, "\n", "Gs: ", gg, "\n", "Ts: ", tt, "\n"

