

#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include <vector>

#include "sequence.h"


using namespace std;

int main(int argc, char* argv[]) {



	ifstream fasta_file;
	fasta_file.open("./testseqs.fasta", ifstream::in);
	if ( !fasta_file.is_open() ) {
		cout << "couldn\'t open the sequences file :( " << endl;
		return 1;
	}

	vector<sequence> some_sequences;
	
	string reg_string_1 = "^>[^\\n]+";
	regex reg1(reg_string_1);
	string file_line;
	
	while( getline( fasta_file, file_line ) ) {

		if ( regex_search(file_line, reg1) ) {
		
			sequence seq;
			seq.set_name(file_line);
			some_sequences.push_back(seq);
		} else {
			if ( !some_sequences.empty() ) {
						
				some_sequences.back().app_seq(file_line);			
			}
		}
	}

	cout << endl;

	for( vector<sequence>::iterator iter = some_sequences.begin(); iter != some_sequences.end(); iter++) {
		cout << "The GC content for: " << iter->get_name() << " is " << iter->calc_gc() << "%" << endl;
	}
	
	fasta_file.close();
	

	return 0;
}
