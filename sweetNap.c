#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct time1 {
	int h;
	int m;
};

struct time2 {
	int h;
	int m;
};

typedef struct time
{
	struct time1 time1; // start time
	struct time2 time2; // end time
	char work[255];
}time;

void main()
{
	int line;
	int max = 0; // Longest nap time.
	int maxIndex;
	printf("< Your schedule >\n");
	printf("Number?\n");
	scanf_s("%d", &line); // Check line condition (line<100)
	if (line >= 100)
	{
		printf("Error! Please try again.");
		exit(0);
	}
	time *t = (time*)malloc(sizeof(time)*line);

	printf("\nSpecific schedule\n");
	for (int i = 0; i < line; i++)
	{
		scanf("%d:%d %d:%d", &t[i].time1.h, &t[i].time1.m , &t[i].time2.h, &t[i].time2.m);
		gets(t[i].work);
		if (t[i].time1.h < 10 || t[i].time1.h>18 || t[i].time1.m<0 || t[i].time1.m>59 || t[i].time2.m < 0 
			|| t[i].time2.m > 59 || t[i].time2.h < 10 || t[i].time2.h>18) // Check time condition (10<hh<18), (00<mm<60)
		{
			printf("Error! Please try again.");
			break;
		}
	}

	for (int i = 0; i < line - 1; i++)
	{
		if (max < ((t[i + 1].time1.h * 60 + t[i + 1].time1.m) - (t[i].time2.h * 60 + t[i].time2.m)))
		{
			max = ((t[i + 1].time1.h) *60 + t[i + 1].time1.m) - ((t[i].time2.h) * 60 + t[i].time2.m);
			maxIndex = i;
		}
	}

	if (max < 60)
		printf("\nDay #1: the longest nap starts at %d:%d and will last for %d minutes",
			t[maxIndex].time2.h, t[maxIndex].time2.m, max);
	else
		printf("\nDay #1: the longest nap starts at %d:%d and will last for %d hours and %d minutes",
			t[maxIndex].time2.h, t[maxIndex].time2.m, max / 60, max % 60);
}