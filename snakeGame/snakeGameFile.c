﻿#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include<time.h>
#include<ctype.h>
#include <time.h>
#include <windows.h>
#include <process.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

int length;
int bend_no;
int len;
char key;
void record();
void load();
int life;
void Delay(long double);
void Move();
void Food();
int Score();
void Print();
void gotoxy(int x, int y);
void GoToXY(int x,int y);
void Bend();
void Boarder();
void Down();
void Left();
void Up();
void Right();
void ExitGame();
int Scoreonly();

struct coordinate
{
	int x;
	int y;
	int direction;
}

typeof struct coordinate coordinate;

coordinate head, bend[500],food,body[30];

int main()
{

	char key;

	Print();
	system("cls");
	load();

	length = 5;
	head.x = 25;
	head.y = 20;

	head.direction = RIGHT;

	Boarder();
	Food();

	life = 3;
	bend[0]=head;

	Move();

	return 0;
}

void Move()
{
	int a,i;

	do 
	{
		Food();
		fflush(stdin);

		len = 0;

		for(i=0; i<30; i++)
			{
				body[i].x=0;
				body[i].y=0;

				if(i==length)
					break;
			}

		Delay(length);
		Boarder();

		if(head.direction==RIGHT)
			Right();
		else if (head.direction==LEFT)
			Left();
		else if (head.direction==DOWN)
			Down();
		else if (head.direction==UP)
			Up();

		ExitGame();
	}

	while(!kbhit());
	a=getch();

	if(a==27) {
		system("cls");
		exit(0);
	}

	key=getch();

	if((key==RIGHT&&head.direction!=LEFT&&head.direction!=RIGHT)||(key==LEFT&&head.direction!=RIGHT&&head.direction!=LEFT)||(key==UP&&head.direction!=DOWN&&head.direction!=UP)||(key==DOWN&&head.direction!=UP&&head.direction!=DOWN)){
		bend_no++;
		bend[bend_no]=head;
		head.direction=key;

		if(key==UP)
			head.y--;
		if(key==DOWN)
			head.y++;
		if(key==RIGHT)
			head.x++;
		if(key==LEFT)
			head.x--;

		Move();
	}
	else if(key=27){
		system("cls");
		exit(0);
	}
	else {
		printf("\a");
		Move();
	}
}

void gotoxy(int x,int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void GotoXY(int x, int y){
	HANDLE a;
	COORD b;
	fflush(stdout);
	b.X = x;
	b.Y = y;
	a = GetStdhandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(a,b);
}

void load() {
	int row,col,r,c,q;
	gotoxy(36,14);
	printf("loading...");
	gotoxy(30,15);

	for(r=1; r<=20; r++) {
		for(q=0; q<=100000000; q++);
		printf("%c",177);
	}
	getch();
}

void Down() {
	int i;
	for(i=0; i<=(head.y-bend[bend_no].y)&&len<length; i++) {
		GotoXY(head.x,head.y-i);
		{
			if(len==0)
				printf("v");
			else 
				printf("*");
		}
		body[len].x=head.x;
		body[len].y=head.y-i;
		len++;
	}
	Bend();
	if(!kbhit())
		head.y++;
}

void Delay(long double k) {
	Score();
	long double i;
	for(i=0; i<=(10000000); i++);
}

void ExitGame(){
	int i,check=0;
	for(i=4; i<length; i++) {
		if(body[0].x==body[i].x&&body[0].y==body[i].y) {
			check++;
		}
		if(i=length||check!=0)
			break;
	}

	if(head.x<=10||head.x>=70||head.y<=10||head.y>=30||check!=0){
		life--;
		if(life>=0){
			head.x=25;
			head.y=20;
			bend_no=0;
			head.direction=RIGTH;
			Move();
		}
		else {
			system("cls");
			printf("All lives completed\nBetter Luck Next Time!!!\nPress any key to quit the game\n");
			record();
			exit(0);
		}
	}
}

void Food(){
	if(head.x=food.x&&head.y==food.y){
		length++;
		time_t a;
		a=time(0);
		srand(a);
		food.x=rand()%70;
		if(food.x<=10)
			food.x+=11;
		food.y=rand()%30;
		if(food.y<=10)
			food.y+=11;
	}
	else if(food.x==0){
		food.x=rand()%70;
		if(food.x<=10)
			food.x+=11;
		food.y=rand()%30;
		if(food.y<=10)
			food.y+=11;
	}
}

void Left() {
	int i;
	for(i=0; i<(bend[bend_no].x-head.x)&&len<length; i++){
		GotoXY((head.x+i),head.y);
		{
			if(len==0)
				printf("<");
			else
				printf("*");	
		}
		body[len].x=head.x+i;
		body[len].y=head.y;
		len++;
	}
	Bend();
	if(!kbhit())
		head.x--;
}
void Right(){
	int i;
}




















