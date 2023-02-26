#ifdef _MSC_VER
#include <../include/limits.h>
#if _MSC_VER >= 1900
#include <../ucrt/stdlib.h>
#else
#include <../include/stdlib.h>
#endif
#ifndef PATH_MAX
#define PATH_MAX _MAX_PATH
#endif
#else
#include_next <limits.h>
#endif

#include "E:\Giorgio\Desktop\programming_exercises\Common_Utilities\ANSI_Colors\ANSI-color-codes.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define CMD_SIZE 30

const char logo[349] = GRN"        _                 _       ______             _ \n   __ _(_) __   _ _  __ _(_) __  |  ____| _ _ _  __ | |\n  / _' | |/  \\ | '_|/ _' | |/  \\ | |     | ' ' |/ _'  |\n | (_| | | () )| | | (_| | | () )| |     | | | | (_|  |\n  \\__, |_|\\__/ |_|  \\__, |_|\\__/ | |____ |_|_|_|\\__,__|\n |____/============|____/========|______|==============\n"reset;

void print_logo();
void help_cmd(char *cmd);

int main()
{

char cmd[CMD_SIZE];
char cwd[PATH_MAX];

print_logo();
getcwd(cwd, sizeof(cwd));
//if(strcmp(getcwd(cwd, sizeof(cwd)),NULL) != 0)
//    puts("Error: something went wrong in finding the working directory");

while (1)
 {
    printf(BLU">%s:"reset, cwd);
    scanf_s("%30s", cmd, CMD_SIZE);

    if (strcmp(cmd, "quit") == 0)
    {
         break;
    }
    else if (strcmp(cmd, "cd") == 0)
    {
         /*Do move dir command*/
    }
    else if (strcmp(cmd, "cp") == 0)
    {
        /*Do copy command*/
    }
    else if (strcmp(cmd, "dir") == 0)
    {
        /*Do dir command*/
    }
    else if (strcmp(cmd, "mkdir") == 0)
    {
        /*Do mkdir command*/
    }
    else if (strcmp(cmd, "del") == 0)
    {
        /*Do del command*/
    }
    else if (strstr(cmd, "help") != NULL)
    {
        help_cmd(cmd);
    }
    else
        printf_s("Unrecognized command '%s'\n", cmd);
 }

return 0;
}
//----------------------------------------------------------------------
void print_logo()
{
    puts(logo);
}
//----------------------------------------------------------------------
void help_cmd(char *cmd)
{
        puts("Further info on a specific command can be obtained by using 'help' cmdName.");
        puts("CD    TBA");
        puts("CP    TBA");
        puts("DIR   TBA");
        puts("MKDIR TBA");
        puts("DEL   TBA");
        puts("");
        puts("Further info on the utilities can be checked within the documentation.");
}
//----------------------------------------------------------------------