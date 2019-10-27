#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void LCS(char* x, char* y, int i, int j)
{
	int** z;
	z = (int**)malloc(sizeof(int) * i);
	for (int k = 0; k < i; k++)
		*z[k] = (int*)malloc(sizeof(int) * j);
	z[0][0] = 0;

	for (int k = 0; k < i; k++)
	{
		for (int h = 0; h < j; h++)
		{
			if (x[i] == y[j])
			{
				z[i][j] = z[i - 1][j - 1] + 1;
			}
			else
			{
				if (z[i][j-1] < z[i-1][j])
				{
					z[i][j] = z[i - 1][j];
				}
				else
				{
					z[i][j] = z[i][j - 1];
				}
			}
		}
	}

	for (int k = 0; k < i; k++)
	{
		for (int h = 0; h < j; h++)
		{
			if (z[i][j] == 1)
				printf("%c", x[i]);
		}
	}

	for (int k = 0; k < i; k++)
		free(z[i]);
	free(z);
}

void main()
{
	int n, m;
	char *arr1, *arr2;

	printf("How long is string 1?\n");
	scanf("%d", &n);
	printf("\nHow long is string 2?\n");
	scanf("%d", &m);
	arr1 = (char*)malloc(sizeof(char) * n);
	arr2 = (char*)malloc(sizeof(char) * m);

	printf("\nInput the string 1\n");
	for (int i = 0; i < n; i++)
		scanf("%c", &arr1[i]);
	printf("\nInput the string 2\n");
	for (int i = 0; i < m; i++)
		scanf("%c", &arr2[i]);

	LCS(arr1, arr2, n, m);

	free(arr1);
	free(arr2);
}