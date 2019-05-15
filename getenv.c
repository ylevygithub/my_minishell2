/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** get the env
*/

#include "my.h"

int get_height_env(char **env)
{
    int i = 0;
    int height_max = 0;

    while (env[i] != NULL) {
        i++;
        height_max++;
    }
    return (height_max);
}

int get_width_env(char **env)
{
    int i = 0;
    int j = 0;
    int width_max = 0;

    while (env[i] != NULL) {
        while (env[i][j] != '\0') {
            j++;
            width_max++;
        }
        j = 0;
        i++;
    }
    return (width_max);
}

char **create_env(int height_max, int width_max, char **env)
{
    int i = 0;
    int j = 0;

    height_max = get_height_env(env);
    width_max = get_width_env(env);
    char **map = malloc(sizeof(char *) * height_max + 1);

    while (i < height_max + 1) {
        map[i] = malloc(sizeof(char) * width_max + 1);
        i++;
    }
    return (map);
}

void my_putmap(char **map)
{
    int i = 0;

    while (map[i] != NULL) {
        my_putstr(map[i]);
        my_putchar('\n');
        i++;
    }
}

char **my_getenv(char **env, char **my_env)
{
    if (env == NULL || my_mapcpy(env, my_env) == NULL)
        return (NULL);
    my_mapcpy(env, my_env);
    return (my_env);
}
