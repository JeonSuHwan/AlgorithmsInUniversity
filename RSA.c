#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int fai(int p, int q)
{
	int f;
	f = (p - 1) * (q - 1);
	return f;
}

int Euclid(int a, int b)
{
	if (b == 0)
		return a;
	else
		return Euclid(b, a % b);
}

int explanation(int a, int e, int n)
{
	int c = 0;
	int d = 1;

	int b[20] = { 0, };
	int p = 0;
	while (1)
	{
		b[p] = e % 2;
		e = e / 2;
		p++;
		if (e == 0)
			break;
	}

	for (int i = p-1; i >=0; i--)
	{
		c = 2 * c;
		d = (d * d) % n;
		if (b[i] == 1)
		{
			c = c + 1;
			d = (d * a) % n;
		}
	}
	return d;
}

void main()
{
	int M; //M < n
	int p, q;
	int n, f;
	int e = 1000, d; // keys

	printf("Input encrypt message\n");
	scanf("%d", &M);

	printf("\nInput two number\n");
	scanf("%d %d", &p, &q);
	n = p * q;
	f = fai(p, q);

	for (int i = 2; i < f - 1; i++)
	{
		if (Euclid(i, f) == 1)
		{
			if (i % 2 == 1)
			{
				if (e > i)
					e = i;
			}
		}
	}
	int i = 1;
	do
	{
		if ((i * e) % f == 1)
		{
			d = i;
			break;
		}
		i++;
	} while (i < f);

	printf("\n< Encryption >\nM : %d\ne : %d\nn : %d\n\n", M, e, n);
	printf("-> %d\n\n", explanation(M, e, n));


	int C = explanation(M, e, n);
	printf("< Decryption >\nC : %d\nd : %d\n\n", C, d);
	printf("-> %d\n\n", explanation(C, d, n));
}