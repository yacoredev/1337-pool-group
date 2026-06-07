/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaadi <ybaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 19:24:23 by ybaadi            #+#    #+#             */
/*   Updated: 2026/06/04 17:06:23 by ybaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_numbers(void)
{
	char start;
	char end;

	start = '0';
	end = '9';
	while (start <= end)
	{
		ft_putchar(start);
		start++;
	}
}

/*int	main()
{
	ft_print_numbers();
	return(0);
}*/
