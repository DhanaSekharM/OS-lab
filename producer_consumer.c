#include <stdlib.h>
#include <stdio.h>
// #include <pthread.h>

// pthread_t tid, attr;
// int full, empty, mutex;
// int buffer[100];
int full = 0, empty = 5, mutex = 1, ch, i = 0;
int buffer[100];

int wait(int s)
{
	return s-1;
}

int signal(int s)
{
	return s+1;
}

void producer()
{
	mutex = wait(mutex);
	empty = wait(empty);

	if(empty >= 0 && mutex==0)
	{
		printf("Enter the item\n");
		scanf("%d", &buffer[full]);
		full = signal(full);
	}
	else
	{
		printf("Buffer is full\n");
		empty = signal(empty);
	}
	
	mutex = signal(mutex);
}

void consumer()
{
	mutex = wait(mutex);
	full = wait(full);

	if(full >= 0 && mutex == 0)
	{
		printf("Consumed %d\n", buffer[full]);
		empty = signal(empty);
	}
	else
	{
		printf("buffer is empty\n");
		full = signal(full);
	}

	mutex = signal(mutex);
}                                                                                              

void main()
{

	while(1)
	{
		printf("1.Producer, 2.Consumer, 3.exit\n");
		scanf("%d", &ch);
	
		switch(ch)
		{
			case 1:
				producer();
				break;
	
			case 2:
				consumer();
				break;
	
			default:
				exit(0);
		}
	}
	

}
