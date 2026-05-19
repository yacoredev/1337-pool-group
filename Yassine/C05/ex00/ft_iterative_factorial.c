/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaadi <ybaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 16:55:07 by ybaadi            #+#    #+#             */
/*   Updated: 2026/05/17 12:51:49 by ybaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     ft_iterative_factorial(int nb)
{
    int     fact;

    // rule: 0! = 1 and the result of negative factorial is zero
    if (nb == 0)
    {
        return (1);
    }
    if (nb < 0)
    {
        return (0);
    }

    fact = 1;
    while (nb > 0)
    {
        fact *= nb;
        nb--;
    }
    return (fact);
}

/*
#include <stdio.h>
int main(void)
{
    int nbr = 0;

    printf("factorial of %d! : %d\n", nbr, ft_iterative_factorial(nbr));

    return 0;
}
*/