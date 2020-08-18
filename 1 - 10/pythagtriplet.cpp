#include <iostream>
using namespace std;

/*
A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
a^2 + b^2 = c^2

For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
*/

int main() {
	// Loop through all of the possibilies checking if it is a pythag triplet
	size_t a, b, c;
	for(a = 1; a <= 1000; ++a) {
		for(b = a + 1; b <= 1000 - a; ++b) {
			c = 1000 - b - a; // The last value can be calculated using algebra instead of another for loop
			if (a * a +  b * b == c * c) {
				cout << a << " " << b << " " << c << endl; // 200, 375, 425
				cout << a * b * c << endl; // 31875000
				break;
			}
		}
	}
	return 0;
}