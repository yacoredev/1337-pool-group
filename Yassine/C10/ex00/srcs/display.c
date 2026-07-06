/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispaly.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaadi <ybaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 01:04:27 by ybaadi            #+#    #+#             */
/*   Updated: 2026/07/01 01:06:59 by ybaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_boolean.h"

t_bool	ft_display(char *buff, int size, int fd, int ret)
{
	do
	{
		buff[ret] = '\0';		// index kybda mn 0
		write(1, buff, ret);	// count kaybda mn 1
	} while ((ret = read(fd, buff, size - 1)) > 0);

	if (ret == -1)
	{
		write(2, ERROR_MSG, 18);
		close(fd);
		return (FAILURE);
	}
	return (SUCCESS);
}