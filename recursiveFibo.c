#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int fib(int n)
{
	if (n == 0 || n == 1)
	{
		return n;
	}
	else
	{
		return (fib(n - 1) + fib(n - 2));
	}
}

void main()
{
	int n;
	printf("< Use recursive method (Naively computing) >\n\n");
	printf("How far are we going to get Fibonacci?\n");
	scanf("%d", &n);

	int fibonacci;
	fibonacci = fib(n);

	printf("\n-> %d (Until %d)", fibonacci, n);
}