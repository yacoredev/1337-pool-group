/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaadi <ybaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 21:30:59 by ybaadi            #+#    #+#             */
/*   Updated: 2026/06/21 17:27:34 by ybaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/* check if character exists in separators string */
int	is_sep(char c, char *seps)
{
	int		i;

	i = 0;
	while (seps[i] && c != seps[i])
	{
		i++;
	}
	if (seps[i] == '\0')
		return (0);
	return (1);
}

/*
   if the current elem != seps and, previous elem == sep or start of str:
   Register its address
*/
void	create_splits_words(char *str, char *charset, char **arr, char *words)
{
	int		i;
	int		j;
	int		word_idx;

	i = 0;
	j = 0;
	word_idx = 0;
	while (str[i])
	{
		if (!is_sep(str[i], charset) && (i == 0 || is_sep(str[i - 1], charset)))
		{
			arr[word_idx++] = &words[j];
			while (str[i] && !is_sep(str[i], charset))
			{
				words[j] = str[i];
				i++;
				j++;
			}
			words[j++] = '\0';
		}
		else
			i++;
	}
	arr[word_idx] = NULL;
}

/*
   count how many words exist in str using seps as separators
   and return length of all characters (not seps)

   if the current elem != seps and, previous elem == sep or start of str
   increment count++
*/
int	ft_count_words(char *str, char *seps, int *len)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (!is_sep(str[i], seps) && (i == 0 || is_sep(str[i - 1], seps)))
		{
			count++;
		}
		if (!is_sep(str[i], seps))
		{
			(*len)++;
		}
		i++;
	}
	return (count);
}

/*
function: splits a string of character depending on charset.
each character in charset is separator of str
return array of pointers to each word, last element = NULL
*/
char	**ft_split(char *str, char *charset)
{
	char	**arr;
	char	*words;
	int		chars_len;
	int		count_words;

	chars_len = 0;
	count_words = ft_count_words(str, charset, &chars_len);
	arr = (char **)malloc((count_words + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	words = (char *)malloc(chars_len + count_words);
	if (words == NULL)
		return (NULL);
	create_splits_words(str, charset, arr, words);
	return (arr);
}
