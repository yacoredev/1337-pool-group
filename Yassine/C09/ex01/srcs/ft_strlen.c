/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaadi <ybaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 17:08:16 by ybaadi            #+#    #+#             */
/*   Updated: 2026/05/12 01:31:22 by ybaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    NAME:
        strlen - calculate the length of a string
    
    DESCRIPTION:
        The  strlen() function calculates the length of the string pointed to by 
        s, excluding the terminating null byte ('\0').

    RETURN VALUE:
        The strlen() function returns the number of bytes in the string pointed to by s.
    
    Errors:
        In standard C, strlen doesn't check for NULL and will crash if you pass it.
*/
int     ft_strlen(char *str)
{
    int     index;
    
    // methode 1:
    index = 0;
    while (str[index] != '\0')
    {
        index++;
    }
    return (index);
    
    // methode 2:
    // int count = 0;
    // while (*str != '\0')
    // {
    //     str++;
    //     count++;
    // }
    // return (count);

    // methode 3:
    // char *ptr = str;
    // while(*ptr)
    // {
    //     ptr++;
    // }
    // return (ptr - str);
}

/* #include <stdio.h>
int main(void)
{

    printf("%d\n", ft_strlen("hello")); // len = 5
    
    return (0);
}*/