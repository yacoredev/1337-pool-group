/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaadi <ybaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 11:11:57 by ybaadi            #+#    #+#             */
/*   Updated: 2026/06/14 01:05:39 by ybaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    Rational number: (integer)
    A number that can be written as a fraction (a / b), where b != 0
    Examples: 1/2, 3, 0.75
    Perfect Square
    sqrt(4)  = 2      => return 2
    sqrt(9)  = 3      => return 3
    sqrt(16) = 4      => return 4

    Irrational number:
    A number that cannot be written as a fraction
    Its decimal form is infinite and non-repeating
    Examples: sqrt(2), pi
    sqrt(2)  = 1.414213...  => return 0
    sqrt(3)  = 1.732050...  => return 0
    sqrt(5)  = 2.236067...  => return 0
*/
int     ft_sqrt(int nb)
{
    unsigned int     i;

    /* Handl negative numbers and zero */
    if (nb <= 0)
    {
        return (0);
    }

    i = 1;
    /*
        loop while multiplying two numbers i * i <= nb
        Prevent overflow: use i <= nb / i instead of i * i <= nb
        hadi li ghadir overflow (i * i) ila kbrat bzaf
    */
    while (i <= nb / i)
    {
        /*
            Ila l9it had rational square root * fraso = nb
            farah howa sqrt dyal nb
        */
        if (i * i == nb)
        {
            return ((int)(i));
        }
        i++;
    }
    /* No integer square root (irrational result) */
    return (0);
}

/*
#include <stdio.h>
#include <limits.h>
int     main(void)
{
    int     nbr = 3;
    printf("sqrt(%d) = %d\n", nbr, ft_sqrt(nbr));

    return (0);
}
*/