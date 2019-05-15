/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** check_exec
*/

#include "my.h"

char *read_dir(char *cmd, char *path)
{
    DIR *dir;
    struct dirent *dirent;

    if ((dir = opendir(path)) == NULL)
        return (NULL);
    while ((dirent = readdir(dir)) != 0) {
        if (my_strcmp(cmd, dirent->d_name) == 0) {
            closedir(dir);
            return (path);
        }
        dirent->d_name[0];
    }
    closedir(dir);
    return (NULL);
}

char *check_exec(char **tab, char *cmd)
{
    DIR *dir;
    struct dirent *dirent;
    int count_path = 0;

    while (tab[count_path]) {
        if ((tab[count_path] = read_dir(cmd, tab[count_path])) != NULL)
            return (tab[count_path]);
        count_path++;
    }
    return (NULL);
}
