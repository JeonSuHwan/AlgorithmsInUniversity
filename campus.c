#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct coordinate {
	int x;
	int y;
} coordinate;

void main()
{
	int test, t = 0;
	int c;
	float length = 0; // total length
	coordinate *cor;

	printf("Test case?\n");
	scanf("%d", &test);
	printf("\n\n");
	
	while (t != test)
	{
		printf("Coordinate?\n"); // read dimentions	
		printf("%d", &c);
		cor = (coordinate*)malloc(sizeof(coordinate) * c);
		for (int i = 0; i < c; i++)
		{
			scanf("%d %d", &cor[i].x, &cor[i].y);
		}

		int min; // mininum index
		for (int i = 0; i < c; i++) //Fine a point with the minimum y-coordinate
		{
			if (i == 0)
				min = 0;
			else
			{
				if (min > cor[i].y)
					min = i;
			}
		}
		t++;
	}
}