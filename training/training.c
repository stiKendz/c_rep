#include <stdio.h>

int voidSign()
{
	int a = 123;
	int *ip = &a;

	void *vp;
	vp=ip;

	printf("Value: %d\n", *((int *)vp));

	return 0;
}

int voidSignTwo()
{
	int a = 123;
	int *ip = &a;

	void *vp = ip;

	printf("vp: %p\n", vp);
	printf("ip: %p\n", (void*)ip);

	return 0;
}

int signAdress()
{
	int a = 12;
	int *pa = &a;
	printf("adress of pointer = %p\n", (void*)&pa); //адрес указателя 
	printf("adress in pointer = %p\n", (void*)pa); //адрес который хранится в указателе
	printf("value on pointer = %d\n", *pa); //значение по адресу в указателе

	return 0;
}

int signComparison()
{
	int a = 10;
	int b = 20;

	int *pa = &a;
	int *pb = &b;

	if(pa>pb)
		printf("pa (%p) bolshe chem pb (%p) \n", (void*)pa, (void*)pb);
	else
		printf("pb (%p) bolshe ili ravno pa (%p) \n", (void*)pb, (void*)pa);


	return 0;
}

int types()
{
	char c = 'N';
	char *pc = &c;
	int *pd = (int*)pc;

	printf("pc=%d\n", (void*)pc);
	printf("pd=%d\n", (void*)pd);

	return 0;
}

int checkWork()
{
	int a = 12;
	int *pa = &a;
	printf("Exercise 1.\n Adress of a = %p\t Value of a %d\n", (void*)pa, *pa);

	int b = 21;
	int *ba = &b;
	printf("b before transformation %d\n", *ba);

	*ba = 25;
	printf("b after transformation %d\n", *ba);

	return 0;
}

int main(void)
{
    int a = 12;
    int b = 6;
     
    int *pa = &a;
    int *pb = &b;
     
    printf("Variable a: address=%p \t value=%d \n", (void*)pa, *pa);
    printf("Variable b: address=%p \t value=%d \n", (void*)pb, *pb);
     
    pa = pb;    // теперь указатель pa хранит адрес переменной b
    printf("Variable b: address=%p \t value=%d \n", (void*)pa, *pa);

	voidSign();

	voidSignTwo();

	signAdress();     

	signComparison();

	types();

	printf("Remember what i learn (checkWork-function from code)\n");
	checkWork();

    return 0;
}
