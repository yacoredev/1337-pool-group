/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaadi <ybaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 13:26:54 by ybaadi            #+#    #+#             */
/*   Updated: 2026/05/17 00:57:20 by ybaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void    ft_putnbr(int nb)
{
    unsigned int    number;
    char            buff[12];
    int             i;

    // Type casting mn int -> unsig.., to prevent overflow fach nbghi ndrab f -1
    number = (unsigned int)nb;

    if (nb == 0)
    {
        write(1, "0", 1);
        return;
    }
    else if (nb < 0)
    {
        write(1, "-", 1);
        number *= -1;
    }

    i = 0;
    while (number > 0) {
        buff[i++] = (number % 10) + '0';
        number /= 10;
    }

    while(i > 0) {
        ft_putchar(buff[--i]);
    }
}

/* BEST methode
void    ft_putnbr(int nb)
{
	if (nb < 0)
	{
		if (nb == -2147483648)
		{
			ft_putnbr(-214748364);
			ft_putchar('8');
			return ;
		}
		ft_putchar('-');
		nb *= -1;
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar((nb % 10) + '0');
}
*/

/*
#include <limits.h>
int     main(void) {

    ft_putnbr(INT_MIN);

    return (0);
}
*/