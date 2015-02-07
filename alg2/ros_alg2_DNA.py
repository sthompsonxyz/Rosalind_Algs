#!/usr/bin/python

import re

regx = re.compile('[^acgt]', re.I)

mySeq = 'GATGGAACTTGACTACGTAAATT'

mySeq = regx.sub('', mySeq)

regx = re.compile('t', re.I)

mySeq = regx.sub('U', mySeq)

print mySeq
