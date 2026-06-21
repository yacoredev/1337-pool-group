/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaadi <ybaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 12:56:41 by ybaadi            #+#    #+#             */
/*   Updated: 2026/06/20 18:30:27 by ybaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int     ft_strlen(char *str);
int     is_base_valid(char *base);
int     ft_atoi_base(char *str, char *base);

/* Convert a decimal number to another base and put it in  buff (result) */
void    convert_base_to(char *base, char *buff, int base_nbr, long divi)
{
    int     rest;
    int     next_idx;

    /*
        If divi is bigger than one digit in this base,
        keep dividing.

        example:
        9  >= 10 (false)  =>  9 < 10  valide digit (9) in decimal
        14 >= 16 (false)  =>  14 < 16 valide digit (E) in hexa
        1  >= 2  (false)  =>  1 < 2   valide digit (1) in binary
    */
    if (divi >= base_nbr)
    {
        convert_base_to(base, buff, base_nbr, divi / base_nbr);
    }

    rest = divi % base_nbr;
    next_idx = ft_strlen(buff);
    buff[next_idx] = base[rest];
    buff[next_idx + 1] = '\0';
}

void    ft_putnbr_base(int nbr, char *base, char *buff)
{
    long    divi;
    int     base_nbr;

    base_nbr = ft_strlen(base);

    if (nbr == 0)
    {
        buff[0] = base[0];
        buff[1] = '\0';
        return;
    }
    divi = (long)nbr;

    if (divi < 0)
    {
        buff[0] = '-';
        buff[1] = '\0';
        divi *= -1;
    }
    convert_base_to(base, buff, base_nbr, divi);
}

int     nbr_len(char *base_to, int number)
{
    int     nbr_base;
    int     len;
    long    nb;

    nb = (long)number;
    len = 0;
    // if number is 0 or negative add place for it in start.
    // dema fach tbghi tchange sign dyal nbr fkar f (int_min * -1) makaynach f int
    if (number <= 0)
    {
        nb *= -1;
        len++;
    }
    nbr_base = ft_strlen(base_to);

    // loop 7ta nwslo l nb == 0 (stop)
    while (nb > 0)
    {
        nb /= nbr_base;
        len++;
    }
    return (len);
}

char    *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
    int     number;
    char    *result;

    if (is_base_valid(base_from) < 2 || is_base_valid(base_to) < 2)
        return (NULL);

    // number li stkhrajt mn 'nbr' m7wal mn base_to -> decimal
    number = ft_atoi_base(nbr, base_from);

    // allocate size bl7ajm dyal nbr li ghan7wlo lih + '\0'
    result = (char *)malloc(nbr_len(base_to, number) + 1);
    if (result == NULL)
    {
        return (NULL);
    }
    *result = '\0';

    // convert mn decimal l base_to and put it in 'result'
    ft_putnbr_base(number, base_to, result);
    return (result);
}