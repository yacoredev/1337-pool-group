/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaadi <ybaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 20:15:35 by ybaadi            #+#    #+#             */
/*   Updated: 2026/06/08 13:57:44 by ybaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int     ft_str_is_uppercase(char *str)
{
    while (*str)
    {
        /*
            had l'interval li kayhamni:  [A... and ...Z]
            3ksto bach ila l9it character kharj
            l'interval li bghit, yrj3 0
        */
        if (*str < 'A' || *str > 'Z')
        {
            return (0);
        }
        str++;
    }

    // ila tsalat loop y3ni string kamlha uppercase
    return (1);
}

/*int     main(void)
{

    printf("%d\n", ft_str_is_uppercase("AZ+"));

    return (0);
}*/