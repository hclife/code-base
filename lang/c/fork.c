#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
    int count=1;
    int child=fork();
    if (child<0)
	perror("fork error:");
    else if (child>0) // The child PID is returned in parent's thread
	printf("This is father, his count=%d(%p), his pid=%d\n",
		count,&count,getpid());
    else // fork() return 0 in child process because it can use getpid()
	printf("This is child,  his count=%d(%p), his pid=%d\n",
		++count,&count,getpid());

    return EXIT_SUCCESS;
}
