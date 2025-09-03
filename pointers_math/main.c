#include <stdio.h>

/*
Когда к указателю добавляется целочисленное значение, это значение сначала умножается на размер типа данных, а затем 
добавляется к указателю.
Когда из указателя вычитается целое значение, это значение сначала умножается на размер типа данных, а затем 
вычитается из указателя аналогично сложению.
*/
int intAdditionSubstraction()
{
	int N = 4;
	int *ptr1, *ptr2;

	ptr1 = &N;
	ptr2 = &N;

	printf("Pointer ptr2 before addition: %p\n", ptr2);

	ptr2 = ptr2 + 3;
	printf("Pointer ptr2 after addition: %p\n", ptr2);


	printf("Pointer ptr2 before substranction: %p\n", ptr2);

	ptr2 = ptr2 - 3;
	printf("Pointer ptr2 after substraction: %p\n", ptr2);

	return 0;
}

/*
Указатели могут быть выведены с помощью %p, поскольку большинство компьютеров хранят значение адреса в шестнадцатеричной форме,
используя %p, что дает значение в этой форме. 
Но для простоты и понимания мы также можем использовать %u, чтобы получить значение в виде int без знака.
*/
int main(void)
{
	int a = 22;
	int *p = &a;
	printf("p = %u\n", p);

	p++;
	printf("p++ = %u\n", p);

	p--;
	printf("p-- = %u\n", p);


	float b = 22.22;
	float *q = &b;
	printf("q = %u\n", q);

	q++;
	printf("q++ = %u\n", q);

	q--;
	printf("q-- = %u\n", q);


	char c = 'a';
	char *r = &c;
	printf("r = %u\n", r);

	r++;
	printf("r++ = %u\n", r);

	r--;
	printf("r-- = %u\n", r);

	
	printf("____________________\n");
	intAdditionSubstraction();

	return 0;
}
