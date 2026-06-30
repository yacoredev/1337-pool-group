/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaadi <ybaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 19:24:38 by ybaadi            #+#    #+#             */
/*   Updated: 2026/06/05 23:31:08 by ybaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void    print_number(long n)
{
    // Technique: Recursion
    // if (n == 0)
    //     return;
    // print_number(n / 10);
    // ft_putchar((n % 10) + '0');
    // or:
    // if (nb > 9)
    //   print_nb(nb / 10);
    // c = nb % 10 + '0';
    // ft_putchar(c);

    // Technique: while loop
    // size 12 kafi lga3 lar9am (m3a '-' w '\0')
    char string[12];
    int i;

    i = 0;
    while(n > 0)
    {
        string[i++] = (n % 10) + '0';
        n /= 10;
    }

    while(i > 0)
    {
        ft_putchar(string[--i]);
    }

    // Technique: Divisor
    // int divisor = 1;
    // Nhssbo akbar divisor (exp 1000 bach nkhrjo '1' f 1234)
    // while (divisor <= n / 10)
    // {
    // 		divisor *= 10;
    // }
    //
    // while (divisor > 0)
    // {
    // 		ft_putchar((n / divisor) + '0');
    // 		n %= divisor;		// Nhaydo ra9m li tprinta
    // 		divisor /= 10;		// Nssghrou divisor
    // }
}

void    ft_putnbr(int nb)
{
    // Khdamna b unsig.. bach ntfadaw overflow mlli nbdlo sing dial -2147483648.
    unsigned int number = (unsigned int)nb;      // unsigned int (double range of int)

    if(nb == 0)
    {
        ft_putchar('0');
        return;
    }

    // INT_MIN = -2147483648
    // ila 7waltha lpositive ghatwli 2147483648
    // w had number ma3ndich f type int
    // INT_MAX = 2147483647
    if(nb < 0)
    {
        number *= -1;
        ft_putchar('-');
    }
    print_number(number);
}

/*
#include <limits.h>
int   main()
{
    ft_putnbr(INT_MIN);

    return (0);
}*/
