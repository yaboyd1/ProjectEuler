#include <iostream>
using namespace std;

/*
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
Find the sum of all the primes below two million.
*/

#define size_t unsigned long long

/* NOTE: isPrime function is generally incorrect and only works in this program */

bool isPrime(const size_t& n) {
	for (size_t i = 3; i * i <= n; ++i)
		if (n % i == 0)
			return false;
	return true;
}

size_t sumOfPrimes(const size_t& LIMIT) {
	size_t sum = 2 + 3; // 2 and 3 are already prime
	for (size_t i = 5; i < LIMIT; i += 2) // Skipping even numbers
		if (isPrime(i))
			sum += i;
	return sum;
}

int main() {
	cout << sumOfPrimes(2e6) << endl; // 142913828922
	return 0;
}

// Before small optimizations

/*
bool isPrime(size_t n) {
	if(n <= 1) return false;
	for(size_t i = 2; i * i <= n; ++i)
		if(n % i == 0)
			return false;
	return true;
}

int main() {
	const int LIMIT = 2e6;
	size_t sum = 0;
	for(size_t i = 2; i < LIMIT; ++i)
		if(isPrime(i))
			sum += i;
	cout << sum << endl; // 142913828922
} */