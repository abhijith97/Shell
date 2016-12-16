#include "header.h"

int command_pinfo(char **tokens)
{
	char input[1000];
	strcpy(input, "/proc/");
	if(tokens[1] != NULL)
		strcat(input, tokens[1]);
	else
	{
		char arr[10];
		sprintf(arr, "%d" , getpid());
		strcat(input, arr);
	}
	int flag=0;
	char input1[1000];
	strcpy(input1, input);
	strcat(input,"/status");

	char a[2];
	int inp_fb1=open(input, O_RDONLY );

	while(read(inp_fb1, a, 1)>0)
	{
		write(1, a, 1);
		flag=1;
	}
	close(inp_fb1);


	if(flag == 1)
		write(1, "Executable File : " , strlen("Executable File : ")) ;
	strcat(input1,"/cmdline");
	int inp_fb2=open(input1, O_RDONLY );

	while(read(inp_fb2, a, 1)>0)
	{
		write(1, a, 1);
		flag=1;
	}
	close(inp_fb2);
	printf("\n");
	if(flag==0)
	{
		printf("Process Status : N/A \n");
		printf("Memory : N/A \n");
		printf("Executable File : N/A \n");
	}
}


int command_cd(char **tokens, char *home)
{
	char output[200];
	// printf("%s\n", home );
	if(tokens[1][0]=='~')
	{

		int k=0;
		for(int i=0 ; i<strlen(home); i++)
		{
			output[k++]=home[i];
		}
		for(int i=1; i<strlen(tokens[1]); i++)
		{
			output[k++]=tokens[1][i];
		}
		output[k]=0;

	}
	else
		strcpy(output, tokens[1]);

	if(chdir(output) < 0)
		perror("Error");
}


int command_pwd()
{
	char *buf_pwd;
	buf_pwd=(char *)malloc(100*sizeof(char));
	if(getcwd(buf_pwd, 100)==NULL)
		perror("Error");
	printf("%s\n", buf_pwd );	
}


int command_echo(char **tokens)
{
	int i=1;
	while(tokens[i]!=NULL)
	{
		printf("%s ", tokens[i]);
		i++;
	}
	printf("\n");
}