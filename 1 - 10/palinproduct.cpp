#include <iostream>
using namespace std;

/*
A palindromic number reads the same both ways. 
The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
Find the largest palindrome made from the product of two 3-digit numbers.
*/

bool isPalindrome(int n) {
	// Source: https://leetcode.com/problems/palindrome-number/solution/

	// Negative numbers cannot be a palindrome
	// A number ending with 0 cannot be a palindrome unless it is 0 itself
	if(n < 0 || (n % 10 == 0 && n != 0)) return false; 

	// Split the number into two halves
	int half = 0;
	while(n > half) {
		half = (half * 10) + (n % 10);
		n /= 10;
	}

	// Compare the first half with the second half
	// Second case for odd digit numbers such as 12321: n = 12, half = 123
	return n == half || n == half / 10;
}

int main() {
	// Iterate through all 3 digit numbers and find largest palidrome product
	int largest = 0;
	for (int i = 999; i > 99; --i) {
		for (int j = 999; j > 99; --j) {
			int product = i * j;
			if(isPalindrome(product) && product > largest) {
				largest = product;
			}
		}
	}
	cout << largest << endl; // 906609
	return 0;
}