#include <stdio.h>
struct process
{
	int arrival_time;
	int burst_time;
	int waiting_time;
	int completion_time;
	int turnaround_time;
	int id;
}p[100], temp;

void main()
{
	int i, min, n, j, time = 0;
	printf("number of processes\n");
	scanf("%d", &n);

	printf("arrival_time and burst_time of each_process\n");

	for(i = 0; i < n;i++)
	{
		scanf("%d %d", &(p[i].arrival_time), &(p[i].burst_time));
		p[i].id = i;
	}

	for(i = 0; i < n-1; i++)
	{
		min = i;
		for(j = i+1; j < n; j++)
		{
			if(p[j].arrival_time < p[min].arrival_time)
				min = j;
		}

		temp = p[min];
		p[min] = p[i];
		p[i] = temp;
	}

// 	for(i = 0; i < n; i++)
// 	{
// 		printf("%d %d %d \n", p[i].id, p[i].arrival_time, p[i].burst_time);
// 	}

	printf("id arrival_time burst_time waiting_time completion_time turnaround_time \n" );
	p[0].waiting_time = 0;
	p[0].completion_time = p[0].burst_time + p[0].arrival_time;
	time = p[0].burst_time + p[0].arrival_time;
	i = 0;
	printf("%d \t %d    \t %d \t\t %d \t\t %d \t\t %d\n", p[i].id, p[i].arrival_time, p[i].burst_time, p[i].waiting_time, p[i].completion_time, p[i].turnaround_time );
	i = 1;
	while(i < n)
	{
		if(time >= p[i].arrival_time)
		{
			p[i].waiting_time = time - p[i].arrival_time;
			time = time + p[i].burst_time;
			p[i].completion_time = time;
			p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
			printf("%d \t %d    \t %d \t\t %d \t\t %d \t\t %d\n", p[i].id, p[i].arrival_time, p[i].burst_time, p[i].waiting_time, p[i].completion_time, p[i].turnaround_time );
			i++;
		}
		else
		{
			printf("Idle at %d\n", time);
			time++;
		}
	}

	printf("id arrival_time burst_time waiting_time completion_time turnaround_time \n" );
	// for(i = 0; i < n; i++)
	// {
	// 	p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
	// 	printf("%d \t %d    \t %d \t\t %d \t\t %d \t\t %d\n", p[i].id, p[i].arrival_time, p[i].burst_time, p[i].waiting_time, p[i].completion_time, p[i].turnaround_time );
	// }

}