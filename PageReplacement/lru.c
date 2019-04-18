#include <stdio.h>

int time = 0, faults = 0, hits = 0;


void print(int frame_size, int frames[])
{
	int k;
	for(k = 0; k < frame_size; k++)
	{
		if(frames[k] != -1)
			printf("%d -", frames[k]);
		else
			printf("_ -");
	}
}

int search(int no_of_pages, int pages[], int times[])
{
	int min = 0, i;
	for(i = 0; i < no_of_pages; i++)
	{
		if(times[i] < times[min])
			min = i;
	}
	return min;
}


void main()
{
	int frame_size, no_of_pages, i, j, k;

	printf("Enter frame_size\n");
	scanf("%d", &frame_size);
	int frames[frame_size];
	int times[frame_size];

	for(i = 0; i < frame_size; i++)
	{
		frames[i] = -1;
		times[i] = 999999999;
	}

	printf("Enter no_of_pages\n");
	scanf("%d", &no_of_pages);
	int pages[no_of_pages];

	printf("Enter the pages\n");
	for(i = 0; i < no_of_pages; i++)
	{
		scanf("%d", &pages[i]);
	}

	for(i = 0; i < no_of_pages; i++)
	{
		int hit_flag = 0;
		for(j = 0; j < frame_size; j++)
		{
			if(frames[j] == pages[i])
			{
				time++;
				times[j] = time;
				hit_flag = 1;
				print(frame_size, frames);
				// for(k = 0; k < no_of_pages; k++)
				// {
				// 	if(frames[k] != -1)
				// 		printf("%d -", frames[k]);
				// 	else
				// 		printf("_ -");
				// }
				printf("Hit\n");
				hits++;
				break;
			}
		}
		if(!hit_flag)
		{
			for(k = 0; k < frame_size; k++)
			{
				if(frames[k] == -1)
				{
					time++;
					frames[k] = pages[i];
					print(frame_size, frames);
					printf("Fault\n");
					faults++;
					hit_flag = 1;
					times[k] = time;
					break;
				}
			}
			if(!hit_flag)
			{
				time++;
				int index = search(frame_size, pages, times);
				frames[index] = pages[i];
				print(frame_size, frames);
				printf("Fault\n");
				faults++;
				times[index] = time;
			}
		}
	}

	printf("Hits %d\n Faults %d\n", hits, faults);

}