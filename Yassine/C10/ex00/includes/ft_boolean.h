/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaadi <ybaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 17:19:12 by ybaadi            #+#    #+#             */
/*   Updated: 2026/07/01 01:01:42 by ybaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

#include <unistd.h>
#include <fcntl.h>

#define SIZE 4096

#define MISS_MSG "File name missing.\n"
#define ARGS_MSG "Too many arguments.\n"
#define ERROR_MSG "Cannot read file.\n"

#define	SUCCESS 0
#define FAILURE 1

typedef int t_bool;

t_bool	ft_checkfile(char *filename, char *buff, int *fd, int *ret);
t_bool	ft_display(char *buff, int size, int fd, int ret);

#endif