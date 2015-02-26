#!/usr/bin/perl

use strict;
use warnings;

my %codon_table = (

UUU => 'F',	CUU => 'L',	AUU => 'I',	GUU => 'V',
UUC => 'F',	CUC => 'L',	AUC => 'I',	GUC => 'V',
UUA => 'L',	CUA => 'L',	AUA => 'I',	GUA => 'V',
UUG => 'L',	CUG => 'L',	AUG => 'M',	GUG => 'V',
UCU => 'S',	CCU => 'P',	ACU => 'T',	GCU => 'A',
UCC => 'S',	CCC => 'P',	ACC => 'T',	GCC => 'A',
UCA => 'S',	CCA => 'P',	ACA => 'T',	GCA => 'A',
UCG => 'S',	CCG => 'P',	ACG => 'T',	GCG => 'A',
UAU => 'Y',	CAU => 'H',	AAU => 'N',	GAU => 'D',
UAC => 'Y',	CAC => 'H',	AAC => 'N',	GAC => 'D',
UAA => 'Stop',	CAA => 'Q',	AAA => 'K',	GAA => 'E',
UAG => 'Stop',	CAG => 'Q',	AAG => 'K',	GAG => 'E',
UGU => 'C',	CGU => 'R',	AGU => 'S',	GGU => 'G',
UGC => 'C',	CGC => 'R',	AGC => 'S',	GGC => 'G',
UGA => 'Stop',	CGA => 'R',	AGA => 'R',	GGA => 'G',
UGG => 'W',	CGG => 'R',	AGG => 'R',	GGG => 'G',
);

use DDP;

my $sequence = uc shift;

my @bases = split //, $sequence;

my @seq_triplets;
while(@bases > 0) {
	my $triplet = '';
	$triplet .= shift @bases if @bases;
	$triplet .= shift @bases if @bases;
	$triplet .= shift @bases if @bases;
	push @seq_triplets, $triplet if $triplet;
}

foreach (@seq_triplets) {
	if(defined $codon_table{$_}){
		if ( $codon_table{$_} eq 'Stop' ) {
			last;
		} else {
			print $codon_table{$_};
		}
	} else {
		last;
	}
}

print "\n";
