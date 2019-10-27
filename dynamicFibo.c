#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int fib(int n)
{
	int* seq = (int*)malloc(sizeof(seq) * (n + 1)); // new int array
	seq[0] = 0;
	seq[1] = 1;

	for (int i = 2; i <= n; i++)
		seq[i] = seq[i - 1] + seq[i - 2];

	return seq[n];
}

void main()
{
	int n;
	printf("< Use recursive method (Naively computing) >\n\n");
	printf("How far are we going to get Fibonacci?\n");
	scanf("%d", &n);

	
	printf("\n-> %d (Until %d)\n", fib(n), n);
}