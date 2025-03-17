#include<stdio.h>

int Factorial_recursive(int n) {
	if (n == 1)
		return 1;
	else
		return n * Factorial_recursive(n - 1);
}

int Factorial_iter(int n) {
	int i, sum;

	sum = 1;
	for (i = 1;i <=n;i++) {
		sum =sum*i;
	}
	
	return sum;
}

/*int main() {
	int fact1, fact2;
	
	fact1 = Factorial_recursive(5);
	fact2 = Factorial_iter(5);

	printf("The value of recursive Factorial : %d\n", fact1);
	printf("The value of iteral Factorial : %d\n", fact2);
}*/