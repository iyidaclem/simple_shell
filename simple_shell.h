#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <string.h>

int show_prompt(char **lineptr, size_t *n);
int  exec_cmd(char *str, char **argv, char **env);
void mini_shell(char **argv, char **env);
#endif
