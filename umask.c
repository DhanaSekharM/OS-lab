#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
 void main()
 {
 	umask(022);

 	int file = open("a.txt", O_CREAT, 0666);
 	printf("%d\n", file);
 	close(file);
 }