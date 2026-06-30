/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oussama <oussama@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 15:56:26 by oussama           #+#    #+#             */
/*   Updated: 2026/06/28 19:44:45 by oussama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

int	ft_is_forbidden(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	else if (c == '+' || c == '-')
		return (1);
	return (0);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (ft_is_forbidden(base[i]))
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (1);
}

int	get_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *nbr, char *base)
{
	int	len;
	int	sign;
	int	res;
	int	value;

	len = ft_strlen(base);
	while ((*nbr >= 9 && *nbr <= 13) || *nbr == 32)
		nbr++;
	sign = 1;
	while (*nbr == '+' || *nbr == '-')
	{
		if (*nbr == '-')
			sign = -sign;
		nbr++;
	}
	res = 0;
	while (*nbr != '\0')
	{
		value = get_index(*nbr, base);
		if (value == -1)
			break ;
		res = (res * len) + value;
		nbr++;
	}
	return (res * sign);
}
