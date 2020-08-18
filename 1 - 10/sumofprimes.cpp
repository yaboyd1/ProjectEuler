#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
Find the sum of all the primes below two million.
*/

// Helper function that fills the array with a bunch of potential composites
// Skipping all even numbers but 2
void fill(vector<size_t>& v, const size_t& limit) {
	v.push_back(2);
	for(size_t i = 3; i < limit; i += 2)
		v.push_back(i);
}

// For every number, checks if the rest of the array is divisible by it
// If a divisible number is found, it is removed
void removeComposites(vector<size_t>& v) {
	const size_t LIMIT = floor(sqrt(v.size()));
	for(auto i = v.begin(); i != v.begin() + LIMIT; ++i) {
		//cout << "Checking " << *i << endl;
		for(auto j = i + 1; j != v.end(); ++j) {
			if (*j % *i == 0) {
				//cout << *j << endl;
				v.erase(j);
				if (j == v.end()) break;
			}
		}
	}
}

// Calculates the sum of all of the elements in an array
size_t sum(const vector<size_t>& v) {
	size_t sum = 0;
	for(size_t i = 0, n = v.size(); i < n; ++i)
		sum += v[i];
	return sum;
}

int main() {
	const size_t LIMIT = 2e6;
	vector<size_t> primes;
	fill(primes, LIMIT);

	removeComposites(primes);

	// for(size_t& i: primes)
	// 	cout << i << " ";

	cout << sum(primes) << endl; // 1179908154
	system("pause");
	return 0;
}