#include<stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
	int coef;
	int degreeX;
	int degreeY;
	int degreeZ;
	char sign;
} Term;

void PrintTerms(Term* term) {
	printf("%c",term->sign);
	printf("%d", term->coef);
	printf("x^%d*z^%d*y^%d", term->degreeX, term->degreeZ, term->degreeY);
}
