#include <stdio.h>
#include <stddef.h>

/*int voidSign()
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
*/


/*В случае с указателем увеличение на единицу будет означать увеличение адреса, 
который хранится в указателе, на размер типа указателя.
Фактически увеличение на единицу означает, что мы хотим перейти к следующему объекту в памяти, 
который находится за текущим и на который указывает указатель. 
А уменьшение на единицу означает переход назад к предыдущему объекту в памяти.
*/
int incrementDecrement()
{
	int a = 12;

	int *ptr = &a;
	printf("adress = %p\t value=%d\n", (void*)ptr, *ptr);
	ptr++;
	printf("adress = %p\t value=%d\n", (void*)ptr, *ptr);
	ptr--;
	printf("adress = %p\t value=%d\n", (void*)ptr, *ptr);


	printf("double and char\n");
	double b = 10.6;
	double *pb = &b;

	printf("Pointer pd: adress=%p\n", (void*)pb);
	pb++;
	printf("Pointer pd: adress=%p\n", (void*)pb);


	char c = 'N';
	char *pc = &c;
	printf("Pointer pc: adress=%p\n", (void*)pc);
	pc++;
	printf("Pointer pc: adress=%p\n", (void*)pc);



	printf("Adresses\n");
	double d = 10.6;
	double *pd = &d;
	printf("Pointer pd: adress=%p\n", (void*)pd);
	pd = pd + 2;
	printf("Pointer pd: adress=%p\n", (void*)pd);



	char cc = 'N';
    char *pcc = &cc;
    printf("Pointer pc: address=%p \n", (void*)pc);
    pcc = pc - 3;
    printf("Pointer pc: address=%p \n", (void*)pc);



	printf("4 bytes difference\n");
	int e = 10;
	int f = 22;
	int *pe = &e;
	int *pf = &f;
	ptrdiff_t g = pe - pf;

	printf("pe=%p\n",(void*)pe);
	printf("pf=%p\n",(void*)pf);
	printf("g=%lld\n",g);

	return 0;
}

int arrayDiff()
{
	/* Расстояние между указателями представляет тип ptrdif_t - на 64-разрядной архитектуре 
	этот тип является псевдонимом для базового типа long long и занимает 8 байт. 
	*/
	int arr[64];
	int* ptr1 = &arr[10];
	int* ptr2 = &arr[40];
	ptrdiff_t dist = ptr2 - ptr1;

	printf("dist=%lld\n", dist);

	return 0;

}

int signSpecific()
{
	int a = 10;
	int *pa = &a;
	int b = *pa + 20; // операция со значением, на который указывает указатель
	pa++; // операция с самим указателем (прейти к другому уровню в памяти?)

	printf("b = %d\n", b); //30


	int x = 10;
	int *xp = &x;
	printf("xp: address=%p \t value=%d \n", (void*)xp, *xp);
	int y = *xp++;     // инкремент адреса указателя
	int yt =(*xp)++;

	printf("y: value=%d \n", y);
	printf("yt: value=%d \n", yt);

	printf("xp: address=%p \t value=%d \n", (void*)xp, *xp);

	return 0;
}

int forCheck()
{
	int a = 10;
	int *pa = &a;
	printf("pa: address=%p \t value=%d \n", (void*)pa, *pa);
	int b = *pa++;      // инкремент адреса указателя
	     
	printf("b: value=%d \n", b);
	printf("pa: address=%p \t value=%d \n", (void*)pa, *pa);

	return 0;
}


int main(void)
{
    /*int a = 12;
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
	*/

	incrementDecrement();

	printf("Distance\n");
	arrayDiff();

	printf("Vazhno\n");
	signSpecific();

	printf("for check\n");
	forCheck();


    return 0;
}
