#include "header.h"

char** get_command()
{
	char *input;
	input=(char *)malloc(100*sizeof(char));
	size_t nbytes = 100;

	if(getline(&input, &nbytes, stdin)==-1)
	{
		// perror("Error");
		// return NULL;
		printf("\n");
		exit(0);
	}


	char *token;
	token=(char *)malloc(100*sizeof(char));
	// char delim[2]=";\0";



	char **tokens;
	tokens=(char**)malloc(100*sizeof(char*));
	int i;
	for(i=0 ; i<100 ; i++)
	{
		tokens[i]=(char*)malloc(100*sizeof(char));
	}	
	int pos=0;
	//GET FIRST TOKEN
	token = strtok(input, ";\n");
	tokens[pos++]=token;
	//GET ALL TOKENS
	while(token!=NULL)
	{
		// printf("%s\n", token );
		token = strtok(NULL, ";\n");
		tokens[pos++]=token;
	}
	tokens[pos]=NULL	;

	return tokens;
	// puts(input);
}

char** seperate_command(char *input, int* num)
{
	
	char *token;
	token=(char *)malloc(100*sizeof(char));
	


	char **tokens;
	tokens=(char**)malloc(100*sizeof(char*));
	int i;
	for(i=0 ; i<100 ; i++)
	{
		tokens[i]=(char*)malloc(100*sizeof(char));
	}	
	int pos=0;
	//GET FIRST TOKEN
	token = strtok(input," ;\n" );
	tokens[pos++]=token;
	//GET ALL TOKENS
	while(token!=NULL)
	{
		// printf("%s\n", token );
		token = strtok(NULL, " ;\n");
		tokens[pos++]=token;
	}
	tokens[pos]=NULL;
	*num=pos-1;
	// printf("%d\n",*num );
	return tokens;
	// puts(input);
}

