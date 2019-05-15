/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** error handling
*/

#include "my.h"

void  my_putchar_error(char c)
{
    write(2, &c, 1);
}

void my_putstr_error(char *str)
{
    int nb = 0;

    while (str[nb] != '\0') {
        my_putchar_error(str[nb]);
        nb++;
    }
}

void error_gestion(int ac)
{
    if (ac != 1) {
        write(2, "One argument, no more, no less.\n", 32);
        exit(84);
    }
}

int verif_last_char_redirection(char *cmd_base, char symbol)
{
    int i = 0;

    while (cmd_base[i] != 0)
        i++;
    if (cmd_base[i - 1] == symbol ||
    (cmd_base[i - 1] == symbol && cmd_base[i - 2] == symbol))
        return (1);
    return (0);
}

int last_char_redirect(char *cmd_base)
{
    if (verif_last_char_redirection(cmd_base, '|') == 1) {
        my_putstr("Invalid null command.\n");
        return (1);
    }
    if (verif_last_char_redirection(cmd_base, '>') == 1 ||
    verif_last_char_redirection(cmd_base, '<') == 1) {
        my_putstr("Missing name for redirect.\n");
        return (1);
    }
    return (0);
}
