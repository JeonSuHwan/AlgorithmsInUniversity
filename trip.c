#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct city {
	char name[10];
	int time;
	int check;
}city;

void main()
{
	city* c;
	int num; // number of test case
	int n1; // number of part1
	int n2; // number of part2
	printf("How many cities?\n");
	scanf("%d", &n1);
	for (int i = 0; i < n1; i++)
	{
		gets(c[i].name);
	}
	printf("Trains?");
	scanf("%d", &n2);
	for (int i = 0; i < n2; i++)
	{

	}
}