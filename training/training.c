#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

// NULL pointer
/* НУЛЕВЫЕ указатели обычно используются для обозначения отсутствия какого-либо адреса. 
Это позволяет нам проверить, указывает ли указатель на какую-либо допустимую ячейку памяти, проверив, равно ли оно NULL.*/
int nullPtr()
{
	int *ptr = NULL;

	return 0;
}

// Void pointer
/* Указатели void в C являются указателями типа void. 
Это означает, что они не имеют никакого связанного типа данных. 
Их также называют универсальными указателями, поскольку они могут указывать на любой тип и могут быть преобразованы в любой тип.*/
int voidPtr()
{
	void *ptr;

	return 0;
}

// Wild pointers
/* Подстановочные указатели - это указатели, которые еще не были инициализированы каким-либо образом. 
Эти типы C-указателей могут вызывать проблемы в наших программах и в конечном итоге приводить к их аварийному завершению. 
Если значения обновляются с использованием подстановочных указателей, это может привести к прерыванию работы или повреждению данных.
*/
int wildPtr()
{
	int *ptr;

	return 0;
}

// Dangling pointers
/*Указатель, указывающий на область памяти, которая была удалена (или освобождена), называется висячим указателем. 
Такая ситуация может привести к неожиданному поведению программы, а также послужить источником ошибок в программах на языке Си.*/
int danglingPtr()
{
	int* ptr = (int*)malloc(sizeof(int));
	
	free(ptr);
	printf("Memory freed \n");

	ptr = NULL; //Указатель ptr явно устанавливается в NULL, чтобы избежать неопределенного поведения.

	return 0;
}

// Массивы и указатели
int pointersArrays()
{
	int numbers[] = {10, 20, 30, 40, 50};
	int *ptr = numbers;

	for(int i = 0; i < 5; i++){
		printf("Element %d --- %d\n", i, *ptr);
		ptr++;
	}

	return 0;
}

// malloc() для выделения памяти для массива во время выполнения.
int allocatingMemory(){
	int *numbers;
	int size;

	printf("How many numbers do you want to store?\n");
	scanf("%d", &size);

	numbers=(int*)malloc(size * sizeof(int));

	if(numbers == NULL){
		printf("Memory allocation failed");
		return 1;
	}

	for(int i = 0; i < size; i++){
		printf("Enter number %d: ", i+1);
		scanf("%d", &numbers[i]);
	}

	printf("You entered ");
	for(int i = 0; i < size; i++){
		printf("%d", numbers[i]);
	}

	free(numbers);
	return 0;
}

/*
Здесь мы передаем адреса x и y в нашу функцию подкачки. 
Это позволяет функции напрямую манипулировать исходными переменными, а не только их копиями. 
Это мощный метод, который позволяет экономить память и выполнять более сложные операции.
*/
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b=temp;
}
int referenceArguments(){
	int x = 10, y = 20;

	printf("Before swap: x = %d, y = %d\n", x, y);
	swap(&x, &y);
	printf("After swap: x = %d, y = %d\n", x, y);

	return 0;
}

/*
В этом примере мы передаем наш массив функции printArray в качестве указателя. 
Это эффективно, потому что мы не копируем весь массив целиком, 
а просто передаем ссылку на его местоположение в памяти.
*/
void printArray(int *arr, int size){
	for(int i = 0; i < size; i++){
		printf("%d", arr[i]);
	}
	printf("\n");
}
int arrayToFunction(){
	int numbers[] = {1, 2, 3, 4, 5};
	int size = sizeof(numbers) / sizeof(numbers[0]);

	printf("The array contains: ");
	printArray(numbers, size);

	return 0;
}

/*
Функция getMinMax находит минимальное и максимальное значения в массиве. 
С помощью указателей можно обновлять оба этих значения непосредственно в вызывающей функции.
*/
void getMinMax(int *arr, int size, int *min, int *max){
	*min = *max = arr[0];
	for(int i = 1; i < size; i++){
		if(arr[i] < *min) *min = arr[i];
		if(arr[i] > *max) *max = arr[i];
	}
}
int multipleValues(){
	int numbers[] = {5, 2, 9, 1, 7, 6, 3};
	int size = sizeof(numbers) / sizeof(numbers[0]);
	int min, max;

	getMinMax(numbers, size, &min, &max);

	printf("Minimum --- %d \t Maximum --- %d \n", min, max);

	return 0;
}

// Константа и указатель
int main(void)
{
	const int cx = 10;
	*(int*) &cx = 20;	
	printf("cx: %d\n", cx);

	danglingPtr();

	printf("Arrays and pointers \n");
	pointersArrays();

	printf("Allocating Memory \n");
	allocatingMemory();

	printf("Passing Arguments as Reference \n");
	referenceArguments();

	printf("Passing Array to Function \n");
	arrayToFunction();

	printf("Returning Multiple values From Function \n");
	multipleValues();

	return 0;
}
