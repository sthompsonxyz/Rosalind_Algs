

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

	int a = 0, c = 0, g = 0, t = 0;

	for ( string::iterator iter = inString.begin(); iter != inString.end(); iter++ ) {
	
		switch ( *iter ) {
			case 'a':
			case 'A':
				a++;
				break;
			case 'c':
			case 'C':
				c++;
				break;
			case 'g':
			case 'G':
				g++;
				break;
			case 't':
			case 'T':
				t++;
				break;
			default:
				break;
		
		}
	}

	cout << "A: " << a << "  C: " << c << "  G: " << g << "  T: " << t << endl;
	

	return 0;
}
