#include <stdio.h>

typedef struct time
{
	int time1;
	int time2;
}time;

int checkLine(int l)
{
	if (l >= 100)
		return 0;
}

int checkTime(int time1, int time2)
{

	if (time1 > 10 && time1 < 18)
	{
		if (time2 > 0 && time2 < 60)
		{
			return 0;
		}
	}
	else
		return 1;
}

void input(time t[], int i)
{
	char doing[255];
	scanf_s("%d:%d %d:%d %s", &t[i].time1, &t[i].time1, &t[i + 1].time1 , t[i + 1].time2, &doing);

	checkTime(t[i].time1, t[i].time2);
	checkTime(t[i + 1].time1, t[i + 1].time2);
}

void main()
{
	int line;
	time t[100];
	scanf_s("%d", &line);
	
	if (checkLine(line) == 0)
	{
		for (int i = 0; i < line; i++)
		{
			input(t, i);
		}
	}
	else
		printf("The line have to be less than 100");

	printf("Day #d: the longest nap starts at hh:mm and will last for [H hours and]M minutes");
}