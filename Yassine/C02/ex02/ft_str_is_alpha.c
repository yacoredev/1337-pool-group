/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaadi <ybaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 21:25:28 by ybaadi            #+#    #+#             */
/*   Updated: 2026/06/08 13:33:21 by ybaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int     ft_str_is_alpha(char *str)
{
    while (*str)
    {
        /*
            had l'interval li kayhamni:  [A... and ...Z] or [a... and ...z]
            3ksto bach ila l9it character kharj
            l'interval li bghit yrj3 0
        */
        if ((*str < 'A' || *str > 'Z') &&
            (*str < 'a' || *str > 'z'))
        {
            return (0);
        }
        str++;
    }

    // ila tsalat loop y3ni mal9it hta character mn gher letters(characters)
    return (1);
}

/*int     main(void)
{
    // char empty[1] = "";      // Allocates 1 byte, initializes as '\0'
    // char buffer[100] = "";   // Allocates 100 bytes, first character is '\0'

    printf("%d\n", ft_str_is_alpha("hello4"));

    return (0);
}*/