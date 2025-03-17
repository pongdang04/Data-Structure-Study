#include<stdio.h>

int Fibonacci_recursive(int n) {
	int i;
	
	if (n == 1 || n == 2) {
		return 1;
	}
	else
		return Fibonacci_recursive(n - 1) + Fibonacci_recursive(n - 2);
}

int Fibbonacci_iter(int n) {
	int prev1 = 1, prev2 = 1, present;

	for(n)
	
}

/*int main() {
	int Fib;

	Fib = Fibonacci(5);
	printf("%d", Fib);
}*/