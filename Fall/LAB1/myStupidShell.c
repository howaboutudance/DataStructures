#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int makeargv(const char *s, const char *delimiters, char ***argvp);

int main(int argc, char *argv[]){
	char delim[] = " \t";
	int i;
	char **myargv;
	int numtokens;

	pid_t pid, wpid;
	int status = 0;

	char *newenviron[] = {NULL};

	if(argc !=2){
		fprintf(stderr, "Usage: %s string\n", argv[0]);
		return 1;
	}

	if((numtokens = makeargv(argv[1], delim, &myargv)) == -1) {
		fprintf(stderr, "Failed to construct an argument array for %s\n", argv[1]);
		return 1;
	}
	
	if((pid = fork()) == 0){
		execve(myargv[0], myargv, newenviron);
		perror("execve");
		exit(EXIT_FAILURE);
	} else {
		printf("MEOW!!!!! \n");
		while((wpid = wait(&status)) > 0);
		exit(1);
	}
}
