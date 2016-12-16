#include "header.h"

void sendsig(char** tokens)
{
	int ret, i, jno=0, signo=0;
	for(i=0;i<strlen(tokens[1]);i++)
	{
		jno = jno*10 + (tokens[1][i]-48);
	}
	jno--;
	for(i=0;i<strlen(tokens[2]);i++)
	{
		signo = signo*10 + (tokens[2][i]-48);
	}
	pid_t pid = joblist[jno].pid;
	ret = kill(pid,signo);
}