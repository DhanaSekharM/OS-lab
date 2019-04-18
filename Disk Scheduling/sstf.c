#include <stdio.h>
#include <stdlib.h>


int searchformin(int locations[], int accessed[], int n, int head_location)
{
	int min = 999999, i, min_index = 0;

	for( i = 0; i < n; i++)
		if(abs(head_location - locations[i]) < min && !accessed[i])
				min = abs(head_location - locations[i]), min_index = i;

	accessed[min_index] = 1;

	return min_index;

}


void main()
{
	int range, head_location, i, n, seek_time = 0;

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

	printf("%d->", head_location);

	for(i = 0; i < n; i++)
	{
		int index = searchformin(locations, accessed, n, head_location);
		printf("%d->", locations[index]);
		seek_time += abs(head_location - locations[index]);
		head_location = locations[index];

	}

	printf("\nseek_time: %d", seek_time);

}