/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaadi <ybaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:20:13 by ybaadi            #+#    #+#             */
/*   Updated: 2026/06/11 17:55:53 by ybaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    NAME:
        strcat - copy or catenate a string

    DESCRIPTION:
        This function catenates the string pointed to by src, after the string pointed
        to by dst (overwriting its terminating null byte) "kanktbo fo9 null ter".
        The programmer is responsible for allocating a destination buffer large enough,
        that is, strlen(dst) + strlen(src) + 1.

    RETURN VALUE:
        These functions return dst.

    Errors:
        if dest buffer less than strlen(dst) + strlen(src) + 1
        It causes a Buffer Overflow.
        Basically, it doesn't check the size
*/

int     ft_strlen(char *str)
{
    int     index;

    index = 0;
    while (str[index])
        index++;
    return (index);
}

char    *ft_strcat(char *dest, char *src)
{
    int     d_len;
    int     i;

    /*
        man strcat makaydirch guard l dest wla src
    */
    d_len = ft_strlen(dest);
    i = 0;
    while (src[i])
    {
        dest[d_len + i] = src[i];
        i++;
    }
    dest[d_len + i] = '\0';
    return(dest);
}

/*
#include <stdio.h>

int     main(int c, char **v)
{
    char buffer[50] = "Morroco";

    if (c == 2)
    {
        printf("%s\n", ft_strcat(buffer, v[1]));
    }
    else
    {
        printf("put one string to catenates it with the origin text\n");
    }
    return (0);
}
*/