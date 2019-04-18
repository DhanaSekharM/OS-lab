#include <unistd.h>

void main()
{
	
	char *args[]={"./syscall",NULL};
	execl("./syscall", args);
}