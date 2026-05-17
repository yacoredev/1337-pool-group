/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaadi <ybaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 18:40:00 by ybaadi            #+#    #+#             */
/*   Updated: 2026/05/10 18:40:08 by ybaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_putchar(char c)
{
        write(1, &c, 1);
}

void    ft_rev_params(int count, char **param)
{
        char    *ptr_param;
        int     i;
        int     j;

        j = count - 1;
        while (j > 0)
        {
                ptr_param = param[j];
                i = 0;
                while (ptr_param[i])
                {
                        ft_putchar(ptr_param[i]);
                        i++;
                }
                ft_putchar('\n');
                j--;
        }
}

int     main(int argc, char *argv[])
{
        ft_rev_params(argc, argv);
        return (0);
}
