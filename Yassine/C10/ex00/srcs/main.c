/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaadi <ybaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 01:04:40 by ybaadi            #+#    #+#             */
/*   Updated: 2026/07/01 01:06:52 by ybaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_boolean.h"

/*
	jrab ga3 cases, l3b b permissions, empty file ...
	dir > file.txt  bach tms7 7ta \n li katb9a fih ywli 0byte
*/
int		main(int argc, char **argv)
{
	/*
		sIZE:
		1024
		4096
		8192
		kolhom vailde, kaysta3mlo hado bzaf 7it hya even nbrs 2^..
		kayt3aml m3aha CPU mzyan
	*/
	char	buff[SIZE];
	int		fd;
	int		ret;

	if (argc < 2)
	{
		write(2, MISS_MSG, 19);
		return (FAILURE);
	}
	else if (argc > 2)
	{
		write(2, ARGS_MSG, 20); // "Too many arguments.\n"
		return (FAILURE);
	}

	if (ft_checkfile(argv[1], buff, &fd, &ret))
		return (FAILURE);

	if (ft_display(buff, SIZE, fd, ret))
		return (FAILURE);

	close(fd);
	return (SUCCESS);
}