#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void insertsionSort(int* A, int n)
{
	int h = 1;
	for (int j = 1; j < n; j++)
	{
		int key = A[j];
		int i = j - 1;
		while (i >= 0 && A[i] > key)
		{
			A[i + 1] = A[i];
			i = i - 1;
		}
		A[i + 1] = key;
		
		for (int k = 0; k < n; k++)
		{
			printf("%d\t", A[k]);
		}
		printf("<- try %d\n", h);
		h++;
	}
}

void main()
{
	int num; // number of index
	int* arr;

	printf("Number of index?\n");
	scanf("%d", &num);
	arr = (int*)malloc(sizeof(int) * num); // asign memory to arr
	
	printf("Input the numbers.\n");
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &arr[i]);
	}
	printf("\n");
	// Insertsion Sort
	insertsionSort(arr, num);
	printf("\n");
	for (int i = 0; i < num; i++)
	{
		printf("%d\t", arr[i]);
	}
}