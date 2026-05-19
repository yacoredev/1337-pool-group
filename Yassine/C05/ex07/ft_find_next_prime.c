/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaadi <ybaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 00:36:42 by ybaadi            #+#    #+#             */
/*   Updated: 2026/05/07 01:09:19 by ybaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     ft_is_prime(int nb)
{
    int     i;

    if (nb < 2)
    {
        return (0);
    }
    
    i = 2;
    while (i <= nb / i)
    {
        if (nb % i == 0)
        {
            return (0);
        }
        i++;
    }
    return (1);
}

int     ft_find_next_prime(int nb)
{
    int     i;
    // first Next prime number is 2
    if (nb <= 2)
    {
        return (2);
    }
    
    i = nb;
    // While nb is not prime, nb is increased
    while (!ft_is_prime(i))
    {
        i++;
    }
    return (i);
}


#include <stdio.h>
int     main(void)
{
    int     nbr = 4;
    
    printf("Next prime number of %d is: %d\n", nbr,ft_find_next_prime(nbr));
    
    return (0);
}