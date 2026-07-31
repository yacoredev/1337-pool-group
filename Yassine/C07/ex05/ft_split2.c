#include <stdio.h>
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
*//*
void	create_splits_words(char *str, char *charset, char **arr, char *words)
{
	int		i;
	int		start_of_word;
	int		word_idx;

	i = 0;
	j = 0;
	word_idx = 0;
	while (str[i])
	{
		if (!is_sep(str[i], charset) && (i == 0 || is_sep(str[i - 1], charset)))
		{
			arr[word_idx++] = &words[start_of_word];
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
}*/

int	ft_wordlen(char *str, int *start, char *seps)
{
	int	len;
	int	i;

	len = 0;
	i = *start;
	while (is_sep(str[i], seps))
		i++;
	*start = i;
	while (str[i] && !is_sep(str[i], seps))
	{
		len++;
		i++;
	}
	return (len);
}

void	ft_put_word(char *buff, int	*start, char *str, char *seps)
{
	int	i;
	int	j;

	j = 0;
	i = *start;
	while (str[i] && !is_sep(str[i], seps))
	{
		buff[j] = str[i];
		j++;
		i++;
	}
	buff[j] = '\0';
	*start = i;
}

/*
   count how many words exist in str using seps as separators
   and return length of all characters (not seps)

   if the current elem != seps and, previous elem == sep or start of str
   increment count++
*/
int	ft_count_words(char *str, char *seps)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (!is_sep(str[i], seps) && (i == 0 || is_sep(str[i - 1], seps)))
			count++;
		i++;
	}
	return (count);
}

/*
function: splits a string of character depending on charset.
each character in charset is separator of str
return array of pointers to each word, last element = NULL
malloc(chars_len + count_words) 'count_words' here for \0 of each word
*/
char	**ft_split(char *str, char *charset)
{
	char	**arr;
	char	*words;
	int		word_len;
	int		start_word;
	int		count_words;

	count_words = ft_count_words(str, charset);
	if (count_words == 0)
	{
		arr = malloc(sizeof(char *));
		*arr = NULL;
		return (arr);
	}
	arr = malloc((count_words + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);

	word_len = 0;
	start_word = 0;
	int i = 0;
	while (i < count_words)
	{
		word_len = ft_wordlen(str, &start_word, charset);
		arr[i] = malloc((word_len + 1) * sizeof(char));
		if (arr[i] == NULL)
			return (NULL);
		ft_put_word(arr[i], &start_word, str, charset);
		i++;
	}
	arr[i] = NULL;
	return(arr);

/*

	words = (char *)malloc(chars_len + count_words);
	if (words == NULL)
	{
		free (arr);
		return (NULL);
	}
	create_splits_words(str, charset, arr, words);
	return (arr);
*/
}
int	main(int ac, char **av)
{
	if (ac == 3)
	{
		char	**arr = ft_split(av[1], av[2]);

		for(int i = 0; arr[i]; i++)
			printf("%s\n", arr[i]);

		if (!*arr)
			printf("NULL");
	}
}
