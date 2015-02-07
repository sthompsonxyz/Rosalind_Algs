

#include <iostream>
#include <string>

using namespace std;

int main() {

	string inString;

	cout << "plz give me a string of bases:\n" << endl;
	cin >> inString;

	if ( inString.length() >= 1000 ) {

		cout << "only for sequences of 1000nt or less, for some arbitrary reason..." << endl;

		return 0;

	}


	for ( string::iterator iter = inString.begin(); iter != inString.end(); iter++ ) {
	
		switch ( *iter ) {
			case 'a':
			case 'A':
				cout << *iter;
				break;
			case 'c':
			case 'C':
				cout << *iter;
				break;
			case 'g':
			case 'G':
				cout << *iter;
				break;
			case 't':
			case 'T':
				cout << 'U';
				break;
			default:
				break;
		
		}
	}

	cout << endl;
	

	return 0;
}
