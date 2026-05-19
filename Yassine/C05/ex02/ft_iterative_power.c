/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaadi <ybaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 18:20:11 by ybaadi            #+#    #+#             */
/*   Updated: 2026/05/05 19:09:41 by ybaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     ft_iterative_power(int nb, int power)
{
    int     value;
    
    if (power < 0)
    {
        return (0);
    }
    
    value = 1;
    // The power is the number multiplied by itself (power) times
    while (power > 0)
    {
        value *= nb;  
        power--;
    }
    return (value);
}

/*
#include <stdio.h>
int main(void)
{
    int nbr = 0;
    int power = 0;
    
    printf("%d power(%d) = %d\n", nbr, power, ft_iterative_power(nbr, power));
    return 0;
}
*/