/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaadi <ybaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 16:43:54 by ybaadi            #+#    #+#             */
/*   Updated: 2026/05/16 09:23:45 by ybaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ifndef = if not defined
// Starts a Header Guard
#ifndef FT_H
# define FT_H

// defines the prototypes of the functions that can be called by this header
void	ft_putchar(char c);
void	ft_swap(int *a, int *b);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);

// Ends the Header Guard
#endif

/* ************************************************************************** */
/*                                                                            */
/*                            WHAT IS INCLUDE GUARD ?                         */
/*                                                                            */
/* ************************************************************************** */
/*
  Include guard = protection system for header files.
  exp bach maydarch double include:
  #include "ft.h"
  #include "ft.h"

  exp: main.c includes "ft.h"	and		utils.c includes "ft.h"
  7tal hna mzyan but ila drt fl
  main.c:	#include "ft.h"
		    	#include "utils.h"
  daba flcompilation, ghayw9a3 double include 7it utils.h minclude ft.h
  hna include guard kayw9af had duplicate declarations

  Goal:
  Prevent the same header file from being included multiple times.

  Why is this important?
  Because multiple includes can cause:
  - redefinition errors
  - duplicate declarations
  - compilation problems
*/

/*
  First time compiler enters this file:
  FT_H does not exist yet.
  So condition is TRUE.
*/

/*
  FIRST INCLUDE:

    FT_H does not exist
    => enter file
    => define FT_H
    => read content

  SECOND INCLUDE:

    FT_H already exists
    => skip entire file
*/
