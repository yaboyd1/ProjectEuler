#include <iostream>
using namespace std;

/*
The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:
13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1

It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.
Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million
*/

size_t numCollatzSteps(const size_t& n) {
	size_t count = 1; // Includes n itself as a term
	for(size_t i = n; i != 1; ++count)
		i % 2 ? i = 3 * i + 1 : i /= 2; 
	return count;
}

size_t maxCollatz(const size_t& LIMIT = 1e6) {
	size_t max = 0, max_collatz_num, steps;
	for(size_t i = 2; i < LIMIT; ++i) {
		steps = numCollatzSteps(i);
		if (steps > max) {
			max = steps;
			max_collatz_num = i;
		}
	}
	return max_collatz_num;
}

int main() {
	cout << maxCollatz() << endl; // 837799
	return 0;
}