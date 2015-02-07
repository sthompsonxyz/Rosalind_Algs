#include "sequence.h"

#include <iostream>


sequence::sequence() {
	dna_seq = "";
}

void sequence::set_seq(std::string in_seq) {
	dna_seq = in_seq;
}

void sequence::app_seq(std::string in_seq) { 
	dna_seq = dna_seq + in_seq; 
}


std::string sequence::get_seq () const { 
	return dna_seq; 
}
		
void sequence::set_name(std::string in_name) { 
	name = in_name; 
}
		
std::string sequence::get_name () const { 
	return name; 
}

double sequence::calc_gc () {

	if ( dna_seq.empty() ) {
		std::cerr << "can\'t calc GC content of an empty sequence" << std::endl;
		return 0.00;
	}

	double at=0.00,gc=0.00;

	for ( std::string::iterator iter = dna_seq.begin(); iter != dna_seq.end(); iter++ ) {
	
		switch ( *iter ) {
			case 'a':
			case 'A':
			case 't':
			case 'T':
				at+=1.00;
				break;
			case 'c':
			case 'C':
			case 'g':
			case 'G':
				gc+=1.00;
				break;

			default:
				break;
		
		}
	}

	double gc_content = ( gc / (dna_seq.length()) ) * 100.00;

	return gc_content;
}




