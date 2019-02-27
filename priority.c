#include <stdio.h>

struct process
{
	int id;
	int arrival_time;
	int burst_time;
	int turnaround_time;
	int completion_time;
	int waiting_time;
	int priority;
	int remaining_time;
}arr[100], temp;

void sort(struct process arr[], int n)
{
	int i, j, min = 0;
	
	for(i = 0; i < n-1; i++)
	{
		min = i;
		for(j = i+1; j < n; j++)
		{
			if(arr[min].priority < arr[j].priority)
			{
				min = j;
			}
		}
		//swap
		temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
	
}


void main()
{
	int i, j, time = 0, n;

	printf("Enter n\n");
	scanf("%d", &n);

	printf("Enter arrival_time burst_time priority\n");
	for(i = 0; i < n; i++)
	{
		arr[i].id = i;
		scanf("%d %d %d", &arr[i].arrival_time, &arr[i].burst_time, &arr[i].priority);
		arr[i].remaining_time = arr[i].burst_time;
		arr[i].completion_time = 0;
	}

	sort(arr, n);

	printf("id arrival_time burst_time waiting_time completion_time turnaround_time priority\n" );

	while(1)
	{
		//k = 0;
		int flag1 = 1, flag2 = 1;
			
		for(j = 0; j < n; j++)
		{
			if(time >= arr[j].arrival_time && arr[j].completion_time == 0)
			{
				arr[j].waiting_time = time - arr[j].arrival_time;
				arr[j].completion_time = arr[j].burst_time + time;
				arr[j].turnaround_time = arr[j].completion_time - arr[j].arrival_time;
				time = time + arr[j].burst_time;
				flag1 = 0;

				printf("%d \t %d    \t %d \t\t %d \t\t %d \t\t %d \t %d\n", arr[j].id, arr[j].arrival_time, arr[j].burst_time, arr[j].waiting_time, arr[j].completion_time, arr[j].turnaround_time, arr[j].priority);
				break;
				
			}
		}

		for(j = 0; j < n; j++)
		{
			if(arr[j].completion_time == 0)
				flag2 = 0;
		}

		if(flag2)
			break;

		if(flag1)
		{
			printf("Idle at %d\n", time);
			time++;
		}

	}
}