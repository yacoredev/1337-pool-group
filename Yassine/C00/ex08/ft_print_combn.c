/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaadi <ybaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 12:35:10 by ybaadi            #+#    #+#             */
/*   Updated: 2026/06/07 18:00:00 by ybaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// matkhdmoch 7ta trj3 lih fday 5 wla 6 7it m7taj backtracking

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

	/*
	Example: n = 3
		f level 0 kankhzan 0
		kandkhal level 1 kankhzan 1
		kandkhal level 2 kankhzan 2 <-- kanb9a fhad level hta ywsal max dyalo '9'

		karja3 level 1 (digit +1) kankhzan 2
		kandkhal level 2 kankhzan 3 <-- kanb9a fhad level hta ywsal max dyalo '9'

		w hka 7ta nwsal max dyal level 1 -> '8'
		karja3 level 0 (digit +1) kankhzan 1
		kandkhal level 1 kankhzan 2
		kandkhal level 2 kankhzan 3 <-- kanb9a fhad level hta ywsal max dyalo '9'
		...
		w haka 7ta nwsal max dyal level 0 -> '7'
	*/
void	backtrack(char *comb, int level, int digit, int size)
{
	// if level is outside of size, print result
	if (level == size)
	{
		comb[level] = '\0';
		ft_putstr(comb);
		/* if firs number reaches its maximum, don't add comma & space  */
		if (comb[0] != (10 - size) + '0')
			ft_putstr(", ");
		return ;
	}
	/*  while mawsaltch lmax dyal kola level  */
	while (digit <= 10 - (size - level))
	{
		comb[level] = digit + '0';
		backtrack(comb, level+1, digit+1, size);
		digit++;
	}
}

void	ft_print_combn(int n)
{
	char	comb[10];

	if (n > 0 && n < 10)
	{
		backtrack(comb, 0, 0, n);
	}
	return ;
}
