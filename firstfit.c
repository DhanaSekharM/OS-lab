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
		for(j = 0; j < no_of_blocks; j++)
		{
			if(p[i].memory_requested <= mem[j].size && !mem[j].allocated)
			{
				p[i].allocated = 1;
				p[i].block_allocated = j;
				mem[j].allocated = 1;
				mem[j].internal_fragmentation = mem[j].size - p[i].memory_requested;
				p[i].external_fragmentation = 0;
				break;
			}
			// else
			// {
			// 	p[i].external_fragmentation
			// }
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
			printf("%d %d %d %s external_fragmentation %d\n", i, p[i].memory_requested, -1, "NO", p[i].external_fragmentation);
		}
		else
		{
			printf("%d %d %d %s\n", i, p[i].memory_requested, p[i].block_allocated, "YES");
		}
	}

	printf("internal_fragmentation\n");

	for(i = 0; i < no_of_blocks; i++)
		if(mem[i].allocated && mem[i].internal_fragmentation != 0)
			printf("%d %d\n", i, mem[i].internal_fragmentation);




}