#!/usr/bin/python


mySeq = 'AAAACCCGGT'
myOut = ''

for base in mySeq:
	if base == 'A':
		myOut = myOut + 'T'
	if base == 'C':
		myOut = myOut + 'G'
	if base == 'G':
		myOut = myOut + 'C'
	if base == 'T':
		myOut = myOut + 'A'

print myOut[::-1]

