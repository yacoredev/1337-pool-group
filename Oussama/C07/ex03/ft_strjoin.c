/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oussama <oussama@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 22:11:43 by oussama           #+#    #+#             */
/*   Updated: 2026/06/18 21:21:04 by oussama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*s_str(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		*dest = src[i];
		dest++;
		i++;
	}
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*s;
	char	*curr;
	int		len;
	int		i;

	i = -1;
	len = 0;
	while (i++ < size - 1)
		len += ft_strlen(strs[i]);
	if (size > 1)
		len += ft_strlen(sep) * (size - 1);
	s = malloc((len + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	curr = s;
	i = 0;
	while (i < size)
	{
		curr = s_str(curr, strs[i]);
		if (i < size - 1)
			curr = s_str(curr, sep);
		i++;
	}
	*curr = '\0';
	return (s);
}

/*int	main(void)
{
	char *strs[] = {"Ou", "ss", "baK"};
	char *s = ft_strjoin(3, strs, " | ");
	printf("%s\n", s);
	free(s);
	s = NULL;
	return (0);
}*/
