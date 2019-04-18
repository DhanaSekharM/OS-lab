#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main()
{
	char *filename = "abc.txt";

	int file = creat(filename, S_IRWXU);
	int cl = close(file);

	file = open(filename, O_WRONLY);    // int file2 = creat("abc3.txt", O_RDWR);
	int cnt = write(file, "qwerty\n" , 7);
	cl = close(file);

	file = open(filename, O_RDONLY);   // char *buf = (char *) calloc(100, sizeof(char));
	char buf[100];
	lseek(file, 2, SEEK_CUR);
	int cnt2 = read(file, buf, 2);
	buf[cnt2] = '\0';
 	cl = close(file);

	file = open(filename, O_APPEND|O_WRONLY);
	int dup_file = dup(file);
	write(file, "data from file \n", 14);
	write(dup_file, "\ndata from dup_file\n", 20);
	lseek(file, 0, SEEK_END);
	cl = close(file);

	char *new_filename = "abc_new.txt";
	link(filename, new_filename);

	int new_file = open(new_filename, O_WRONLY);
	lseek(new_file, 0, SEEK_END);
	write(new_file, "ql", 2);
	close(new_file);
	unlink(new_filename);

	printf("%d %d %d %d %d \n",access(filename, F_OK), access(filename, R_OK), access(filename, W_OK), access(filename, X_OK), access("a.out", W_OK));



	printf("%d %d %d %s\n", file, cnt, cnt2, buf);
}