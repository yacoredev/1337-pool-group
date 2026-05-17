/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaadi <ybaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 22:28:07 by ybaadi            #+#    #+#             */
/*   Updated: 2026/05/17 12:49:27 by ybaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    NAME:
        strlcat - copying strings and character sequences

    DESCRIPTION:
        Copy and catenate the input string into a destination string.  If the  destination
        buffer,  limited  by  its size, isn't large enough to hold the copy, the resulting
        string is truncated (but it is guaranteed to be null-terminated).  They return the
        length of the total string they tried to create.

    RETURN VALUE:
        The length of the total string that they tried to create
        (as if truncation  didn't occur).

    Advantage :
        strcat: Dangerous; doesn't check destination size, leads to buffer overflows.
        strncat: Safer; limits characters copied, but doesn't guarantee null-termination
        if size is wrong.
        strlcat: Safest; guarantees null-termination and returns the total length it tried
        to create to detect truncation.
*/

int     ft_strlen(char *str)
{
    unsigned int     index;

    if (!str)
    {
        return (0);
    }

    index = 0;
    while (str[index])
    {
        index++;
    }
    return (index);
}

unsigned int    ft_strlcat(char *dest, char *src, unsigned int size)
{
    unsigned int    d_len;
    unsigned int    s_len;
    unsigned int    i;

    d_len = ft_strlen(dest);
    s_len = ft_strlen(src);

    /*
        ila kan d_size <= len(dest) y3ni size aslan sghar mn origin string li fdest
        y3ni ma3ndi fin nzid chi7aja hna kaywli size = len (7it fhad size mal9itch '\0')
        fhad case standard kigoul rje3 strlen(src) + size.
    */
    if (size <= d_len)
    {
        return (s_len + size);
    }

    /* index dyal '\0' = size - 1 */
    i = 0;
    while (src[i] && (d_len + i) < (size - 1))
    {
        dest[d_len + i] = src[i];
        i++;
    }
    dest[d_len + i] = '\0';
    return (d_len + s_len);
}

#include <stdio.h>


int     main(int argc, char *argv[])
{
    char buffer[13] = "origin text.";
    unsigned int size = sizeof(buffer);
    unsigned int ret_len;

    if (argc == 2)
    {
        ret_len = ft_strlcat(buffer, argv[1], size);

        printf("result: %s\n", buffer);
        printf("The length of string that tried to create: %d\n", ret_len);
        printf("Buffer size allowed: %d\n", size);

        // TRUNCATION CHECK
        if (ret_len < size)
            printf("\nCopying successful\n");
        else
        {
            printf("\nTruncation happened\n");
            printf("you need at least %d bytes\n", ret_len);
        }
    }
    else
    {
        printf("put one string to catenate it with origin text!\n");
    }
    return (0);
}
