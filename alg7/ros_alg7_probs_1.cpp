

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;


double select_prob(vector<char>& population, char type) {

	int count = 0;
	bool removed = false;
	vector<char> selected_population;
	for( vector<char>::iterator iter = population.begin(); iter != population.end(); iter++) {
		
		if( *iter == type ) {
			if(!removed) {
				count++;
				removed = true;
			} else {
			
			selected_population.push_back(*iter);
			count++;
			}
		} else {
			selected_population.push_back(*iter);
		}
	}
	
	double probs = double(count) / double(population.size());
	population = selected_population;

	return probs;
}

vector<char>& pop_regen(vector<char>& population, int k, int m, int n) {

	population.clear();

        for( int i = 0; i < k; i++) {
                population.push_back('k');
        }
        for( int i = 0; i < m; i++) {
                population.push_back('m');
        }
        for( int i = 0; i < n; i++) {
                population.push_back('n');
        }

	
	return population;
}

int main() {

	//types for probs, could allow for any number of these
	int k, m, n;

	//get number of each type
	cout << "amount of k (homozygous dominant):" << endl;
	cin >> k;

	cout << "amount of m (heterozygous):" << endl;
	cin >> m;

	cout << "amount of n (homozygous recessive):" << endl;
	cin >> n;

	
	//setting up a vector of all types	
	vector<char> types;
	types.push_back('k');
	types.push_back('m');
	types.push_back('n');

	//setting up population with appropriate number of each type (this could be put off in a regen function)
	// also the whole thing can be more efficient by not creating a vector member for each class
	// but using a classname with int amount of each
	vector<char> population;
	
	//get prob of picking one of a type from a population of types
	//see func, could do number of prob levels (only need 2 at first, i.e chance of picking one then another)

	vector<double> prob_list;
	
	for (vector<char>::iterator types_iter = types.begin(); types_iter != types.end(); types_iter++) {
		for(vector<char>::iterator types_iter2 = types.begin(); types_iter2 != types.end(); types_iter2++) {
			population = pop_regen(population, k , m , n);
			double first_select = select_prob(population, *types_iter);
			double second_select = select_prob(population, *types_iter2);
			double these_probs = first_select * second_select;
			cout << "prob of " << *types_iter << " with " << *types_iter2 << " is: " << these_probs << endl;
			prob_list.push_back(these_probs);
		}
	}

	cout << prob_list.size() << endl;
	assert( prob_list.size() == 9 );

	double sum_of_elements;
	for_each(prob_list.begin(), prob_list.end(), [&](double n) { sum_of_elements += n; });
	cout << sum_of_elements << endl;

	//then add up total change of *zygousness
	
	// allele probs matrix:					HomCh HetCh homCh    anyDom		noDom
	// 0 is kk: AA x AA -> AA, AA, AA, AA   	1.0	0.0	0.0			1.0		0.0	
	// 1 is km: AA x Aa -> AA, Aa, AA, Aa 		0.5	0.5	0.0			1.0		0.0
	// 2 is kn: AA x aa -> Aa, Aa, Aa, Aa 		0.0	1.0	0.0			1.0		0.0

	// 3 is mk: Aa x AA -> AA, AA, Aa, Aa 		0.5	0.5	0.0			1.0		0.0
	// 4 is mm: Aa x Aa -> AA, Aa, Aa, aa 		0.25 0.5 0.25		0.75	0.25
	// 5 is mn: Aa x aa -> Aa, Aa, aa, aa 		0.5 0.0 0.5			0.5		0.5

	// 6 is nk: aa x AA -> Aa, Aa, Aa, Aa 		0.0 1.0 0.0			1.0		0.0
	// 7 is nm: aa x Aa -> Aa, aa, Aa, aa 		0.0 0.5 0.5			0.5		0.5
	// 8 is nn: aa x aa -> aa, aa, aa, aa 		0.0 0.0 1.0			0.0		1.0


	vector<double> anyDoms {1.0, 1.0, 1.0, 1.0, 0.75, 0.5, 1.0, 0.5, 0.0};
	vector<double> noDoms {0.0, 0.0, 0.0, 0.0, 0.25, 0.5, 0.0, 0.5, 1.0};
	vector<double> eachAnyDoms;
	vector<double> eachNoDoms;

	for ( int i = 0; i < 9; i++ ) {
		eachAnyDoms.push_back( prob_list[i] * anyDoms[i] );
		eachNoDoms.push_back( prob_list[i] * noDoms[i] );
	}

	sum_of_elements = 0.0;
	for_each(eachAnyDoms.begin(), eachAnyDoms.end(), [&](double n) { sum_of_elements += n; });
	cout << "Prob of dominant phenotype: " << sum_of_elements << endl;

	sum_of_elements = 0.0;
	for_each(eachNoDoms.begin(), eachNoDoms.end(), [&](double n) { sum_of_elements += n; });
	cout << "Prob of recessive phenotype: " << sum_of_elements << endl;

	return 0;
}
