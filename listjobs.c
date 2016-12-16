#include "header.h"

void listjobs()
{
	int i;
	for(i=0;joblist[i].pid!=-1;i++)
	{
		printf("[%d] %s [%d]\n", (i+1),joblist[i].pname,joblist[i].pid);
	}
}