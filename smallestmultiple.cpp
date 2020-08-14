#include <iostream>
using namespace std;

/*
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

// Bruteforce helper function to check if a number is divisible from [2, range]
bool isDivisibleRange(size_t n, size_t range) {
	for(size_t i = 2; i <= range; ++i)
		if (n % i != 0)
			return false;
	return true;
}

// Bruteforce: Adding until it is divisible
size_t smallestNumDivisibleByRange(size_t range) {
	size_t answer;
	for(answer = range; !isDivisibleRange(answer, range); answer += range);
	return answer;
}

int main() {
	cout << smallestNumDivisibleByRange(10) << endl; // 2520
	cout << smallestNumDivisibleByRange(20) << endl; // 232792560
	return 0;
}