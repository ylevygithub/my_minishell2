/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** path handling for no builtins
*/

#include "my.h"

char **tab_fix(char **cmd, char *path, int count)
{
    path = separate_path(path);
    cmd = str_to_word_tab(path, count);
    return (cmd);
}
