#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_INPUT_LENGTH 1024
#define BUFFER_SIZE 1024
extern char **environ;

char *_itoa(int num_len);
int _putchar(char c);
char *terminate(char **args, char **line);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
void new_process(char **args, char *str_path, char *envp[]);
int _strlen(char *s);
int tonkenization(char **args, char *line);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _setenv(char *name, char *value);
int isBuiltIn(char *args[]);
void exec_builtIns(char **args, char *str_path, char *envp[]);
void _env(void);
void _unsetenv(char **args);
void _cd(char *args[]);
char *get_env(char *env_name);
int my_getline(char **line_ptr, size_t *n_chars, FILE *stream);
void cd_process(char *absolute_path, char *cwd, DIR *dirp, char *dir_name,
struct stat filestat);
void cd_dash(char *old_pwd, char *cwd);
void create_env(int counter, int new_len, char *new_env);
void modify_env(char **env_ptr, char *env_string, char *new_env,
char *env_name, int *env_len, int *counter, int *env_modified);
char *_strtok(char *str, char *delim);
int  first_tok(char *next_tok, char *delim, int *isdelim);
void subsequent_tok(char **next_tok, char *delim, int *isdelim);
int _strncmp(char *s1, char *s2, int len);
void unset(int env_index, int counter);
char *cmd_location(char *command, char *str_path);
void _puts(char *str);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, int len);
int _atoi(char *s);
void exempt_comments(char **s);
void _eputs(char *str);
void non_interactive(char **argv, char **envp);
int non_i_tokenization(char **args, char *line);
int n_toks(char *line);
#endif /*MAIN_H*/
