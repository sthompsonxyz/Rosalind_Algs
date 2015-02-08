

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {

	string inString1;
	string inString2;

	cout << "plz give me the first string of bases:" << endl;
	cin >> inString1;

	cout << "right now give me another string of bases, it\'s got to be the same length as the first one:" << endl;
	cin >> inString2;

	if ( inString1.length() != inString2.length() ) {

		cout << "they\'ve got to be the same length... good day!..." << endl;

		return 0;

	}

	int distance = 0;
	for(int i = 0; i < inString1.length(); i++) {
		if ( inString1[i] != inString2[i] ) {
			distance++;
		}
	}
		
	cout << "The distance between the two sequences is: " << distance << endl;

	cout << endl;
	

	return 0;
}
