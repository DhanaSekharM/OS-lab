#include <stdio.h>
struct process
{
	int memory_requested;
	int allocated;
	int external_fragmentation;
	int block_allocated;
}p[100];

struct memory_block
{
	int size;
	int internal_fragmentation;
	int allocated;
}mem[100];


void main()
{
	int no_of_processes, no_of_blocks, i, j, k;

	printf("Enter number of memory blocks\n");
	scanf("%d", &no_of_blocks);

	printf("Enter size of each block\n");
	for(i = 0; i < no_of_blocks; i++)
	{
		scanf("%d", &mem[i].size);
		mem[i].internal_fragmentation = 0;
		mem[i].allocated = 0;
	}

	printf("Enter number of processes\n");
	scanf("%d", &no_of_processes);

	printf("Enter memory request of each process\n");
	for(i = 0; i < no_of_processes; i++)
	{
		scanf("%d", &p[i].memory_requested);
		mem[i].allocated = 0;
		mem[i].internal_fragmentation = -1;
	}


	for(i = 0; i < no_of_processes; i++)
	{
		int best = -1, index = -1;
		for(j = 0; j < no_of_blocks; j++)
		{
			if(p[i].memory_requested <= mem[j].size && !mem[j].allocated)
			{
				if(best == -1)
				{
					best = mem[j].size;
					index = j;
				}
				else
				{
					if(mem[j].size < best)
					{
						best = mem[j].size;
						index = j;
					}
				}
			}
		}

		if(index != -1)
		{
			p[i].allocated = 1;
			p[i].block_allocated = index;
			mem[index].allocated = 1;
			mem[index].internal_fragmentation = mem[index].size - p[i].memory_requested;
			p[i].external_fragmentation = 0;
		}

		if(!p[i].allocated)
			for(k = 0; k < no_of_blocks; k++)
				if(!mem[k].allocated)
					p[i].external_fragmentation += mem[k].size;
	}

	printf("proces_id memory_requested block_allocated allocated?\n");

	for(i = 0;i < no_of_processes; i++)
	{
		if(!p[i].allocated)
		{
			printf("%d %d %d %s external_fragmentation %d \n", i, p[i].memory_requested, -1, "NO", p[i].external_fragmentation);
		}
		else
		{
			printf("%d %d %d %s \n", i, p[i].memory_requested, p[i].block_allocated, "YES");
		}
	}

	printf("internal_fragmentation\n");

	for(i = 0; i < no_of_blocks; i++)
		if(mem[i].allocated && mem[i].internal_fragmentation != 0)
			printf("%d %d\n", i, mem[i].internal_fragmentation);

}