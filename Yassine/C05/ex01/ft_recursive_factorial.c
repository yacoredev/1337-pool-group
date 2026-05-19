/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaadi <ybaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 17:56:16 by ybaadi            #+#    #+#             */
/*   Updated: 2026/05/05 18:51:28 by ybaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     ft_recursive_factorial(int nb)
{   
    if (nb < 0)
    {
        return (0);
    }
    if (nb == 0)
    {
        return (1);
    }
    return (nb * ft_recursive_factorial(nb - 1));
}

/*
#include <stdio.h>
int main(void)
{
    int nbr = -4;
    
    printf("factorial of %d! : %d\n", nbr, ft_recursive_factorial(nbr));
    
    return 0;
}
*/