/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** main
*/

#include "my.h"

int main_func(char **av, char **my_env, char **cmd)
{
    size_t c = 32;
    int count;
    char *cmd_base;

    my_putstr("----<<<<WELCOME TO THE SHELL OF Yaacov Levy<<<<----\n");
    while (42) {
        my_putstr("$>");
        if (getline(&cmd_base, &c, stdin) == -1) {
            my_putstr("exit\n");
            exit(0);
        }
        cmd_base = epure_str(cmd_base);
        if (last_char_redirect(cmd_base) == 1)
            return (1);
        cmd = str_to_word_tab(cmd_base, count);
        if (builtin(cmd, my_env) == 84)
            return (84);
    }
    free(cmd_base);
    return (0);
}

int main(int ac, char **av, char **env)
{
    char **cmd;
    char **my_env = create_env(get_height_env(env), get_width_env(env), env);
    my_env = my_getenv(env, my_env);
    char *path = my_gethome(my_env);
    int return_value = main_func(av, my_env, cmd);

    error_gestion(ac);
    if (return_value == 84 || return_value == 1)
        return (return_value);
    free(cmd);
    free(path);
    free(my_env);
    return (0);
}
