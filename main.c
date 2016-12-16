#include "header.h"

void SIGINT_handler();
void SIGCHLD_handler();

void SIGINT_handler()
{
	signal(SIGINT, SIG_IGN);
	printf("Handled\n");


}
void SIGCHLD_handler()
{
	printf("Process exited!\n");

}
int main()
{
	joblist[0].pid=-1;
	shellpid=getpid();

	arr=(char**)malloc(40000*sizeof(char*));
	int i;
	for(i=0 ; i<40000; i++)
	{
		arr[i]=(char*)malloc(20*sizeof(char));
	}
	home=(char *)malloc(100*sizeof(char));
	getcwd(home, 100);


	/*SIGNAL HANDLERS*/
	struct sigaction sVal;
	sVal.sa_flags = SA_RESTART;
	sVal.sa_sigaction = &HandleSignal;

	sigfillset(&sVal.sa_mask);

	if(sigaction(SIGINT, &sVal, NULL)<0)
		perror("Error");
	if(sigaction(SIGCHLD, &sVal, NULL)<0)
		perror("Error");


	// printf("Helo");
	signal(SIGINT, ctrlC);
	signal(SIGTSTP, ctrlZ);

	// signal(SIGCHLD, SIGCHLD_handler);



	char **tokens;
	do
	{
		display(home);

		tokens=get_command();
		if(tokens == NULL)
		{
			perror("Error");
			continue;

		}
		int pos=0;
		while(tokens[pos]!=NULL)
		{	
			int num=0;
			piping(seperate_command(tokens[pos++] , &num) , &num, home);
		}

	}while(1);
	return 0;
}





