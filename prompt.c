#include "header.h"
char* get_curdir(char *temp, char *home);
char output[100];
void display(char *home)
{

	char *buf_username, *buf_hostname, *buf_curdir;

	//GET USERNAME
	buf_username=(char*)malloc(100*sizeof(char));
	getlogin_r(buf_username, 100);

	//GET HOSTNAME
	buf_hostname=(char*)malloc(100*sizeof(char));
	gethostname(buf_hostname, 100);

	//GET CURRENT DIRECTORY
	buf_curdir=(char*)malloc(100*sizeof(char));
	getcwd(buf_curdir, 100);




	printf(ANSI_COLOR_RED  "%s" ANSI_COLOR_RESET "@%s:"ANSI_COLOR_YELLOW  "%s" ANSI_COLOR_RESET "$ ",
	  buf_username, buf_hostname, get_curdir(buf_curdir, home));


}

char* get_curdir(char *temp, char *home)
{
	int pos=0;
	while(pos<strlen(temp) && pos<strlen(home))
	{
		if(temp[pos]!=home[pos])
		{

			break;
		}
		pos++;
	}
	if(pos<strlen(home))
	{
		return temp;
	}
	else
	{
		output[0]='~';
		int k=1;
		for(int i=pos; i<strlen(temp); i++)
		{
			output[k++]=temp[i];
		}
		output[k]=0;
		return output;
	}
}