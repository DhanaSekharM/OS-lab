#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void main()
{
	
	char *filename = "abc2.txt";

	int file = creat(filename, S_IRWXU);
	close(file);

	file = open(filename, O_WRONLY);
	write(file, "hello", 5);

	printf("chmod_flag %d\n", chmod(filename, S_IRUSR | S_IWUSR)); 

	printf("chown_flag %d\n", chown(filename, 1000, 27));

	int pid = fork();

	//exit(0);


	if(pid)
	{
		//wait();
		printf("child pid:%d\n", pid);
		printf("uid euid:%d %d\n", getuid(), geteuid());
		printf("gid egid:%d %d\n", getgid(), getegid());
		printf("process ID of the parent %d\n", getppid());
	}
	else
	{
		//signal(SIGINT, handle_sigint);
		//kill(pid, SIGINT);
		alarm(5);
		printf("child process flag:%d\n", pid);
		printf("child process id %d\n", getpid());

		chdir("/home/cse/Documents");
		int file = creat("here.txt", S_IRWXU);
	}

	close(file); 	
}