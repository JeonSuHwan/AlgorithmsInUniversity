#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct dot {
	double x;
	double y;
	double weight;
}dot;

void main()
{
	int dots;
	dot* d;
	scanf("%d", &dots);
	d = (dot*)malloc(sizeof(dot) * dots);

	for (int i = 0; i < dots; i++) // Read the vertexes
	{
		scanf("%f %f", &d[i].x, &d[i].y);
	}
	
	/*for (int i = 0; i < dots-1 i++)
	{
		int j = 1;
		for (j; j < dots; j++)
		{

		}
		j++;
	}*/
	//use Prim algorithm.
	free(d);
}