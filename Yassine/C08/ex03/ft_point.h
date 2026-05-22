/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaadi <ybaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 23:22:02 by ybaadi            #+#    #+#             */
/*   Updated: 2026/05/16 16:28:29 by ybaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_POINT_H
# define FT_POINT_H

# include <unistd.h>

// s_point: Hadi s-smiya daakhilya dyal struct (Struct Tag)
// s_ (kat3ni Structure)
typedef struct s_point
{
	int	x;
	int	y;
// t_point: Hadi smya jdida (Alias) li kankhdmo biha direct f
// lcode mlli kandeclariw variable (bhal t_point p;).
// t_ (kat3ni Type)
}	t_point;

void	set_point(t_point *point);

#endif