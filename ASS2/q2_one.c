#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>

FILE *fp;

void split(char *line, char **argv)
{
     if(*line == '\0')
     {
         argv[0] = "\0";
         return;
     }

     while (*line != '\0')
     {
          while (*line == ' ' || *line == '\t')
               *line++ = '\0';

          *argv++ = line;

          while(*line != '\0' && *line != ' ' && *line != '\t')
               line++;
     }
     *argv = '\0';
}

void execute(char **argv)
{
    pid_t pid = fork();
    int status;
    char ch;
    if(!strcmp(argv[0],"cd"))
            chdir("/home/inro");
    if(!pid)
    {
        if(!strcmp(argv[0],"exit"))
            exit(0);
        else if(execvp(argv[0], argv) < 0 && strcmp(argv[0],"hist")!=0 && strcmp(argv[0],"cd")!=0)
        {
               printf("command not found!!!\n");
               exit(1);
        }
     }
     else if(pid>0)
     {
        if(!strcmp(argv[0],"hist"))
        {
            fp = fopen("history.txt","r");
            ch = fgetc(fp);
            while(ch != EOF)
            {
                printf("%c",ch);
                ch = fgetc(fp);
            }
        }
         while(wait(&status) != pid);
     }
     else
         printf("fork is not working!!!\n");

}


int main()
{
    char *buff;
    fp = fopen("history.txt","w");
    fclose(fp);
    while(1)
    {

        char cwd[100];
        char *argv[100];
        char shell[1000];
	    char *s;

        getcwd(cwd, sizeof(cwd));
	
        strcpy(shell,"ubuntu@sobhan:");
        strcat(shell,cwd);
        strcat(shell,"$ ");

        buff = readline(shell); //read a line from terminal
        fp = fopen("history.txt","a");
        fprintf(fp, "%s\n", buff);
        fclose(fp);
        if(strlen(buff)>0)
            add_history(buff);

        split(buff,argv);

        if(!strcmp(argv[0],"exit"))
            exit(0);
        else if(!strcmp(argv[0],"\0"))
            continue;
        else
           execute(argv);
    }
    return 0;
}






