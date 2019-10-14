#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct dot {
	double x;
	double y;
	int check;
	double weight;
	struct weight *w;
}dot;

struct weight {
	int index;
	double weight;
};

void main()
{
	int dots;
	dot* d;
	/*double weight = 0;*/
	double total = 0;
	double min;
	double weight = 0;
	scanf("%d", &dots);
	d = (dot*)malloc(sizeof(dot) * dots);
	for (int i = 0; i < dots; i++)
	{
		d[i].w = (struct weight*)malloc(sizeof(struct weight)*(dots-1));
	}

	for (int i = 0; i < dots; i++) // Read the vertexes
	{
		scanf("%lf %lf", &d[i].x, &d[i].y);
		d[i].check = 0;
	}
	
	for (int i = 0; i < dots; i++)
	{
		int h = 0;
		for (int j = 0; j < dots; j++)
		{
			if (i!=j)
			{
				d[i].w[h].index = j;
				d[i].w[h].weight = sqrt(pow(d[i].x - d[j].x, 2.0) + pow(d[i].y - d[j].y, 2.0));
				h++;
			}
		}
	}
	//use Prim algorithm.
	
	int check = 0;
	int k = 0;
	int minIndex = 0;
	d[0].weight = 0;
	d[0].check = 1;
	for(int j=0; j<dots; j++)
	{
		min = 100;
		for (int i = 0; i < dots - 1; i++)
		{
			if (d[d[k].w[i].index].check != 1)
			{
				if (d[k].w[i].weight < min)
				{
					min = d[k].w[i].weight;
					minIndex = d[k].w[i].index;
				}
			}
		}
		d[k].weight = min;
		k = minIndex;
		d[k].check = 1;
	} 

	for (int i = 0; i < dots; i++)
	{
		total += d[i].weight;
	}
	printf("\n%.2f", total-100);
	for (int i = 0;i < dots; i++)
	{
		free(d[i].w);
	}
	free(d);
}