#include "header.h"

void movetofg(char **tokens)
{
	int i,jno=0,status;
	for(i=0;i<strlen(tokens[1]);i++)
	{
		jno = jno*10 + (tokens[1][i]-48);
	}
	jno--;
	for(i=0;joblist[i].pid!=-1;i++)
	{
		if(i==jno)
			break;
	}
	if(i==jno)
	{
		kill(joblist[jno].pid, SIGCONT);
		waitpid(joblist[jno].pid,&status,0);
	}

	else
		fprintf(stderr,"Job %d doesn not exist", jno+1);
}