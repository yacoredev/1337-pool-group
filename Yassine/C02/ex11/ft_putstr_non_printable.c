/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaadi <ybaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 00:29:59 by ybaadi            #+#    #+#             */
/*   Updated: 2026/06/11 11:55:30 by ybaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
/*
    Whitespaces:
    '\t' (horizontal tab) = (TAB)
    '\n' (new line)       = (ENTER)
    '\v' (vertical tab)   = (SHIFT+ENTER)
    '\f' (form feed)
    '\r' (carriage return) = (Home)
    ' '  (SPACE)      <-- hada bo7do li printable

    -------------------------------------------------

    Number representation in any base:

    number = (number / base) * base + (number % base)

    quotient  = number / base
    remainder = number % base

    0 <= remainder < base

    -------------------------------------------------

    (255)10 = (FF)16 = (11111111)2

    fl binary 1byte kanmtloh b 8 digits
    exp: 01001101

    f decimal 1byte kanmtloh b 3 digits
    exp: 255 or 128 or 041 ...

    fl hexa 1byte kanmtloh b 2 digits
    exp: FF or 8C or 7F ...
    (y3ni kol 4bits = digit f hexa)

    3lach kansta3mlo hex digits?
    7it 1 hex digit = 4 bits
    chi li kaykhli l9ira2a mn memory sahla

    1byte = 8 digits(bin) = 3 digits(dec) = 2 digits(hex)
*/

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void    ft_print_hexa(unsigned char c)
{
    char    *hexaBAse = "0123456789abcdef";

    /*
        7na hna m7tajin nmtlo 1byte bl hexa (2digits)
        exp: c = 127 --> 127 / 16 = 7  --> h[index 7] = 7
                         127 % 16 = 15 --> h[index 15] = f

        bach nkhraj digit lwl fl hexa
    */
    ft_putchar(hexaBAse[c/16]);
    /*
        bach nkhraj digit tani fl hexa
    */
    ft_putchar(hexaBAse[c%16]);
}

int     ft_str_is_printable(char c)
{
    if (c >= ' ' && c <= '~')
    {
        return (1);
    }
    return (0);
    // return (c >= ' ' && c <= '~');
}

void    ft_putstr_non_printable(char *str)
{
    int     i;

    i = 0;
    while (str[i])
    {
        if (ft_str_is_printable(str[i]))
        {
            ft_putchar(str[i]);
        }
        else
        {
            /*
                ila makanch character printable kanprinti value dyalo ka hexadecimal
                mnsbo9 b backslash
                Imp: \ bo7dha kat3tabr "Escape Character" y3ni makat3tabrch next char
            */
            ft_putchar('\\');
            ft_print_hexa(str[i]);
        }
        i++;
    }
}

/*
methode 2:
void    ft_putstr_non_printable(char *str)
{
    char  *hexaBase = "0123456789abcdef";
    int   firstDigit;
    int   secondDigit;

    while (*str)
    {
        if (*str >= ' ' && *str <= '~')
        {
        write(1, str, 1);
        }
        else
        {
        write(1, "\\", 1);

        firstDigit = *str / 16;
        write(1, &hexaBase[firstDigit], 1);

        secondDigit = *str % 16;
        write(1, &hexaBase[secondDigit], 1);
        }
        str++;
    }
}
*/

int     main(void)
{
    char s[] = "Coucou\ntu vas\r bien ?\n";     // {.., u, \n, t,..}

    ft_putstr_non_printable(s);

    return (0);
}