#include<stdio.h>

struct process
{
	int id;
	int arrival_time;
	int burst_time;
	int turnaround_time;
	int completion_time;
	int waiting_time;
	int remaining_time;
	int in_rq;
}arr[100], temp, rq[100], current_process;

int front = -1, rear = -1;

void sort(struct process arr[], int n)
{
	int i, j, min = 0;
	
	
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

void enqueue(struct process rq[], struct process p)
{
	rear++;
	if(front == -1)
	{
		front = 0;
		rear = 0;
	}

	rq[rear] = p;
}

struct process dequeue(struct process rq[])
{
	if(front > rear)
	{
		front = -1;
		rear = -1;
		current_process.id = -1;
		return current_process;
	}

	front++;

	return rq[front-1];

}

void print_rq(struct process rq[])
{
	int i;

	if(front == -1)
		return;

	for(i = front; i < rear; i++)
		printf("%d ", rq[i].id);

	printf("\n");
}

int search_for_id(struct process arr[], int id, int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		if(arr[i].id == id)
			return i;
	}
}

void main()
{
	int n, i = 0, j, time = 0, new_id, k = 0, index = 0, quantum;

	printf("Enter n\n");
	scanf("%d", &n);

	printf("Enter time quantum\n");
	scanf("%d", &quantum);

	printf("Enter arrival_time and burst_time\n");
	for(i = 0; i < n; i++)
	{
		arr[i].id = i;
		scanf("%d %d", &arr[i].arrival_time, &arr[i].burst_time);
		arr[i].remaining_time = arr[i].burst_time;
		arr[i].completion_time = 0;
		arr[i].in_rq = 0;
	}

	sort(arr, n);

	time = time + arr[0].arrival_time;

	enqueue(rq, arr[0]);
	arr[0].in_rq = 1;



	//print_rq(rq);

	while(1)
	{
		int flag = 1;
		current_process = dequeue(rq);

		index = search_for_id(arr, current_process.id, n);

		arr[index].in_rq = 0;

		//printf("%d\n", current_process.id);

		if(current_process.remaining_time > quantum)
		{
			arr[index].remaining_time = arr[index].remaining_time - quantum;
			time = time + quantum;

		}
		else
		{
			time = time + current_process.remaining_time;
			arr[index].waiting_time = time - arr[index].arrival_time - arr[index].burst_time;
			arr[index].completion_time = time;
			arr[index].turnaround_time = arr[index].completion_time - arr[index].arrival_time;
		}

		for(i = 0; i < n; i++)
		{
			if(arr[i].arrival_time <= time && arr[i].completion_time == 0 && i != index && !arr[i].in_rq)
			{
				enqueue(rq, arr[i]);
				arr[i].in_rq = 1;
			}
		}

		if(arr[index].completion_time == 0)
		{
			enqueue(rq, arr[index]);
			arr[index].in_rq = 1;
		}

		//print_rq(rq);

		for(i= 0; i < n; i++)
		{
			if(arr[i].completion_time == 0)
				flag = 0;
		}

		if(flag)
			break;

	}

	printf("id arrival_time burst_time waiting_time completion_time turnaround_time \n" );
	for(j = 0; j < n; j++)
		printf("%d %d %d %d %d %d\n", arr[j].id, arr[j].arrival_time, arr[j].burst_time, arr[j].waiting_time, arr[j].completion_time, arr[j].turnaround_time);

}