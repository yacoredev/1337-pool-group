/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaadi <ybaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 17:19:12 by ybaadi            #+#    #+#             */
/*   Updated: 2026/05/18 18:20:32 by ybaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
// n9do nktbo any name but mn a7san b7al name of file bach matw93 collision m3a header akhor
# define FT_BOOLEAN_H

// main.c or any file includes "ft_boolean.h" -> ft_boolean.h includes "unistd.h"
#include <unistd.h>

// macro declaration
#define EVEN_MSG "I have an even number of arguments.\n"
#define ODD_MSG "I have an odd number of arguments.\n"

/*
	macro with arguments.
	b7al function sghira, preprocessor howa li kaybdal EVEN(nbr)
	bdak lexpression 9bal compilation. (macro howa text replacement)
	hadchi kaml macros. y3ni lcompiler aslan makaychofch EVEN(nbr) innma
	kaychof lexpression lach tremplacat
*/
#define	EVEN(nbr) ((nbr) % 2 == 0) // DARORI mn parentheses (nbr) 7it y9d ykon nbr = a + b

#define	SUCCESS 0
#define TRUE 1
#define FALSE 0

typedef int t_bool;

/*
	function declaration:
	header kaydeclari had prototypes hna wakha kaynin f main bach ay file
	dar include lhad lheader y9dr ywsal lihom
*/
void	ft_putstr(char* str);
t_bool	ft_is_even(int nbr);

#endif

/*
Header file:
   Contains shared declarations and definitions.

Macro:
   Text replacement done before compilation.

Typedef:
   Creates a new name for an existing type.

Include guard:
   Prevents a header file from being included multiple times.

Boolean simulation:
   Creating TRUE/FALSE behavior manually in C.
*/