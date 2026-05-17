/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaadi <ybaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 18:10:52 by ybaadi            #+#    #+#             */
/*   Updated: 2026/05/10 18:10:53 by ybaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_params(int count, char **param)
{
	char	*ptr_param;
	int	i;
	int	j;	

	j = 1;
	while (j < count)
	{
		ptr_param = param[j];
		i = 0;
		while (ptr_param[i])
		{
			ft_putchar(ptr_param[i]);
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}

int	main(int argc, char *argv[])
{
	ft_print_params(argc, argv);
	return (0);
}
