#include <iostream>
#include <cmath>
using namespace std;

/*
Find the difference between the sum of the squares of the 
first one hundred natural numbers and the square of the sum.
*/

// Keep adding the squares from [1, n]
int sumOfSquares(int n) {
	int sum = 0;
	for(int i = n; i >= 1; --i)
		sum += pow(i, 2);
	return sum;
}

// Keep adding [1, n], and then square
int squareOfSums(int n) {
	int sum = 0;
	for(int i = n; i >= 1; --i)
		sum += i;
	return pow(sum, 2);
}

int main() {
	cout << squareOfSums(10) - sumOfSquares(10) << endl; // 2640
	cout << squareOfSums(100) - sumOfSquares(100) << endl; // 25164150
	return 0;
}