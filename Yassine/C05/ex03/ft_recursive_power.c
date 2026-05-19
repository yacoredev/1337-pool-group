/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaadi <ybaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 18:49:21 by ybaadi            #+#    #+#             */
/*   Updated: 2026/05/05 19:09:11 by ybaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     ft_recursive_power(int nb, int power)
{
    if (power < 0)
    {
        return (0);
    }
    // Any number raised to 0 is 1
    if (power == 0)
    {
        return (1);
    }
    return (nb * ft_recursive_power(nb, power - 1));
}

/*
#include <stdio.h>
int main(void)
{
    int nbr = 5;
    int power = -4;
    
    printf("%d power(%d) = %d\n", nbr, power, ft_recursive_power(nbr, power));
    return 0;
}
*/