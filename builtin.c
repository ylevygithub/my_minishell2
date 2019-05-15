/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** builtins
*/

#include "my.h"

int my_pid(char *concat_cmd, char **cmd, char **my_env)
{
    pid_t pid = fork();

    if (pid < 0)
        my_putstr_error("Error to execute minishell1\n");
    else if (pid > 0)
        wait(NULL);
    else if (pid == 0) {
        if (execve(concat_cmd, cmd, my_env) == -1)
            return (84);
    }
    return (0);
}

int my_cmd(char **cmd, char **my_env)
{
    int count = 0;
    char *path = my_getpath(my_env);
    char **tab = tab_fix(tab, path, count);
    char *exec_path = check_exec(tab, cmd[0]);
    char *cat;

    if (exec_path == NULL) {
        my_putstr_error(cmd[0]);
        my_putstr_error(": Command not found.\n");
        return (1);
    }
    cat = my_strcat(exec_path, cmd[0]);
    if (my_pid(cat, cmd, my_env) == 84)
        return (84);
    free(cat);
    free(tab);
    free(exec_path);
    return (0);
}

void exit_setenv(char **cmd, char **my_env)
{
    if (my_strcmp(cmd[0], "exit") == 0) {
        my_putstr("exit\n");
        exit(0);
    }
    else if (my_strcmp(cmd[0], "env") == 0)
        my_putmap(my_env);
}

int builtin(char **cmd, char **my_env)
{
    exit_setenv(cmd, my_env);
    if (my_strcmp(cmd[0], "unsetenv") == 0) {
        write(2, "unsetenv: Too few arguments.\n", 29);
        return (1);
    }
    else if (my_strcmp(cmd[0], "setenv") == 0)
        my_putmap(my_env);
    else
        if (my_cmd(cmd, my_env) == 84)
            return (84);
    return (0);
}
