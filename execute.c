#include "header.h"

void execute(char **tokens , int *pos, char* home,int cno,int noOfCommands)
{
	int i, j, flag, fd, pos1 = -1, pos2 = -1, posf, test;

	int in = dup(0);
	int out = dup(1);


	for(i=0;tokens[i]!=NULL;i++)
	{
		if(tokens[i][0] == '<')
		{
			fd=open(tokens[i+1], O_RDONLY);
			test = dup2(fd,0);
			if(test == -1)
			{
				perror("dup error");
				return ;
			}

			close(fd);
			pos1 = i;
		}
		else if(tokens[i][0] == '>')
		{
			if(tokens[i][1] == '>')
				fd=open(tokens[i+1],O_CREAT | O_WRONLY |O_APPEND, 0644);
			
			else
				fd=open(tokens[i+1],O_CREAT | O_WRONLY | O_TRUNC, 0644);
			test = dup2(fd,1);
			if(test == -1)
			{
				perror("dup error");
				return ;
			}

			close(fd);
			pos2 = i;
		}
	}

	if(pos1 != -1 && pos2 != -1)
	{
		posf = (pos1 < pos2) ? pos1 : pos2;
		tokens[posf] = NULL;
	}
	else if(pos1 != -1)
		tokens[pos1]=NULL;
	
	else if(pos2 != -1)
		tokens[pos2] = NULL;

	*pos-=1;
	if(strcmp(tokens[0], "cd")==0)
		command_cd(tokens, home);
	else if(strcmp(tokens[0], "pwd")==0)
		command_pwd(tokens);
	else if(strcmp(tokens[0], "pinfo")==0)
		command_pinfo(tokens);
	else if(strcmp(tokens[0], "echo")==0)
		command_echo(tokens);
	else if(strcmp(tokens[0],"listjobs") == 0) 
		listjobs();

	else if(strcmp(tokens[0],"sendsig") == 0) 
		sendsig(tokens);

	else if(strcmp(tokens[0],"killallbg") == 0) 
	{
		killallbg();		
	}
	else if(strcmp(tokens[0],"fg") == 0) 
	{
		movetofg(tokens);		
	}
	else if(strcmp(tokens[0],"quit") == 0) 
		exit(0);
	else
	{
			// char *argv[] = { "ls", "-l", 0 };
			// execvp(tokens[0], tokens);
			// printf("%c\n",tokens[pos][strlen(tokens[pos])-1] );
		// printf("%c\n",tokens[*pos][0] );
		if(tokens[*pos][strlen(tokens[*pos])-1] == '&')
		{		
					// printf("Hi" );

			tokens[*pos][strlen(tokens[*pos])-1]=0;
			system_command_background(tokens);
		}
		else if(tokens[*pos][0] == '&')
			system_command_background(tokens);

		else
			system_command_foreground(tokens,cno,noOfCommands);
		dup2(in,0);
		dup2(out,1);

	}	

}

