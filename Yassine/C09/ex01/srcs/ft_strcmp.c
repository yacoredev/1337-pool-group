/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaadi <ybaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 18:27:33 by ybaadi            #+#    #+#             */
/*   Updated: 2026/04/21 17:00:46 by ybaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    NAME:
       strcmp - compare two strings
    
    DESCRIPTION:
       The strcmp() function compares the two strings s1 and s2. The locale is not taken into account
       The comparison is done using unsigned characters.

    RETURN VALUE:
       strcmp() returns an integer indicating the result of the comparison, as follows:

       •  0, if the s1 and s2 are equal;

       •  a negative value if s1 is less than s2;

       •  a positive value if s1 is greater than s2.
*/

int     ft_strcmp(char *s1, char *s2)
{
    while (*s1 && *s2)
    {
        if (*s1 != *s2)
            break;
        s1++;
        s2++;
    }
    return ((unsigned char)*s1 - (unsigned char)*s2);
}

/*
#include <stdio.h>

int     main(void)
{
    char s1[] = "Applet";
    char s2[] = "Applet";

    // Compare two strings 
  	// and print result
    int res = ft_strcmp(s1, s2);

    printf("According to the ASCII table,\n");
    if(res == 0)
        printf("string1 and string2 are same\n");
    else if(res < 0)
        printf("string1 is smaller than string2\n");
    else
        printf("string1 is greater than string2\n");
        
    return (0);
}
*/