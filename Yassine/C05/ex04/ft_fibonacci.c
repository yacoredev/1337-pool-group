/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaadi <ybaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 19:17:26 by ybaadi            #+#    #+#             */
/*   Updated: 2026/06/13 18:41:59 by ybaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    Formula:
    Fib_n = Fib_n-1 + Fib_n-2
    F_0 = 0
    F_1 = 1
*/
int     ft_fibonacci(int index)
{
    // Recursion Technique:
    if (index < 0)
    {
        return (-1);
    }
    // if index = 1 or 0 return it (default start sequence 0 1)
    if (index < 2)
    {
        return (index);
    }
    /*
        kanb9aw nhbto hta nwslo l default numbers li homa 0 or 1
        w kanb9a n7sb mn 3ndhom n = n-1 + n-2 hta nwsal l index

        Example:
        f(4)
        =
        f(3) + f(2) --> fach trja3 lya f(3) kandoz l f(2) = ..

        f(3)
        =
        f(2) + f(1) --> fach trja3 lya f(2) kandoz l f(1) = ..

        f(2)
        =
        f(1) + f(0) <-- f(1) return 1, f(0) return 0

        wsalt default numbers daba nb9aw njm3o w ntl3o
        first number + next number
    */
    return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));

    // Iterative Technique:
    // int     base0 = 0;
    // int     base1 = 1;
    // int     fib = 0;
    // int     i = 0;
    // if (index < 0)  return -1;
    // while (i < index - 1)
    // {
    //     fib = base0 + base1;
    //     base0 = base1;
    //     base1 = fib;
    //     i++;
    // }
    // return (fib);
}

/*
#include <stdio.h>
int main(void)
{
    int idx = 7;
    int ret = ft_fibonacci(idx);

    if (ret >= 0)
        printf("nth Fibonacci of %d is: %d\n", idx, ret);
    else
        printf("Error! \"negative value\"\n");

    return 0;
}
*/