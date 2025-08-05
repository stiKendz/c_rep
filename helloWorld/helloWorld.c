#include <stdio.h>

/*int main() {
		printf("Hello World\n");
		return 0;
	}

int main() {
		int number = 10;
		printf("The number is %d\n", number);
		return 0;	
	}


int main() {
		int number;
		int numberTwo = 12;
		printf("Enter a number: ");
		scanf("%d", &number);
		printf("You entered: %d and number two (not entered) %d\n", number, numberTwo);
		return 0;
	}


int main() {
		int number, numberTwo;
		printf("Print first number: ");
		scanf("%d", &number);
		printf("Print second number: ");
		scanf("%d", &numberTwo);
		int sum = number + numberTwo;
		printf("Summa vvedennix chisel ravna = %d\n. Pobeda! \n", sum);
	}
*/

int main() {
		int number;
		printf("Print number: ");
		scanf("%d", &number);
		if ( number % 2 == 0) {
			printf("The number even.\n");
		} else {
			printf("The number id odd.\n");
		}
		return 0;
	}
