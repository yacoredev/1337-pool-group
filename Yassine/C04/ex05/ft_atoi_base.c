/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaadi <ybaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 16:23:03 by ybaadi            #+#    #+#             */
/*   Updated: 2026/05/13 13:17:36 by ybaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    Conversion Logic, Base to Decimal:
    
       - RULE: MULTIPLY each digit by (Base ^ Position).
       - ORDER: Positions start from 0 on the right.
       - Example (1010 to Decimal):
            (1 * 2^3) + (0 * 2^2) + (1 * 2^1) + (0 * 2^0)
            = 8 + 0 + 2 + 0 -> Result: 10
*/

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

int     is_base_valid(char *base)
{
    int     i;
    int     j;

    i = 0;
    while (base[i])
    {
        if (base[i] == '-' || base[i] == '+' || base[i] == ' ' 
        || (base[i] >= '\t' && base[i] <= '\r'))
        {
            return (0);
        }
        
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
    return (1);
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
    // Harf makaynch f base (asln talbin f subject, base maykonoch - or +)
    return (-1);
}

unsigned int    ft_convert_base_ten(char *str, int i, int base_nbr, char *base)
{
    unsigned int    result;
    int             idx_base;
    
    result = 0;
    while (str[i])
    {
        idx_base = check_and_getidxbase(str[i], base);
        if (idx_base == -1)
        {
            break;
        }
        result = (result * base_nbr) + idx_base;
        i++;
    }
    return (result);
}

int     ft_atoi(char *str, char *base, int base_nbr)
{
    /*
        unsigned hna bach n9dr nkhzan fih 2147483648 li makaynach f int,
        but ila drbto f -1 ghaywli valide f int (-2147483648)
    */
    unsigned int    result;
    int             sign;
    int             i;

    sign = 1;
    i = 0;
    while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
    {
        i++;
    }

    while (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
        {
            sign *= -1;
        }
        i++;
    }
    
    result = ft_convert_base_ten(str, i, base_nbr, base);
    return (int)(result * sign);
}

int     ft_atoi_base(char *str, char *base)
{
    int     base_nbr;

    // return 0 if there's an invalid argument (str_base) see subject
    base_nbr = ft_strlen(base);
    if (!is_base_valid(base) || base_nbr < 2)
    {
        return (0);
    }

    // convert initial portion of the str from specific base to int
    // expected the rule of ft_atoi function
    return (ft_atoi(str, base, base_nbr));
}

/*
#include <stdio.h>
int     main(void) {
    
	char	*dec = "0123456789";
	char	*hex = "0123456789abcdef";
	char	*oct = "012345678";
	char	*bin = "01";
    char    *new = "poneyvif";
    
    // convert a string number from a given base to int
    // works like ft_atoi (spaces, signs, stop on invalid char)
    printf("===== Convert any Base to Decimal =====\n");
    printf("\nbase[%d] (%s)\nDecimal: %d\n", ft_strlen(dec), dec, ft_atoi_base_ten("  --2147483648", dec));
    printf("\nbase[%d] (%s)\nDecimal: %d\n", ft_strlen(hex), hex, ft_atoi_base_ten("  --4acf8Gu-mm", hex));
    printf("\nbase[%d] (%s)\nDecimal: %d\n", ft_strlen(oct), oct, ft_atoi_base_ten("  --2147488a48", oct));
    printf("\nbase[%d] (%s)\nDecimal: %d\n", ft_strlen(bin), bin, ft_atoi_base_ten("  --0110183648", bin));
    printf("\nbase[%d] (%s)\nDecimal: %d\n", ft_strlen(new), new, ft_atoi_base_ten("  --nfv8vvpo24", new));

    return (0);
}
*/