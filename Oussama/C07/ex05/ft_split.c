/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oussama <oussama@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 15:30:49 by oussama           #+#    #+#             */
/*   Updated: 2026/06/30 22:55:10 by oussama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_separator(char c, char *sep)
{
	int	i;

	i = 0;
	while (sep[i] != '\0')
	{
		if (c == sep[i])
			return (1);
		i++;
	}
	return (0);
}

char	**free_all(char **arr, int i)
{
	while (i >= 0)
	{
		free(arr[i]);
		i--;
	}
	free(arr);
	return (NULL);
}

char	*ft_extract_word(char *str, char *charset, int *w_len)
{
	char	*new_word;
	int		len;
	int		i;

	len = 0;
	while (str[len] && !(is_separator(str[len], charset)))
		len++;
	*w_len = len;
	new_word = malloc((len + 1) * sizeof(char));
	if (new_word == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_word[i] = str[i];
		i++;
	}
	new_word[i] = '\0';
	return (new_word);
}

int	ft_count_words(char *str, char *charset)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && is_separator(*str, charset))
			str++;
		if (*str)
		{
			count++;
			while (*str && !(is_separator(*str, charset)))
				str++;
		}
	}
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	char	**arr;
	int		arr_len;
	int		w_len;
	int		i;

	arr_len = ft_count_words(str, charset);
	arr = malloc((arr_len + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	i = 0;
	w_len = 0;
	while (*str)
	{
		while (*str && is_separator(*str, charset))
			str++;
		if (*str)
			break ;
		arr[i] = ft_extract_word(str, charset, &w_len);
		if (arr[i] == NULL)
			return (free_all(arr, i));
		str += w_len;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

/*int	main()
{
	char	**res;
	int		i;

	res = ft_split(" 1  33  7 ", " ");
	if (res == NULL)
		printf("faild");
	else
	{
	i	 = 0;
		while (res[i] != NULL)
		{
			printf("%s", res[i]);
			i++;
		}
	}
	printf("\n");
	free(res);
	res = NULL;
	return (0);
}*/
