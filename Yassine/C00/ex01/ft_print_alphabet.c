/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaadi <ybaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 19:24:14 by ybaadi            #+#    #+#             */
/*   Updated: 2026/06/04 17:01:12 by ybaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_print_alphabet(void)
{
	char letter;

	letter = 'a';	// 'a' = 97 in ascii table
	while (letter <= 'z')
	{
		ft_putchar(letter);
		letter++;
	}
}

/*int	main()
{
	ft_print_alphabet();
	return(0);
}*/
