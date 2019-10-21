// Going thru project euler exercises
// in c++ 

#include <iostream>
#include <string>
#include <math.h>
#include <list>
//#include <bits/stdc++.h>
#include <cmath>
#include <cassert>

using namespace std;

int soln1;
int soln2;
int soln3;
int soln4;
int soln5;
int soln6;

int sum_of_multiples(int x1, int x2, int n);
int even_fib_sum(int n);
int fib(int n);
bool is_prime(int n);
int largest_prime_factor(long long int n);
bool is_palindrome(int n);
int largest_palindromic_product(int digits);
int evenly_disible(int n);
int gcd(int a, int b);
int lcm(int a, int b);
int problem5();
int sum_of_squares(int n);
int square_of_sum(int n);
int problem6();


int main()
{
	
	soln1 = sum_of_multiples(3,5,1000);
	soln2 = even_fib_sum(4000000);
	soln3 = largest_prime_factor(600851475143);
	soln4 = largest_palindromic_product(3);
	soln5 = problem5();
	soln6 = problem6();
	
	cout << "\n--- Project Euler ---" << endl;
	cout << endl;

	cout << "1. The sum of all multiples of 3 and 5 below 1000 is: " << soln1 << endl;
	cout << "2. The sum of even Fibonacci numbers below 4,000,000 is: " << soln2 << endl;
	cout << "3. The largest prime factor of '600851475143' is: " << soln3 << endl;
	cout << "4. The largest palindomic product of two 3 digit numbers is: "
	<< soln4 << endl;
	cout << "5. The smallest number evenly divisible by 1,2,...,20 is: " << soln5 << endl;
	cout << "6. The absolute difference between the square of sum, and sum of squares "
	<< "of all positive integers (1,2,..., 100) is: " << soln6 << endl;
	
	cout << endl;

	assert(sum_of_squares(10) == 385);
	assert(square_of_sum(10) == 3025);
	// cout << "GCD test: \n\n";
	// cout << "gcd(1,5) = " << gcd(1,5) << endl;
	// cout << "gcd(3,9) = " << gcd(3,9) << endl;
	// cout << "gcd(6,15) = " << gcd(6, 15) << endl;

	// cout << endl;
	// cout << "LCM test: \n\n";
	// cout << "lcm(3,4) = " << lcm(3,4) << endl;
	// cout << "lcm(9,18) = " << lcm(9,18) << endl;


	// cout << evenly_disible(20) << endl;

	return 0;
	
}

int sum_of_multiples(int x1, int x2, int n) {
	// This function will find the sum of all multiples
	// of x1 and x2 below n
	int result = 0;
	for (int i = 1; i < n; ++i)
	{
		if (i % x1 == 0 || i % x2 == 0) {
			result += i;
		}
	}
	return result;
}

int fib(int n) {
	// returns the nth fibonacci term
	int result = 0;
	if (n < 3 && n > 0) {
		result = 1;
	} else if (n >= 3) {		
		result = fib(n-2) + fib(n-1);
	} else {
		result = 0;
	}
	return result;
}

int even_fib_sum(int n) {
	// This function returns the sum of  even
	// Fibonacci terms whos value do not exceed n.
	int result = 0;
	for (int i = 1; fib(i) < n; ++i)
	{
		if (fib(i) % 2 == 0)
		{
			result += fib(i);
		}
	}
	return result;
}

bool is_prime(int n) {
	/* This fuction returns true if n is prime,
	and false if n is composite. */
	int result = true;
	int root = ceil(sqrt(n)) + 1;
	if (n == 1) {
		result = false;
		return result;
	} else if (n == 2) {
		return result;
	} else if (n % 2 == 0) {
		result = false;
		return result;
	} else {
		for (int i = 3; i < root; i += 2) {
			// Test for loop:
			// cout << "i = " << i << ", remainder = " << (n % i) << endl;
			if (n % i == 0) {
				result = false;
				return result;
			}
		}
	}
	return result;
}

int largest_prime_factor(long long int n) {
	/* This function will return the 
	largest prime factor of n */
	int largest;
	int root = ceil(sqrt(n)) + 1;
	list<int> prime_factors;
	for (int i = 1; i < root; ++i) {
		if (n % i == 0 && is_prime(i)) {
			// largest = i;
			prime_factors.push_back(i);
			if (is_prime(n / i)) {
				prime_factors.push_back(n / i);
			}
		}
	}
	largest = *max_element(prime_factors.begin(), prime_factors.end());
	if (largest == 0) {
		largest = n;
	}
	return largest;

}

bool is_palindrome(int n) {
	/* This function will return true if
	n is a palindrome (12321) and false
	otherwise */
	bool result = true;
	string number = to_string(n);
	int midpoint = ceil(number.length() / 2);
	for (int i = 0; i < midpoint; ++i) {
		if (number[i] != number[number.length() - i - 1]) {
			result = false;
			return result;
		}
	}
	return result;

}

int largest_palindromic_product(int digits) {
	int lower_bound = pow(10,(digits - 1));
	int upper_bound = pow(10, digits);
	int largest = 1;
	for (int i = lower_bound; i < upper_bound; ++i) {
		for (int j = lower_bound; j < upper_bound; ++j) {
			int product = i * j;
			if (is_palindrome(product) && product > largest) {
				largest = product;
			}
		}
	}
	return largest;
}

int evenly_disible(int n) {
	/* this function will return the smallest number
	that is evenly disible by all numbers between 1 and n */

	int smallest = n;
	bool solved = false;


	while (solved == false) {
		int count = 0;
		// printf("smallest is %d, and count is %d\n", smallest, count);
		for (int i = 1; i <= n; ++i)
		{
			if (smallest % i == 0)
			{
				count += 1;
			}
		}

		if (count == n) {
			solved = true;
			
		}
		else
		{
			smallest += n;
		}
		

	}
	return smallest;
}

int gcd(int a, int b) {
	/* this function will return the greatest
	common divisor of a and b */
	int remainder = 0;
	while (b != 0) {
		remainder = b;
		b = a % b;
		a = remainder;
	}
	return a;
}

int lcm(int a, int b) {
	/* This function will return the least
	common multiple of a and b */
	return (a * b / (gcd(a,b)));
}

int problem5() {
	int result = 1;
	for (int i = 1; i < 21; i++)
	{
		result = lcm(i, result);
	}
	return result;
}

int sum_of_squares(int n) {
	/* this function will return the sum
	of the squares from 1,2,...n */
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		int square = pow(i,2);
		sum += square;
	}

	return sum;

}

int square_of_sum(int n) {
	/* this function will return the square
	of the sum of all integers (1,2,...,n). in other words:
	output = (1+2+...+n)^2 */
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += i;
	}
	return pow(sum, 2);
}

int problem6() {

	long int result = 0;
	long int sum = sum_of_squares(100);
	long int square = square_of_sum(100);
	result = abs(square - sum);
	return result;

}