/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaadi <ybaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 10:15:28 by ybaadi            #+#    #+#             */
/*   Updated: 2026/06/23 12:45:16 by ybaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int     ft_strlen(char *str)
{
    int     index;

    index = 0;
    while (str[index] != '\0')
    {
        index++;
    }
    return (index);
}

/*
    stock points to a single struct.

    function receives:
        stock -> t_stock_str *
    access:
        stock->elem
*/
void    ft_strcpy(t_stock_str *stock, char *str)
{
    int     i;

    i = 0;
    while(str[i] != '\0')
    {
        stock->copy[i] = str[i];
        i++;
    }
	stock->copy[i] = '\0';
}

/*
    Free all allocated copies, then free
    the struct array itself.

    stock points to the first element of
    an array of structs.

	ah stock pointer, but fach kandir stock[i] == *(stock + i) ky3tini
	actual structure number i type dyalo t_stock_str
	machi bhal (stock + i) kay3tini gher pointer 3la structure number i

    function receives:
        stock -> t_stock_str *
    access:
        stock[i].elem
*/
void	ft_free_mem(t_stock_str *stock, int curr_sk)
{
	int		i;

	i = 0;
	while (i < curr_sk)
	{
		free(stock[i].copy);
		i++;
	}
	free(stock);
}

// t_stock_str = struct s_stock_str
struct s_stock_str *ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str *stock;

	/* 	malloc kydir: memory allocation larray dyal structures.
		sizeof(t_stock_str): Kay7seb ch7al mn byte katakhd structure wa7da.
		each element mn had array of structure: 24 bytes			* ac+1 = 96 bytes
			int size;       // 4 bytes
			padding;		// 4 bytes (dyal alignment padding bach compiler y9ad mem)
			char *str;      // 8 bytes (Pointer)
			char *copy;     // 8 bytes (Pointer)
	*/
	stock = (t_stock_str *)malloc((ac + 1) * sizeof(t_stock_str));
	if (stock == NULL)
		return (NULL);

	i = 0;
	while (i < ac)
	{
		/*
			stock: pointer to first struct
			stock[i]: actual structure

			(.)  -> used with a struct variable
			(->) -> used with a pointer to struct

			ptr->x == (*ptr).x		stock[i].str == (*(stock+i)).str
		*/
		stock[i].size = ft_strlen(av[i]);

		stock[i].str = av[i];

		stock[i].copy = (char *)malloc(stock[i].size + 1);
		if (stock[i].copy == NULL)
		{
			// free copys strings and Array of stock
			ft_free_mem(stock, i);
			return (NULL);
		}
		/*
			&stock[i] == stock + i	address of struct nbr i		(pointer)
			av[i] == &av[i][0]		address of param nbr i		(pointer)
		*/
		ft_strcpy(stock + i, av[i]);
		i++;
	}
	stock[i].str = 0;	// or '\0' or NULL
	return (stock);
}