#include "header.h"

void HandleSignal(int sig, siginfo_t *si, void *context)
{
	int status, pid,i,pos;
	switch(sig)	
	{
		case SIGINT:
		fprintf(stderr, "\nControl-C was pressed\n");

		
		break;
		case SIGCHLD:
		pid = waitpid(-1, NULL, WNOHANG);
		// printf("%d\n", pid );
		if(pid>0)
		{
			// printf("%d\n", pid );
			kill(pid , SIGTERM);
		/*fprintf(stderr, "\nSIGCHLD. mypid = %d, mypgid = %d\n",
			getpid(), getpgid(getpid()));*/
		  
		
		/*if(si->si_code == CLD_EXITED || si->si_code == CLD_KILLED )
		{
			printf("Done");
		}*/
		
			// printf("%lld\n", si->si_pid );
			if(arr[pid][0]!=0)
				fprintf(stderr, "\n%s with pid %d exited!\n" ,arr[pid], pid);
			arr[pid][0]=0;
			for(i=0;joblist[i].pid!=-1;i++)
			{
				if(joblist[i].pid == pid)
					pos = i;
			}
			for(i=pos;joblist[i+1].pid!=-1;i++)
			{
				joblist[i]=joblist[i+1];
			}
			joblist[i].pid = -1;
		}
		// si->si_signo=0;
		break;
	 }
}

void ctrlC(int signo)
{
	if(signo == SIGINT)
	{
		if(getpid() != shellpid)
			kill(getpid(),9);
		else
		{
			printf("\n");
		}
	}
	// printf("\n");
}

void ctrlZ(int signo)
{
	if(signo == SIGTSTP)
	{
		printf("Detected Ctrl+Z\n");
	}

}