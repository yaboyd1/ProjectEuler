"""
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. 
The sum of these multiples is 23.
Find the sum of all the multiples of 3 or 5 below 1000.
"""

# The sum of all multiples of 3 are: 3 + 6 + 9 + 12 + 15...
# The sum of all multiples of 5 are: 5 + 10 + 15 + 20 + 25...
# Notice how 15 is in both of these sums
# This is because 15 is both divisible by 3 and 5
# By the Inclusion-Exclusion Principle: https://en.wikipedia.org/wiki/Inclusion%E2%80%93exclusion_principle
# We can find the multiples of 3 OR 5 by finding the multiplies of 3 + muliples of 5 - muliples of 3 AND 5
# mult3and5 = mult3 + mult5 - mult15

# NOTE: n(n+1)/2 = 1 + 2 + 3 + ... + n
# Therefore the sum of the multiples of 3 can be expressed as 3 * n(n+1)/2

def sumOfMultiples(num, max_limit):
	n = (max_limit - 1) // num
	print(n)
	return num * n * (n + 1) // 2

print(sumOfMultiples(3, 1000) + sumOfMultiples(5, 1000) - sumOfMultiples(3 * 5, 1000))
