/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_str.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaadi <ybaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 10:19:08 by ybaadi            #+#    #+#             */
/*   Updated: 2026/05/16 16:32:31 by ybaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STOCK_STR_H
# define FT_STOCK_STR_H

# include <stdlib.h>

typedef struct s_stock_str
{
	int		size;
	char	*str;
	char	*copy;
}	t_stock_str;

struct	s_stock_str *ft_strs_to_tab(int ac, char **av);
int     ft_strlen(char *str);
void    ft_strcpy(t_stock_str *stock, char *str);
void	ft_free_mem(t_stock_str *stock, int curr_sk);

#endif