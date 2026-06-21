/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaadi <ybaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 22:44:26 by ybaadi            #+#    #+#             */
/*   Updated: 2026/06/18 12:28:31 by ybaadi           ###   ########.fr       */
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

/*
	Swap only the pointers (virtual addresses), not the actual strings in memory.

	(char **) is not a container — it's just a pointer, it needs to point to
	something that already exists.
	It doesn't hold anything itself — it just says "go look over there."

	char *arr[] = {"a", "b", "c"};  // the actual stuff exists here
	char **param = arr;				// NOW param points to something real
*/
void	ft_sort_params(int ctr, char **param)
{
	char	*swap;
	int		change;
	int		i;
	int		j;

	i = 0;
	/* had outer loop ghir bach nsaghar l'etaps, (nkhraj akhir param kbir li t7at blasto) */
	while (i < ctr - 1)
	{
		change = 0;
		j = 1;
		/* kol mra kan9ssar l'iterval b i */
		while (j < ctr - i - 1)
		{
			/* if strcmp return positive value this means: the first str is greater than next str

				param[0][0] == character	--> type: char
				param[0] == address			--> type: char *
			*/
			if (ft_strcmp(param[j], param[j + 1]) > 0)
			{
				swap = param[j];
				param[j] = param[j + 1];
				param[j + 1] = swap;
				change = 1;
			}
			j++;
		}
		if (change == 0)	break;
		i++;
	}
	ft_print_param(ctr, param);
}

int		main(int argc, char **argv)
{
	ft_sort_params(argc, argv);
	return (0);
}
