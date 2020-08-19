#include <iostream>
using namespace std;

/*
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
What is the 10 001st prime number?
*/

/* NOTE: isPrime function is generally incorrect and only works in this program */

bool isPrime(const size_t& n) {
	for (size_t i = 2; i * i <= n; ++i)
		if (n % i == 0)
			return false;
	return true;
}

size_t primeAtPos(const size_t& LIMIT) {
	size_t count = 2, i; // Already counting 2 and 3
	for (i = 5; count < LIMIT; i += 2) // Skipping even numbers
		if (isPrime(i))
			++count;
	return i - 2;
}

int main() {
	const size_t LIMIT = 10001;
	cout << primeAtPos(LIMIT) << endl; //104743
	return 0;
}