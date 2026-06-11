/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaadi <ybaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 19:54:17 by ybaadi            #+#    #+#             */
/*   Updated: 2026/06/08 13:28:59 by ybaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

/*
    imp: strcpy() wa strncpy() makayhtamoch lsize dyal dest wach sghir wla kbir
    lfr9 binhom:
    - strcpy() gher katcopy bla chorot (momkin ti7 f Buffer Overflow ila kan src>dest).
    - strncpy() katcopy but number of n (y3ni momkin ntfada buffer overflow
    b size dyal dest)

    The strncpy() function is similar to strcpy(),
    but it copies at most n bytes from source to destination string.
    If source is shorter than n, strncpy() adds a null character to
    destination to ensure n characters are written. exp [h,e,l,\0,\0,\0]

    man strncpy: "If there is no null byte among the first n bytes
    of src, the string placed in dest will not be null-terminated."
    y3ni ila kan n sghr mn src dik string li ghatcopa fdest maghatkonch
    fiha '\0'
*/
char    *ft_strncpy(char *dest, char *src, unsigned int n)
{
    /*
        bach ntfada warning dyal "comparison between signed and unsigned"
        w aslan fach kant3aml m3a bytes khasni unsigned int wla size_t
    */
    unsigned int     i;

    i = 0;
    while (i < n && src[i])
    {
        dest[i] = src[i];
        i++;
    }

    /*
        darori nzido Null terminator bach nsdo string
        ila tcopat src kolha f dest wmazal n kbir
        nkml dakchi lib9a f dest b '\0' hta nsali n.
        ila len(src) >= n maghatzadch '\0' f dest
        7it khrejt mn loop li 9bal, 9bal mal9a '\0' f src,
        or btari9a khora condition li khrjatni hya i < n
        w hya nit li kayna flwhile tanya
    */
    while (i < n)
    {
        dest[i] = '\0';
        i++;
    }
    return (dest);
}

/*int main(void) {
    char src[] = "Hello";
    char dest[20];

    // Copies "Hello" to dest
    // It returns a pointer to the dest string after copying the content from src.
    printf("%s\n", ft_strncpy(dest, src, 3));       // hell
    return(0);
}*/