/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaadi <ybaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 12:56:36 by ybaadi            #+#    #+#             */
/*   Updated: 2026/06/20 17:18:20 by ybaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

// BASE: must not contain the whitespaces or (-, +), nor repeated letters
// and its size must be larger than 2.
int     is_base_valid(char *base)
{
    int     i;
    int     j;

    i = 0;
    while (base[i])
    {
        if (base[i] == ' ' || (base[i] >= '\t' && base[i] <= '\r'))
            return (0);
        if (base[i] == '-' || base[i] == '+' )
            return (0);

        j = i + 1;
        while (base[j])
        {
            if (base[i] == base[j])
            {
                return (0);
            }
            j++;
        }
        i++;
    }
    return (i);
}

int     check_and_getidxbase(char c, char *base)
{
    int     i;

    i = 0;
    while (base[i])
    {
        if (c == base[i])
        {
            return (i);
        }
        i++;
    }
    // Harf makaynch f base (talbin f subject, base maykonoch - or +)
    return (-1);
}

/*
    convert initial portion of the str from specific base to int
    expected the rule of ft_atoi function

    formula:    result = result * base + digit

    example:    147    => mathematique: 1 * 10² + 4 * 10¹ + 7 * 10⁰

    result = 0  * 10 + 1 = 1
    result = 1  * 10 + 4 = 14
    result = 14 * 10 + 7 = 147

    The same applies to converting any base to decimal.
*/
int     ft_atoi_base(char *str, char *base)
{
    /*
        unsigned hna bach n9dr nkhzan fih 2147483648 li makaynach f int,
        but ila drbto f -1 flakhar ghaywli valide f int (-2147483648)
        w hasab subject maghadich y3tiwna number kharj range dyal int
    */
    unsigned int    result;
    int             base_nbr;
    int             idx_nbr;
    int             sign;
    int             i;

    i = 0;
    while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
        i++;

    sign = 1;
    while (str[i] == '+' || str[i] == '-')
    {
        if (str[i++] == '-')
            sign *= -1;
    }

    base_nbr = ft_strlen(base);
    result = 0;
    while (str[i])
    {
        idx_nbr = check_and_getidxbase(str[i], base);
        if (idx_nbr == -1)
            break;
        result = (result * base_nbr) + idx_nbr;
        i++;
    }
    return ((int)(result * sign));
}