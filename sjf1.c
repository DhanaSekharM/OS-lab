#include<stdio.h>

struct process
{
	int pid;
	int at;
	int bt;
	int wt;
	int ct;
	int tat;
	int check;
};

struct process p[10],temp;


void main()
{
	int i,j,n,time,total_time = 0,min_at = 100000;
	printf("Enter the number of processes\n");
	scanf("%d",&n);
	printf("Enter the arrival time and burst time for the processes\n");
	for (int i = 0; i < n; i++)
	{
		printf("Process with pid %d\n", i);
		p[i].pid = i;
		printf("Arrival time = ");
		scanf("%d",&p[i].at);
		printf("Burst time = ");
		scanf("%d",&p[i].bt);
		printf("\n");
		p[i].check = 0;
		total_time += p[i].bt;
		if(p[i].at < min_at)
		{
			min_at = p[i].at;
		}
	}
	printf("\n\n");
	time = min_at;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n-1-i; j++)
		{
			if(p[j].bt > p[j+1].bt)
			{
				temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;
			}
		}
	}
	for (time = min_at; time < total_time; time++)
	{
		for (i = 0; i < n; ++i)
		{
			if(p[i].at <= time && p[i].check == 0)
			{
				p[i].ct = time + p[i].bt;
				p[i].wt = p[i].ct - p[i].bt - p[i].at;
				p[i].tat = p[i].ct - p[i].at;
				p[i].check = 1;
				time += (p[i].bt -1 );
				break;
			}
			else
			{
				printf("idle at %d\n", time);
			}
		}		
	}
	for (i = 0; i < n; i++)
	{
		printf("For process with pid %d\n", p[i].pid);
		printf("The Arrival Time is %d\n", p[i].at);
		printf("The Burst Time is %d\n", p[i].bt);
		printf("The Completion Time is %d\n", p[i].ct);
		printf("The Waiting Time is %d\n", p[i].wt);
		printf("The Turn Arround Time is %d\n", p[i].tat);
		printf("\n");
	}
}