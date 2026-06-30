/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaadi <ybaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 19:01:26 by ybaadi            #+#    #+#             */
/*   Updated: 2026/06/11 18:00:00 by ybaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    NAME:
        strncat - append non-null bytes from a source array to a string,
        and null-terminate the result

    DESCRIPTION:
        This function appends at most nb non-null bytes from the array pointed to by src, fol‐
        lowed by a null character, to the end of the string pointed to by dst.
        dst must point to a string contained in a buffer that is large enough, that is,
        the buffer size must be at least strlen(dst) + strnlen(src, n) + 1.

    RETURN VALUE:
        These functions return dst.

    Errors:
        if dest buffer less than strlen(dst) + (n byte of src) + 1
        It causes a Buffer Overflow.
        Basically, it doesn't check the size of dest

    Advantage :
        Safety, strncat appends only n characters, giving you control to prevent memory overflows.
        deference binha w bin strcat hya kat7akam f ch7al tcopy (ila 3rfti sizeof(dest)) bach
        mat overflowach, ima strcat katcopy bla franat ta tsali src w khlas
*/

int     ft_strlen(char *str)
{
    int     index;

    index = 0;
    while (str[index])
    {
        index++;
    }
    return (index);
}

char    *ft_strncat(char *dest, char *src, unsigned int nb)
{
    unsigned int     d_len;
    unsigned int     i;

    d_len = ft_strlen(dest);

    i = 0;
    while (i < nb && src[i])
    {
        dest[d_len + i] = src[i];
        i++;
    }
    // f standard version darori nzid '\0' dema
    dest[d_len + i] = '\0';
    return (dest);
}

/*
#include <stdio.h>

int     main(int c, char *v[])
{
    char buff[20] = "origin text.";

    if (c == 2)
    {
        printf("Added %d chars to:\n%s\n", 3, ft_strncat(buff, v[1], 3));
    }
    else
    {
        printf("put one string to catenates it with the origin text\n");
    }
    return (0);
}
*/