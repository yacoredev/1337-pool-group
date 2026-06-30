/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaadi <ybaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 19:24:18 by ybaadi            #+#    #+#             */
/*   Updated: 2026/06/04 17:03:45 by ybaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_print_reverse_alphabet(void)
{
	char letter;

	letter = 'z';	// 'z' = 122 (integer) in ascii table
	while (letter >= 'a')
	{
		ft_putchar(letter);
		letter--;
	}
}

/*int	main()
{
	ft_print_reverse_alphabet();
	return(0);
}*/
