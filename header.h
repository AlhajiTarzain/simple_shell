#ifndef HEADER_H
#define HEADER_H



#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/*prototypes*/
int myputchar(char c);
void _myprintf(const char *);
int inbenv();
int compare(const char *first, const char *second, size_t total);
int length(const char *str);
char *duplicator(const char *str);
int comp(char *first, char *second);
char *copy(char *s1, char *s2);
char *concat(char *s1, const char *s2);
char *create_path(char *args);
int inbuilt(char **args, char *input, int result);
int execute_cmd(char **args, __attribute__((unused)) char *input);
int checker(char **args, char *line);
char *copy(char *s1, char *s2);
char *concat(char *s1, const char *s2);
int comp(char *first, char *second);
char *duplicator(const char *str);
int length(const char *str);
int ston(char *str);
void empty(char **prr);
int exitshell(char **cmd, char *input, int status);
char **mtoken(char *input_str, char *delimiter);

#endif
