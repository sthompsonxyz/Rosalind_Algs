

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {

	string inString;

	cout << "plz give me a string of bases:\n" << endl;
	cin >> inString;

	if ( inString.length() >= 1000 ) {

		cout << "only for sequences of 1000nt or less, for some arbitrary reason..." << endl;

		return 0;

	}

	for ( string::reverse_iterator r_iter = inString.rbegin(); r_iter != inString.rend(); r_iter++ ) {
	
		switch ( *r_iter ) {
			case 'a':
			case 'A':
				cout << 'T';
				break;
			case 'c':
			case 'C':
				cout << 'G';
				break;
			case 'g':
			case 'G':
				cout << 'C';
				break;
			case 't':
			case 'T':
				cout << 'A';
				break;
			default:
				break;
		
		}
	}

	cout << endl;
	

	return 0;
}
