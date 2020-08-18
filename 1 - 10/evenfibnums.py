"""
Each new term in the Fibonacci sequence is generated by adding the previous two terms. 
By starting with 1 and 2, the first 10 terms will be:
1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
By considering the terms in the Fibonacci sequence whose values do not exceed four million, 
find the sum of the even-valued terms.
"""

# Playing around with the fibonacci numbers and python syntax

fib = [1, 2]

while(fib[-1] < 4000000):
	fib.append(fib[-1] + fib[-2])

print("\nExceeds 4 million :(")
print(fib)

# The last value is not less than 4 million :(
# I know we can simply just do "del fib[-1]" but I don't wanna
# Python doesn't have do while loops so let's make our own

fib2 = fib[:2] # Copy the first two values

while True:
	value = fib2[-1] + fib2[-2]
	if value > 4000000:
		break
	fib2.append(value);

print("\nDoes not exceed 4 million :)")
print(fib2)

# Yay! These are all of the fibonacci numbers not exceeding 4 million

even_fib_numbers = []
for i in fib2:
	if i % 2 == 0:
		even_fib_numbers.append(i)

print("\nEven Finonacci Numbers:")
print(even_fib_numbers)

print("\nSum of Even Finonacci Numbers:")
print(sum(even_fib_numbers))

# Every third element in the fib sequence is an even number if you notice
# [2, 8, 34, 144, 610, 2584, 10946, 46368, 196418, 832040, 3524578]
# We can express this as: E(n) = 4 * E(n - 1) + E(n - 2)
# For example: 34 == 4 * 8 + 2 is True
# This would save us the check of whether it is even or not
# Let's visual and code the sequence

even_fib_numbers2 = even_fib_numbers[:2] # Start with the first two even fib values
while True:
	value = 4 * even_fib_numbers2[-1] + even_fib_numbers2[-2]
	if value > 4000000:
		break
	even_fib_numbers2.append(value)

print("\nUsing E(n) = 4 * E(n - 1) + E(n - 2), the even fib numbers are:")
print(even_fib_numbers2)

print("This is the same output as our prev implementation! :)") if even_fib_numbers2 == even_fib_numbers else print("This is not the same output as our prev implementation :(")