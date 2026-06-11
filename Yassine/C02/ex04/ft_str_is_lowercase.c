/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaadi <ybaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 18:33:47 by ybaadi            #+#    #+#             */
/*   Updated: 2026/06/08 13:54:00 by ybaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int     ft_str_is_lowercase(char *str)
{
    while (*str)
    {
        /*
            had l'interval li kayhamni:  [a... and ...z]
            3ksto bach ila l9it character kharj
            l'interval li bghit yrj3 0
        */
        if (*str < 'a' || *str > 'z')
        {
            return (0);
        }
        str++;
    }

    // ila tsalat loop y3ni string kamlha lowercase
    return (1);

    /*
        while (*str && (*str >= 'a' && *str <= 'z'))
        str++;

        if (*str != '\0')
            return (0);
        else
            return (1);
    */
}

/*int     main(void)
{

    printf("%d\n", ft_str_is_lowercase("Aa"));

    return (0);
}*/