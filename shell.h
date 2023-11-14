#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER 1024
#define TRUE 1
#define PROMPT "$ "
/* error strings */
#define ERR_MALLOC "Unable to malloc space\n"
#define ERR_FORK "Unable to fork and create child process\n"
#define ERR_PATH "No such file or directory\n"
extern char **environ;

/**
 * struct list_s - linked list of variables
 * @value: value
 * @next: pointer to next node
 *
 * Description: generic linked list struct for variables.
**/
typedef struct list_s
{
	char *value;
	struct list_s *next;
} list_s;

/**
 * struct built_s - linked list of builtins
 * @name: name of builtin
 * @p: pointer to function
 *
 * Description: struct for builtin functions.
**/
typedef struct built_s
{
	char *name;
	int (*p)(void);
} built_s;

void prompt(int fd, struct stat buf);
char *get_line(FILE *fp);
char **tokenizer(char *str);
char *which_path(char *command, char *fullpath, char *path);
int child(char *fullpath, char **tokens);
void errors(int error);

/* utility functions */
void _puts(char *str);
int str_len(char *s);
int str_cmp(char *name, char *variable, unsigned int length);
int str_ncmp(char *name, char *variable, unsigned int length);
char *str_cpy(char *dest, char *src);

/* prototypes for builtins */
int shell_env(void);
int shell_exit(void);
int buiilt_in_execu(char **tokens);
int shell_no_builtins(built_s builtin[]);

/* prototypes for the helper functions for path linked list */
char *get_env(const char *name);
char **copy_env(char **environ_copy, unsigned int environ_length);
list_s *pathlist(char *variable, list_s *head);

/* prototypes for free functions */
void free_all(char **tokens, char *path, char *line, char *fullpath, int flag);
void free_dp(char **array, unsigned int length);

#endif /* SHELL_H */
