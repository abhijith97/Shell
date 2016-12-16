#include "header.h"

int system_command_background(char **tokens)
{
	int pid = fork();
	if(pid == 0)
	{
		
		//CHILD PROCESS
		setpgid(0, 0);

		if(execvp(tokens[0], tokens)<0)
			fprintf(stderr, "Command not found!\n" );
		// kill(0, 0);
		_exit(0);

		// printf("HEYYY\n");

	}
	else if(pid > 0)
	{
		int i;
		bgprocs temp;
		printf("%d\n",pid );
		strcpy(arr[pid], tokens[0]);
		// printf("%d %s\n", pid, arr[pid]);
		int status;
		temp.pid = pid;
		strcpy(temp.pname, tokens[0]);
		for(i=0;joblist[i].pid!=-1;i++)
		{
		}
		joblist[i]=temp;
		joblist[i+1].pid=-1;
		// waitpid(-1, &status, WNOHANG | WUNTRACED);
		return 1;
	}
	else
	{
		
		return 1;
	}
}

int system_command_foreground(char **tokens, int cno, int noOfCommands)
{
	int fd1[2], fd2[2];
	if(noOfCommands != 1)
	{
		if(cno%2==0)
		{
			pipe(fd2);	
		}
		else
		{
			pipe(fd1);
		}
	}
	int pid = fork();
	if(pid == 0)
	{
		//CHILD PROCESS
		if(noOfCommands != 1)
		{
			if(cno == 0)
			{

				dup2(fd2[1],1);
			}
			else if(cno == noOfCommands - 1)
			{

				if(cno % 2 == 0)
				{	
					dup2(fd1[0],0);	
				}
				else
				{		
					dup2(fd2[0],0);
				}
			}
			else
			{

				if(cno % 2 == 0)
				{
					dup2(fd2[1],1);	
					dup2(fd1[0],0);		
				}
				else
				{
					dup2(fd1[1],1);
					dup2(fd2[0],0);
				}
			}
		}
		if(execvp(tokens[0], tokens)<0)
			fprintf(stderr, "Command not found!\n" );

	}
	else if(pid>0)
	{
		int status;
		if(noOfCommands != 1)
		{
			if(cno == 0)
			{
				close(fd2[1]);
			}
			else if(cno == noOfCommands - 1)
			{
				if(cno%2==0)
				{
					close(fd1[0]);
				}
				else
				{
					close(fd2[0]);
				}
			}
			else
			{
				if(cno%2==0)
				{
					close(fd2[1]);
					close(fd1[0]);
				}
				else
				{
					close(fd1[1]);
					close(fd2[0]);
				}
			}
		}
		waitpid(pid, &status, 0);
		return 1;
	/*	if(status == 0)
			printf("Process with pid %d exited normally\n", pid);
		else
			printf("Process with pid %d exited with error\n", pid);*/
	}
	else
	{
		if(noOfCommands != 1)
		{
			if (cno != noOfCommands - 1)
			{
				if (cno % 2 != 0)
				{
					close(fd1[1]); 
				}
				else
				{
					close(fd2[1]); 
				} 
			}
		} 
		perror("Error");
	}

}
