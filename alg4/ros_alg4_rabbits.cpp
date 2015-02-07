

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {

	int n, k;

	cout << "something about rabbits..:" << endl;
	cout << "enter number of generations:" << endl;

	while(1) {
		cin >> n;

		if(!cin) {
			cout << "It obviously does need to be a number.. defaulting to 5..." << endl;
			cin.clear();
			cin.ignore();
			n = 5;
			break;
		}

		if ( n > 40 ) {
			cout << "For some arbitrary reason there is an upper limit of 40 generations" << endl;
			continue;
		} else if ( n <= 0 ) {
			cout << "I need something to work with, not negative numbers, between 1 and 40 plz" << endl;
			continue;
		} else {
			break;
		}
	}

	cout << "kindly indicate the number of offpsring pairs per generation:" << endl;
	while(1) {
		cin >> k;

		if(!cin) {
			cout << "It obviously does need to be a number.. defaulting to 3..." << endl;
			cin.clear();
			cin.ignore();
			k = 3;
			break;
		}

		if ( k > 5 ) {
			cout << "For some arbitrary reason there is an upper limit of 5 pairs of offspring per adult pair per generation" << endl;
			continue;
		} else if ( k <= 0 ) {
			cout << "I need something to work with, not negative numbers, between 1 and 5 plz" << endl;
			continue;
		} else {
			break;
		}
	}


	vector<long> adults(1);
	vector<long> newbs(1);
	adults[0] = 0;
	newbs[0] = 1;


	for ( int i = 0; i < n; i++ ) {

		long newlings = newbs.back();
		newbs.push_back(adults.back() * k);
		adults.push_back(newlings + adults.back());
		


	}

	cout << "There\'s " << adults.back() << " pairs of the fluffy little bastards now!" << endl;
	

	return 0;
}
