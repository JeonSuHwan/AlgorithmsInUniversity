#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void Merge(int* A, int s, int m, int n)
{
	int i = s, j = m + 1, k = s;
	int* tmp = (int*)malloc(sizeof(int) * n); // new array
	while (i <= m && j <= n)
	{
		if (A[i] <= A[j])
			tmp[k++] = A[i++];
		else
			tmp[k++] = A[j++];
	}
	while (i <= m)
		tmp[k++] = A[i++];
	while (j <= n)
		tmp[k++] = A[j++];
	for (int a = s; a <= n; a++)
		A[a] = tmp[a];
}

void MergeSort(int* A, int s, int n)
{
	int m;
	if(s<n)
	{
		m = (s + n) / 2;
		MergeSort(A, s, m);
		MergeSort(A, m+1, n);
		Merge(A, s, m, n);
	}
}

void main()
{
	int num;
	printf("Input array number.\n");
	scanf("%d", &num);

	int* arr;
	arr = (int*)malloc(sizeof(int) * num);
	for (int i = 0; i < num; i++) // Read array
	{
		scanf("%d", &arr[i]);
	}
	printf("\n-------------------------------------\n");
	printf("Before\n");
	for (int i = 0; i < num; i++)
	{
		printf("%d\t", arr[i]);
	}
	
	printf("\n\nAfter\n");
	MergeSort(arr, 0, num); // merge sort
	for (int i = 0; i < num; i++)
	{
		printf("%d\t", arr[i]);
	}
}