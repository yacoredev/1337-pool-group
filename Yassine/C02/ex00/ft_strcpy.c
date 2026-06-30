/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaadi <ybaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 19:15:23 by ybaadi            #+#    #+#             */
/*   Updated: 2026/06/08 13:18:15 by ybaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

/*
    imp: strcpy() wa strncpy() makayhtamoch lsize dyal dest wach sghir wla kbir
    lfr9 binhom:
    - strcpy() gher katcopy bla chorot (momkin ti7 f Buffer Overflow ila kan src>dest).
    - strncpy() katcopy but number of n (y3ni momkin ntfada buffer overflow
    ila 3rft size dyal dest)

    The strcpy() function copies a string from the source to the destination.
    It copies the entire string, including the null terminator.

    Fl man strcpy, lfunction makat verifiych wach dest sghira 3la src. Ila kant
    src kbira, lprogram ghadi ycrash (segmentation fault)
    Dakchi 3lach khass tcopier kolchi bla ma tswwel 3la
    size (hadik khdma dyal [strncpy] machi strcpy).
*/
char    *ft_strcpy(char *dest, char *src)
{
    unsigned int    i;

    i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    // darori nzido Null terminator bach nsdo string
    dest[i] = '\0';
    return (dest);
}

/*int     main(void)
{
    char src[] = "Hello";
    char dest[20];

    // Copies "Hello" to dest
    // It returns a pointer to the dest string after copying the content from src.
    printf("%s\n", ft_strcpy(dest, src));      // hello

    return(0);
}*/