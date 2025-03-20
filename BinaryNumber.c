#include<stdio.h>

void SeperateNumbers(int n) {
	int tmp;

	if (n / 10 <= 0)
		printf("%d ", n);
	else
	{
		tmp = n % 10;
		SeperateNumbers(n / 10);
		printf("%d ", tmp);
	}
}

int main() {
	SeperateNumbers(123);
}