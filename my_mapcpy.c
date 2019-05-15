/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** copy the map
*/

#include "my.h"

char **my_mapcpy(char **src, char **dest)
{
    int i = 0;
    int j = 0;
    int x = 0;
    int y = 0;

    if (dest == NULL)
        return (NULL);
    while (src[i] != NULL) {
        while (src[i][j] != '\0') {
            dest[x][y] = src[i][j];
            j++;
            y++;
        }
        j = 0;
        y = 0;
        i++;
        x++;
    }
    dest[x] = NULL;
    return(dest);
}
