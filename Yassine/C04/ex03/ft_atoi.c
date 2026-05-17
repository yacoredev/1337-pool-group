/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaadi <ybaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 18:11:13 by ybaadi            #+#    #+#             */
/*   Updated: 2026/05/13 13:18:25 by ybaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
    isspace()
        checks for white-space characters. In the "C" and "POSIX" locales, these are:
        space (' '), form-feed ('\f'), newline ('\n'), carriage return  ('\r'),
        horizontal tab ('\t'), and vertical tab ('\v').

    Sequential Logic of atoi: 
        Spaces --> Signs --> Digits
*/
int     ft_atoi(char *str)
{
    int     i;
    int     sign;
    int     result;

    i = 0;
    sign = 1;
    result = 0;
    // skip whitespaces gher li flbdya
    while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
    {
        i++;
    }
    
    /*
        Handle signs (arbitrary amount).
        mora whitespaces darori khas l9a sign + or -  (or a number)
        ila mal9ithomch return 0
    */
    while (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
        {
            sign *= -1;
        }
        i++;
    }

    /*
        ila l9it mora signs mtab3in chi7aja mn gher ra9m return 0.
        w m3a l9a char mora numbers machi number reja3 lhsab mn tma.
    */
    while (str[i] && str[i] >= '0' && str[i] <= '9')
    {
        result = (result * 10) + (str[i] - '0');
        i++;
    }
    return (result * sign);
}

/*
#include <stdio.h>
int     main(void) {
    
    printf("Calling ft_atoi(\"0\");                     | Expected = 0          | Result = %d\n",ft_atoi("0"));
	printf("Calling ft_atoi(\"-0\");                    | Expected = 0          | Result = %d\n",ft_atoi("-0"));
	printf("Calling ft_atoi(\"42\");                    | Expected = 42         | Result = %d\n",ft_atoi("42"));
	printf("Calling ft_atoi(\"-42\");                   | Expected = -42        | Result = %d\n",ft_atoi("-42"));
	printf("Calling ft_atoi(\"42        --\");          | Expected = 42         | Result = %d\n",ft_atoi("42        --"));
	printf("Calling ft_atoi(\"       ++42\");           | Expected = 42         | Result = %d\n",ft_atoi("       +42"));
	printf("Calling ft_atoi(\"       -+--42\");         | Expected = -42        | Result = %d\n",ft_atoi("       -+--42"));
	printf("Calling ft_atoi(\"       ---42AbuDhabi\");  | Expected = -42        | Result = %d\n",ft_atoi("       ---42AbuDhabi"));
	printf("Calling ft_atoi(\"       ---42Abu-Dhabi\"); | Expected = -42        | Result = %d\n",ft_atoi("       ---42Abu-Dhabi"));
	printf("Calling ft_atoi(\"2147483647\");            | Expected = 2147483647 | Result = %d\n",ft_atoi("2147483647"));
	printf("Calling ft_atoi(\"---2147483647\");         | Expected = -2147483647| Result = %d\n",ft_atoi("---2147483647"));
	printf("Calling ft_atoi(\"2147483648\");            | Expected = -2147483648| Result = %d\n",ft_atoi("2147483648"));
	printf("Calling ft_atoi(\"Abu-Dhabi 42\");          | Expected = 0          | Result = %d\n",ft_atoi("Abu_Dhabi 42"));
	printf("Calling ft_atoi(\"\");                      | Expected = 0          | Result = %d\n",ft_atoi(""));

    return (0);
}
*/