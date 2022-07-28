#include <stdio.h>
#include <unistd.h>
int main(){
	int pfd[2];
	int status;
	char message[10] = "BVRITH";
	char readmes[10];
	status = pipe(pfd);
	if(status == -1){
		printf("Unable to create pipe\n");
	}
	int pid = fork();
	if(pid==0){
		printf("Child Process-Reading from pipe, Message is '%s'\n",message);
		read(pfd[0],readmes,sizeof(readmes));
	}
	else{
		printf("Parent Process-Writing '%s' to pipe\n",message);
		write(pfd[1],message,sizeof(message));
	}
	return 0;
}
