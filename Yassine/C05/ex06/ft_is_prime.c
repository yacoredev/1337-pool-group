/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaadi <ybaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 17:02:10 by ybaadi            #+#    #+#             */
/*   Updated: 2026/05/07 00:31:08 by ybaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    The Logic:
    If a number n is composite (not prime), it can be factored into a * b = n.
    If both a and b were greater than sqrt{n},
    then a * b would be greater than n (a * b > sqrt{n} * sqrt{n} = n), which 
    is impossible.
    
    Therefore, at least one factor must be less than or equal to sqrt{n}. 
    To check if a number is prime, you only need to search for divisors up to sqrt{n}. 
    If you don't find any divisor by that point, there aren't any at all.
*/
int     ft_is_prime(int nb)
{
    int     i;

    // 0 and 1 are not prime numbers and we dont have negative prime numbers
    if (nb < 2)
    {
        return (0);
    }
    
    // gaa3 numbers kat9bel div 3la 1 w 3la rasha 3liha bdina mn 2 w 7bsna 9bal nb
    i = 2;
    
    /*
        If a number has a divisor,
        you will find it before sqrt(nb)

        Any number note prime, rah jay men darb dyal two numbers: nb = a * b
        and at least one of a or b must be <= sqrt(n),
        otherwise their product would be greater than n.

        loop 7tal i <= sqrt(nb)  <=>  i * i <= nb  <=>  i <= nb / i
    */
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


#include <stdio.h>
int     main(void)
{
    int     nbr = 2;
    int     ret = ft_is_prime(nbr);
    
    if (ret)
        printf("%d is Prime Number\n", nbr);
    else    printf("%d is NOT Prime Number\n", nbr);
    
    return (0);
}
