/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oussama <oussama@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 18:54:21 by oussama           #+#    #+#             */
/*   Updated: 2026/06/29 17:03:08 by oussama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);
int	check_base(char *base);
int	ft_atoi_base(char *nbr, char *base);

int	ft_nbrlen_base(int nbr, char *base)
{
	int		len;
	int		base_len;
	long	n;

	n = nbr;
	len = 0;
	if (n <= 0)
	{
		n = -n;
		len++;
	}
	base_len = ft_strlen(base);
	while (n > 0)
	{
		n = n / base_len;
		len++;
	}
	return (len);
}

char	*ft_fill_conv(char *str, char *base, int num, int len)
{
	long	n;
	int		i;
	int		base_len;

	str[len] = '\0';
	n = num;
	if (n == 0)
		str[0] = base[0];
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	base_len = ft_strlen(base);
	i = len - 1;
	while (n > 0)
	{
		str[i] = base[n % base_len];
		n /= base_len;
		i--;
	}
	return (str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		num;
	int		nbr_len;
	char	*conv;

	if (!check_base(base_from) || !check_base(base_to))
		return (NULL);
	num = ft_atoi_base(nbr, base_from);
	nbr_len = ft_nbrlen_base(num, base_to);
	conv = malloc((nbr_len + 1) * sizeof(char));
	if (conv == NULL)
		return (NULL);
	conv = ft_fill_conv(conv, base_to, num, nbr_len);
	return (conv);
}

/*int	main(void)
{
	char	*convert;

	convert = ft_convert_base("1337", "0123456789", "01");
	if (convert == NULL)
		printf("Base invalid\n");
	else
		printf("%s\n", convert);
	free(convert);
	convert = ft_convert_base("\r +-+01010b1", "01", "012346789abcdef");
	if (convert == NULL)
        printf("Base invalid\n");
	else
    	printf("%s\n", convert);
	free(convert);
	convert = ft_convert_base(" -+0a", "0123456789abcdef", "0123456789");
	if (convert == NULL)
        printf("Base invalid\n");
	else
    	printf("%s\n", convert);
	free(convert);
	convert = ft_convert_base("\t +++kk", "01", "0123456789abcdef");
	if (convert == NULL)
        printf("Base invalid\n");
	else
    	printf("%s\n", convert);
	free(convert);
	convert = ft_convert_base("-0", "0123456789", "oussbak");
	if (convert == NULL)
        printf("Base invalid\n");
	else
    	printf("%s\n", convert);
	free(convert);
	convert = NULL;
	return (0);
}*/
