#include<stdio.h>

void Hannoi_tower(int n, char from, char tmp, char to) {
	if (n == 1) {
		printf("���� 1�� %c���� %c�� �ű��\n", from, to);
	}
	else {
		Hannoi_tower(n - 1, from, to, tmp);
		printf("���� %d�� %c���� %c�� �ű��.\n",n, from, to);
		Hannoi_tower(n - 1, tmp, from, to);
	}
}

/*int main() {
	int iNo;

	printf("Enter number");
	scanf_s("%d", &iNo);
	Hannoi_tower(iNo,'a', 'b', 'c');
}*/