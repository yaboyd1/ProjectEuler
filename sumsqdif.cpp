#include <iostream>
#include <cmath>
using namespace std;

/*
Find the difference between the sum of the squares of the 
first one hundred natural numbers and the square of the sum.
*/

// Keep adding the squares from [n, 1]
int sumOfSquares(int n) {
	int sum = 0;
	for(int i = n; i >= 1; --i)
		sum += pow(i, 2);
	return sum;
}

// Keep adding [n, 1] and then square
int squareOfSums(int n) {
	int sum = 0;
	for(int i = n; i >= 1; --i)
		sum += i;
	return pow(sum, 2);
}

int main() {
	cout << sumOfSquares(10) - squareOfSums(10) << endl;
	cout << sumOfSquares(100) - squareOfSums(100) << endl;
	return 0;
}