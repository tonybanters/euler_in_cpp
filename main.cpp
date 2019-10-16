// Going thru project euler exercises
// in c++ 

#include <iostream>
#include <string>

using namespace std;

int soln1;
int soln2;

int sum_of_multiples(int x1, int x2, int n);
int even_fib_sum(int n);
int fib(int n);

int main(int argc, char const *argv[])
{
	soln1 = sum_of_multiples(3,5,1000);
	soln2 = even_fib_sum(4000000);
	cout << "The sum of all multiples of 3 and 5 below 1000 is " << soln1 << ".\n";
	cout << "The sum of even Fibonacci numbers below 4,000,000 is " << soln2 << ".\n";
	// printf("The sum of all multiples of 3 and 5 below 1000 is %d.\n", soln1);

	return 0;
}

int sum_of_multiples(int x1, int x2, int n) {
	// This function will find the sum of all multiples
	// of x1 and x2 below n
	int result = 0;
	for (int i = 1; i < n; ++i)
	{
		if (i % x1 == 0 || i % x2 == 0)
		{
			result += i;
		}
	}
	return result;
}

int fib(int n) {
	// returns the nth fibonacci term
	int result;
	if (n < 3 && n > 0) {
		result = 1;
	} else if (n >= 3) {		
		result = fib(n-2) + fib(n-1);
	} else if (n <= 0) {
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
