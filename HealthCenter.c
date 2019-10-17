#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct matrix {
	int index;
	struct row *row;
}matrix;

struct row {
	int index;
	int weight;
};

void main()
{
	int f; // Number of existing health centers.
	int I; // Number of intersections.
	int inter; // intersection number at which an existing health center is found.
	scanf("%d %d", &f, &I);
	scanf("%d", &inter);

	matrix* m;
	m = (matrix*)malloc(sizeof(matrix) * I);
	for (int i = 0; i < I; i++)
	{
		m[i].row = (struct row*)malloc(sizeof(struct row) * I);
	}

	

	for (int i = 0; i < I; i++)
	{
		free(m[i].row);
	}
	free(m);
}