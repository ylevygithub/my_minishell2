/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** get
*/

#include "my.h"

int get_path(char *line_of_my_env)
{
    if (line_of_my_env != NULL && line_of_my_env[0] == 'P' &&
    line_of_my_env[1] == 'A' && line_of_my_env[2] == 'T' &&
    line_of_my_env[3] == 'H') {
        return (0);
    }
    return (1);
}

int get_home(char *line_of_my_env)
{
    if (line_of_my_env != NULL && line_of_my_env[0] == 'H' &&
    line_of_my_env[1] == 'O' && line_of_my_env[2] == 'M' &&
    line_of_my_env[3] == 'E') {
        return (0);
    }
    return (1);
}

int get_ch_before_homevalue(char *my_env)
{
    int i = 0;

    while (my_env[i] != '=') {
        i++;
    }
    i++;
    return (i);
}

char *my_gethome(char **my_env)
{
    int width = get_width_env(my_env);
    int i = 0;
    int j = 0;
    int x = 0;
    char *my_home = malloc(sizeof(char) * width + 1);

    while (get_home(my_env[i]) != 0)
        i++;
    j = get_ch_before_homevalue(my_env[i]);
    while (my_env[i][j] != 0) {
        my_home[x] = my_env[i][j];
        x++;
        j++;
    }
    my_home[x] = '\0';
    free(my_home);
    return (my_home);
}

char *my_getpath(char **my_env)
{
    int width = get_width_env(my_env);
    int i = 0;
    int j = 0;
    int x = 0;
    char *my_path = malloc(sizeof(char) * width + 1);

    if (my_env == NULL)
        return (NULL);
    while (get_path(my_env[i]) != 0)
        i++;
    j = get_ch_before_homevalue(my_env[i]);
    while (my_env[i][j] != 0) {
        my_path[x] = my_env[i][j];
        x++;
        j++;
    }
    my_path[x] = '\0';
    return (my_path);
}
