/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaadi <ybaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 01:04:31 by ybaadi            #+#    #+#             */
/*   Updated: 2026/07/01 01:54:56 by ybaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_boolean.h"

t_bool	ft_checkfile(char *filename, char *buff, int *fd, int *ret)
{
	*fd = open(filename, O_RDONLY);
	if (*fd == -1)
	{
		write(2, ERROR_MSG, 18); // "Cannot read file.\n"
		return (FAILURE);
	}

	/*
		Keyboard/File -> Kernel -> buf -> returns number of bytes copied
		kol mra kay3mr buf kytprinta w y3awd ytktb fo9o
		Kernel howa likay3rf fin wslna fl9ira2a bl File Descriptor
		kola FD 3ndo File Offset (current place in file)
		read makat9rach byte dyal '\0'
	*/
	*ret = read(*fd, buff, SIZE - 1);
	if (!*ret)
	{
		write(2, ERROR_MSG, 18);
		close(*fd);
		return (FAILURE);
	}
	return (SUCCESS);
}