/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaadi <ybaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 22:44:26 by ybaadi            #+#    #+#             */
/*   Updated: 2026/05/11 13:38:20 by ybaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}


void    ft_putstr(char *str)
{
	int     i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	ft_putchar('\n');
}

void	ft_print_param(int size, char **param)
{
	int	i;

	i = 1;
	while (i < size)
	{
		ft_putstr(param[i]);
		i++;
	}
}

int     ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

// Swap only the pointers (virtual addresses), not the actual strings in memory.
void	ft_sort_params(int ctr, char **param)
{
	char	*swap;
	int		i;
	int		j;

	i = 1;
	while (i < ctr)
	{
		j = i + 1;
		while (j < ctr)
		{
			// if strcmp return positive value this means: the first str is greater than next str
			if (ft_strcmp(param[i], param[j]) > 0)
			{
				swap = param[i];
				param[i] = param[j];
				param[j] = swap;
			}
			j++;
		}
		i++;
	}
	ft_print_param(ctr, param);
}

int		main(int argc, char **argv)
{
	ft_sort_params(argc, argv);
	return (0);
}
