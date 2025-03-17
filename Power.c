#include<stdio.h>

int PowerFunc_recur(int x, int n) {
	if (n == 1)
		return x;
	else
		return x* PowerFunc_recur(x, n - 1);
}

int PowerFunc_iter(int x, int n) {
	int result, i;
	result = 1;

	for (i = 0;i < n;i++)
		result = result * x;

	return result;
}

int main() {
	int result1, result2;
	
	result1 = PowerFunc_recur(2, 10);
	result2 = PowerFunc_iter(2, 10);

	printf("2^10 = %d(with recursive func)\n", result1);
	printf("2^10 = %d(with iterative func)\n", result2);
}