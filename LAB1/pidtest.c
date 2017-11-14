#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv){
	pid_t pid, wpid;
	int status = 0;

	if((pid = fork()) == 0){
		printf("I am the child: %u\n", getpid());
		for(int i = 0; i < 1000000; i++){
		}
		exit(1);
	} else { 
		while((wpid = wait(&status)) > 0);
		printf("I am the parent: %u and my child is: %u now go to bed.\n", getpid(), pid);
		exit(1);
	}
}
