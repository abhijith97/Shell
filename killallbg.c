#include "header.h"

void killallbg()
{
	int i;
	for(i=0;joblist[i].pid!=-1;i++)
	{
		printf("Killing %d\n",joblist[i].pid);
		kill(joblist[i].pid,SIGKILL);
		joblist[i].pid=-1;
	}
}