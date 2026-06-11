/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaadi <ybaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 21:47:20 by ybaadi            #+#    #+#             */
/*   Updated: 2026/06/08 13:40:03 by ybaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int     ft_str_is_numeric(char *str)
{
    while (*str)
    {
        /*
            had l'interval li kayhamni:  [0... and ...9]
            3ksto bach ila l9it character kharj
            l'interval li bghit yrj3 0
        */

        if (*str < '0' || *str > '9')
        {
            return (0);
        }
        str++;
    }

    // ila tsalat loop y3ni mal9it hta character mn gher numbers(characters)
    return (1);
}

/*
int     main(void)
{
    printf("%d\n", ft_str_is_numeric("1247t"));

    return (0);
}*/