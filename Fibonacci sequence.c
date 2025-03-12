#include<stdio.h>

int Fibonacci(int n) {
	int i;
	
	if (n == 1 || n == 2) {
		return 1;
	}
	else
		return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main() {
	int Fib;

	Fib = Fibonacci(5);
	printf("%d", Fib);
}