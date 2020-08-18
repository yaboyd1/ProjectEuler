#include <iostream>
#include <cmath>
using namespace std;

/*
The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143 ?
*/

size_t largestPrime(size_t n) {
	// Every time we find a factor, divide the number by the factor and search again
	// If we go exhaust all of the possibilities [2, floor(sqrt(n))], it is (probably) the largest prime!
	for(size_t i = 2; i < floor(sqrt(n)); ++i) {
		if (n % i == 0) {
			n /= i;
			i = 2;
		}
	}
	return n;
}

int main() {
	const size_t NUM = 600851475143;
	cout << largestPrime(NUM) << endl; // 6857
	
	return 0;
}

// Bruteforcing code below

// Bruteforce to find out if a number is prime or not
bool isPrime(const size_t& n) {
	const int LIMIT = floor(sqrt(n));
	for(size_t i = 2; i < LIMIT; ++i)
		if(n % i == 0)
			return false;
	return true;
}

// Bruteforce to find the largest prime number
// Takes way too long :(
size_t findLargestPrime(const size_t& n) {
	for(size_t i = floor(sqrt(n)); i > 1; --i)
		if(n % i == 0 && isPrime(i))
			return i;
	return 0;
}