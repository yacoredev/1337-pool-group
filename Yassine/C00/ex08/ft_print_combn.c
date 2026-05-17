/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaadi <ybaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 12:35:10 by ybaadi            #+#    #+#             */
/*   Updated: 2026/05/15 12:35:11 by ybaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// matkhdmoch 7ta trj3 lih fday 5 wla 6

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

void	backtrack(char *comb, int n, int curr_pos, int digit)
{
	if (curr_pos == n)
	{
		comb[curr_pos] = '\0';
		ft_putstr(comb);
		/* if firs number reaches its maximum, don't add comma & space  */
		if (comb[0] != (10 - n) + '0')
			ft_putstr(", \n");
		return ;
	}
	/*  digit <= max dyal kola curr_pos  */
	while (digit <= 10 - (n - curr_pos))
	{
		comb[curr_pos] = digit + '0';
		backtrack(comb, n, curr_pos + 1, digit + 1);
		digit++;
	}
}

void	ft_print_combn(int n)
{
	char	comb[10];

	if (n > 0 && n < 10)
	{
		backtrack(comb, n, 0, 0);
	}
	return ;
}
