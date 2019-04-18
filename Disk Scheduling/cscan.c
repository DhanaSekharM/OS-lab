#include <stdio.h>
#include <stdlib.h>


void sort(int locations[],int n)
{
	int min, i, j;

	for(i = 0; i < n; i++)
	{
		min = i;
		for(j = i; j < n; j++)
		{
			if(locations[j] < locations[min])
				min = j;
		}

		int temp = locations[i];
		locations[i] = locations[min];
		locations[min] = temp;
	}

	// for(i = 0; i < n; i++)
	// {
	// 	printf("%d ", locations[i]);
	// }
}

int getnear(int locations[], int head_location, int n, int flag)
{
	int m, i;
	if(!flag)
	{
		for(i = 0; i < n; i++)
			if(head_location < locations[i])
				return i;
	}
	else
	{
		for(i = 0; i < n; i++)
			if(head_location < locations[i])
				return i-1;
	}
}

void main()
{
	int range, head_location, i, n, seek_time = 0, previous_location, index;

	printf("Enter max disc size\n");
	scanf("%d", &range);

	printf("Enter number of locations\n");
	scanf("%d", &n);

	int locations[n], accessed[n], diff[n];

	printf("Enter disc locations\n");
	for(i = 0; i < n; i++)
	{
		scanf("%d", &locations[i]);
		accessed[i] = 0;
	}

	printf("Enter head_location\n");
	scanf("%d", &head_location);

	printf("Enter previous location\n");
	scanf("%d", &previous_location);

	printf("%d->", head_location);

	sort(locations, n);

	
	if(head_location > previous_location)
	{
		index = getnear(locations, head_location, n, 0);
		for(i = index; i < n; i++)
		{
			printf("%d->", locations[i]);
		}

		printf("%d->%d->", range - 1, 0);

		for(i = 0; i < index; i++)
		{
			printf("%d->", locations[i]);
		}

		seek_time = 2*(range - 1) - head_location +  locations[index - 1];
	}

	else
	{
		index = getnear(locations, head_location, n, 1);
		for(i = index; i >= 0; i--)
		{
			printf("%d->", locations[i]);
		}

		printf("%d->%d->", 0, 199);

		for(i = n-1; i > index; i--)
		{
			printf("%d->", locations[i]);
		}
		seek_time = head_location + 2*(range - 1) - locations[index + 1];
	}
	
	printf("\nseek_time: %d", seek_time);

}