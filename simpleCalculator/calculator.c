#define _CRT_SECURE_NOWARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	double r1=0, r2=0, r3=0;
	char op;

	printf("Enter first number \n");
	scanf(" %lf", &r1);

	printf("Enter operator \n");
	scanf(" %c", &op);
	printf("Enter second number\n");
	scanf(" %lf", &r2);

	switch(op) {
		case '+': r3 = r1 + r2; break;
		case '-': r3 = r1 - r2; break;
		case '*': r3 = r1 * r2; break;
		case '/': 
			if ( fabs(r2) < 1.0E-10 ) {
				printf("Divide by zero!\n");
				scanf(" %c", &op);
				return 1;
			}
			r3 = r1 / r2;
			break;
		default:
			printf("Error!\n");
			scanf(" %c", &op);
			return 2;
	}
	printf("%f %c %f = %f\n", r1, op, r2, r3);
	scanf(" %c", &op);
	return 0;
}
