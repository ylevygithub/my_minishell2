/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** lib
*/

#include "my.h"

void  my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    int nb = 0;

    while (str[nb] != '\0') {
        my_putchar(str[nb]);
        nb++;
    }
}

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    while (s1[i]) {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    i = 0;
    while (s2[i]) {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    return (0);
}

char *my_strcat(char *path, char *cmd)
{
    int i = 0;
    int j = 0;
    int x = 0;
    char *tmp = malloc(sizeof(char) * 4096);

    while (path[i] != 0) {
        tmp[j] = path[i];
        i++;
        j++;
    }
    tmp[j] = '/';
    j++;
    while (cmd[x] != 0) {
        tmp[j] = cmd[x];
        x++;
        j++;
    }
    tmp[j] = '\0';
    return (tmp);
}
