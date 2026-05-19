/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaadi <ybaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 11:19:34 by ybaadi            #+#    #+#             */
/*   Updated: 2026/05/17 12:48:37 by ybaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int     is_not_num(char *c)
{
    if (*c < '0' || *c > '9')
    {
        return (1);
    }
    return (0);
}

int     is_not_alpha(char *c)
{
    if ((*c < 'A' || *c > 'Z') &&
        (*c < 'a' || *c > 'z'))
    {
        return (1);
    }
    return (0);
}

void    ft_charupcase(char *letter)
{
    if (*letter >= 'a' && *letter <= 'z')
    {
        *letter -= 32;
    }
}

void    ft_strlowcase(char *str)
{
    int     i;

    i = 0;
    while (str[i])
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 32;
        }
        i++;
    }
}

char    *ft_strcapitalize(char *str)
{
    int     i;

    // methode 1:
    // step 1: transforms all letters to lowercase
    ft_strlowcase(str);

    /* step 2: Capitalizes the first letter of each word
        - capital the first letter
        - if the last character is not letter or a number,
           capital the current letter

        ⚠️​ If I'm relying on capitalizing the following
        character, I can change a character outside
        the string boundaries.
        (also if i check the previous (first) char)
    */
    i = 0;
    while (str[i])
    {
        /* Imp note: hna kon daz l condition li tab3 i == 0 knt ghadi n9ra
           kharj string but first loop maghayw9a3ch hadchi 7it m3a ghaychof
           i == 0 ghaydkhl direct ycapitalizi char (ila kan 7arf)
        */
        if (i == 0 || (is_not_alpha(&str[i - 1]) && is_not_num(&str[i - 1])))
        {
            ft_charupcase(&str[i]);
        }
        i++;
    }

    // methode 2:
    // i = 0;
    // while (str[i])
    // {
    //     /* Imp note: hna kon daz l condition li tab3 i == 0 knt ghadi n9ra
    //        kharj string but first loop maghayw9a3ch hadchi 7it m3a ghaychof
    //        i == 0 ghaydkhl direct ycapitalizi char (ila kan 7arf)
    //     */
    //     if (i == 0 || (is_not_alpha(&str[i - 1]) && is_not_num(&str[i - 1])))
    //     {
    //         ft_charupcase(&str[i]);
    //     }
    //     else if (str[i] >= 'A' && str[i] <= 'Z')
    //     {
    //         str[i] += 32;
    //     }
    //     i++;
    // }

    return (str);
}

/*int     main(void)
{
    char s[] = "hrRT TRE+trR TOOL*mon/tre-eet45eg r7r 7r7 ";

    char *ptr_to_s = ft_strcapitalize(s);
    printf("%s\n", ptr_to_s);

    return (0);
}*/