
#ifndef FILE_FOO_SEEN
#define FILE_FOO_SEEN

char** arr;
char *home;

#include <syscall.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"


void display(char *home);
char** get_command();
char** seperate_command(char *input, int *num);
void piping(char **tokens,int*,char*);
void execute(char** tokens, int *pos, char* home,int,int);

int command_cd(char **tokens, char* home);
int command_echo(char **tokens);
int command_pwd();
int command_pinfo(char **tokens);
void listjobs();
void sendsig(char** tokens);
void movetofg(char **tokens);
void killallbg();


int system_command_background(char **tokens);
int system_command_foreground(char **tokens,int,int);
void HandleSignal(int sig, siginfo_t *si, void *context);

void ctrlC(int);
void ctrlZ(int);

typedef struct 
{
	pid_t pid;
	char pname[100];
}bgprocs;

pid_t shellpid;
bgprocs joblist[1000];
#endif