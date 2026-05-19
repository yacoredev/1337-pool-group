/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaadi <ybaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 11:11:57 by ybaadi            #+#    #+#             */
/*   Updated: 2026/05/06 18:24:29 by ybaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    Rational number:
    A number that can be written as a fraction (a / b), where b != 0
    Examples: 1/2, 3, 0.75

    Irrational number:
    A number that cannot be written as a fraction
    Its decimal form is infinite and non-repeating
    Examples: sqrt(2), pi

    In this exercise:
    If sqrt(nb) is an integer, return it
    Otherwise, return 0
*/
int     ft_sqrt(int nb)
{
    unsigned int     i;
    
    // Handl negative numbers and zero
    if (nb <= 0)
    {
        return (0);
    }
    
    i = 1;
    /*
        Rational square root dyal nb howa number so that:
        number * number = nb  <=>  number = nb / number
        
        drtha bsigha tanya bach i yb9a ymchi gher 7tal i * i = nb mayfotoch
        w bach maykbarch i bzaf (prevent overflow):
        Example:    ila kant nb = 2147483647 (Max Int)
                    i ghadi w kaytla3 fach kaywsal 46341
                    kaydir 2147483647 / 46341 = 46340
                    kywli condition (46341 <= 46340) False
    */
    while (i <= nb / i)
    {
        // Ila l9it had rational square root * fraso = nb
        // farah howa sqrt dyal nb
        if (i * i == nb)
        {
            return ((int)(i));
        }
        i++;
    }
    // No integer square root (irrational result)
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