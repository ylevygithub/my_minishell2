/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** my.h
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>

/*getenv.c*/
char **create_env(int , int , char **);
char **my_getenv(char **, char **);
int get_height_env(char **);
int get_width_env(char **);
void my_putmap(char **);

/*str_to_word_tab.c*/
char *separate_path(char *);
int count_char(char *, int *);
int count_word(char *);
char **str_to_word_tab(char *, int );

/*builtin.c*/
int my_cmd(char **cmd, char **my_env);
int my_pid(char *concat_cmd, char **cmd, char **my_env);
int builtin(char **, char **);
void exit_setenv(char **, char **);

/*my_mapcpy.c*/
char **my_mapcpy(char **, char **);

/*lib.c*/
void my_putchar(char );
void my_putstr(char *);
int my_strcmp(char *, char *);
int my_strlen(char *);
char *my_strcat(char *path, char *cmd);

/*clean_str.c*/
char *epure_str(char *);
int end_str(char *);

/*my_get.c*/
int get_home(char *);
int get_path(char *);
int get_ch_before_homevalue(char *);
char *my_gethome(char **);
char *my_getpath(char **);

/*main.c*/
int main_func(char **, char **, char **);

/*error_handling.c*/
void my_putchar_error(char );
void my_putstr_error(char *);
void error_gestion(int );
int verif_last_char_redirection(char *, char );
int last_char_redirect(char *);

/*path_handling.c*/
char *full_path_ls(char *);
char *full_path_pwd(char *);
char **tab_fix(char **, char *, int );
int my_ls(char **, char **, char **);
int my_pwd(char **, char **, char **);

/*exec_path.c*/
char *read_dir(char *, char *);
char *check_exec(char **, char *);
