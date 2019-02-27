#include<stdio.h>

struct process
{
	int id;
	int arrival_time;
	int burst_time;
	int turnaround_time;
	int completion_time;
	int waiting_time;
}arr[100], temp, p[100];

void sort(struct process arr[], int n, int ch)
{
	int i, j, min = 0;
	if(ch)
	{
		for(i = 0; i < n-1; i++)
		{
			min = i;
			for(j = i+1; j < n; j++)
			{
				if(arr[min].arrival_time > arr[j].arrival_time)
					min = j;
			}

			//swap
			temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}
	else
	{
		for(i = 0; i < n-1; i++)
		{
			min = i;
			for(j = i+1; j < n; j++)
			{
				if(arr[min].burst_time > arr[j].burst_time)
					min = j;
			}

			//swap
			temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}

	// printf("sort\n");

	// for(i = 0; i < n ; i++)
	// 	printf("%d %d %d\n", arr[i].id, arr[i].arrival_time, arr[i].burst_time);

	// printf("end\n");
}

void main()
{
	int n, i = 0, j, time = 0, new_id, k = 0, l;

	printf("Enter n\n");
	scanf("%d", &n);

	printf("Enter arrival_time and burst_time\n");
	for(i = 0; i < n; i++)
	{
		arr[i].id = i;
		scanf("%d %d", &arr[i].arrival_time, &arr[i].burst_time);
		arr[i].completion_time = 0;
	}

	sort(arr, n, 0);

	// printf("%d", arr[0].completion_time);
	printf("id arrival_time burst_time waiting_time completion_time turnaround_time \n" );

	while(1)
	{
		k = 0;
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

				printf("%d \t %d    \t %d \t\t %d \t\t %d \t\t %d\n", arr[j].id, arr[j].arrival_time, arr[j].burst_time, arr[j].waiting_time, arr[j].completion_time, arr[j].turnaround_time);
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

	float twaiting_time = 0, tcompletion_time = 0, tturnaround_time = 0;

	for(i = 0; i < n; i++)
	{
		twaiting_time += arr[i].waiting_time;
		tcompletion_time += arr[i].completion_time;
		tturnaround_time += arr[i].turnaround_time;
	}

	printf("Avg waiting_time %f\n Avg completion_time %f\n Avg turnaround_time %f\n", twaiting_time/n, tcompletion_time/n, tturnaround_time/n); 
}