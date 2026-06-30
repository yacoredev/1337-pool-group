/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaadi <ybaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 17:16:09 by ybaadi            #+#    #+#             */
/*   Updated: 2026/06/30 14:52:06 by ybaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// SOLUTION 1
int		is_sep(char c, char *seps)
{
	while(*seps)
	{
		if (c == *seps)
			return (1);
		seps++;
	}
	return (0);
}

/*
	- skip seps
	- check if current char != '\0'
	- first char is first of word (count it)
	- skip current word
*/
int		ft_count_words(char *str, char *charset)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while(str[i])
	{
		while (str[i] && is_sep(str[i], charset))
			i++;

		if (str[i] != '\0')
		{
			count++;
			while (str[i] && !is_sep(str[i], charset))
				i++;
		}
	}
	return(count);
}

/*
	- allocate memory to word
	- put word in it
*/
char	*ft_putword(char *start, char *end)
{
	char	*word;
	int		i;

	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);

	i = 0;
	while (start < end)
	{
		word[i] = *start;
		start++;
		i++;
	}
	word[i] = '\0';
	return (word);
}

/*
	- skip seps in the begening
	- check if current char != '\0'
	- the first char is the first of word (save it's index)
	- move to end of word (save it's index)
	- allocate memory, size of this word and put word in it
	- if one of malloc word fail, free previous word allocation + array of pointer
	=> 25 line exact
*/
void	ft_splitstr(char *str, char *charset, char **ptr_words, int *k)
{
	char	*start;

							/*   bghawk tkhdmha b pointers bach tn9s nbr of lines   */
	while (*str)
	{
		// while (str[i] && is_sep(str[i], charset))
		while (*str && is_sep(*str, charset))
			str++;

		// if (str[i] != '\0')
		if (*str)
		{
			// start = i;		// man7atch start of word hta nt2akad bli char != null and sep. or ret
			start = str;
			// while (str[i] && !is_sep(str[i], charset))
			while (*str && !is_sep(*str, charset))
				str++;
			// end = i;
			// end = start;

			// ptr_words[*k] = ft_putword(str, start, end);
			ptr_words[*k] = ft_putword(start, str);
			if (!ptr_words[*k])
			{
					while (*k > 0)
						free(ptr_words[--(*k)]);
					free(ptr_words);
					return ;
			}
			(*k)++;
		}
	}
}

/*
	- 7seb nbr_words
	- ptr_words --> allocat memory of size: nbr_words + 1
	- allocat word in each element of nbr_words
	- put null in last elemet in ptr_words and return it
*/
char	**ft_split(char *str, char *charset)
{
	char	**ptr_words;
	int		k;

	ptr_words = malloc((ft_count_words(str, charset) + 1) * sizeof(char *));
	if (!ptr_words)
		return (NULL);

	k = 0;
	ft_splitstr(str, charset, ptr_words, &k);

	ptr_words[k] = NULL;
	return (ptr_words);
}

#include <stdio.h>
int		main()
{
	char *str1 = "hello;,amg;dfa,fse,,,,";
	char *str2 = ",,,hello;,amg;dfa,fse,,,";
	char *str3 = ",   hello;,amg;dfa,fse,  ";
	char *str4 = "";
	char *str5 = ",,a";

	char *charset = ";,";

	char **array = ft_split(str1, charset);

	int i = 0;
	while (array[i])
	{
		printf("%s\n", array[i]);
		i++;
	}
	if (array[i] == NULL)
		printf("(NULL)\n");

	while (i >= 0)
		free(array[i--]);
	free(array);
	return (0);
}


/*
// POINTERS (m7taja some repairs)
int		is_sep(char c, char *charset)
{
	while(*charset)
	{
		if(*charset == c)
			return (1);
		charset++;
	}
	return (0);
}

int		ft_count_chars(char *str, char *charset)
{
	int		count;

	count = 0;
	while(*str)
	{
		if (!is_sep(*str, charset))
			count++;
		str++;
	}
	return (count);
}

/*
	if i == 0 or ([i] != sep and [i-1] == sep): this is first of the word
*//*
int		ft_count_words(char *str, char *charset)
{
	int		count;

	count = 0;
	if (!is_sep(*str, charset))
		count++;

	str++;
	while(*str)
	{
		/* I caught the first word *//*
		if (!is_sep(*str, charset) && is_sep(*(str - 1), charset))
		{
			count++;
			while (*str && !is_sep(*str, charset))
				str++;
		}
		else
			str++;
	}
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	char	*array;
	char	**ptr_to_strs;
	char	**result;

	/*
	memory layout:

		*array = {char, char, char}

		array = &array[0]
		*array = char
	*//*
	array = malloc((ft_count_chars(str, charset) + 1) * sizeof(char));
	if (!array)
		return (NULL);

	/*
	memory layout:

		**ptr_to_strs = {char *, char *, char *}

		ptr_to_strs = &ptr_to_strs[0]
		*ptr_to_strs = char *
		**ptr_to_strs = char
	*//*
	ptr_to_strs = malloc((ft_count_words(str, charset) + 1) * sizeof(char *));
	if (!ptr_to_strs)
		return (NULL);
	// hadi knt drtha flwl ghlat fiha (7it ptr_to_strs fih garbage value ba9i ma3tito addr b malloc)
	result = ptr_to_strs;

	/* if the first char isn't sep: save it's address in ptr_to_str *//*
	*array = '\0';
	while(*str)
	{
		if ((!*array && !is_sep(*str, charset)) || (!is_sep(*str, charset) && is_sep(*(str - 1), charset)))
		{
			*(ptr_to_strs++) = array;
			while (*str && !is_sep(*str, charset))
			{
				*array = *str;
				array++;
				str++;
			}
			*(array++) = '\0';
		}
		else
			str++;
	}
	*ptr_to_strs = NULL;
	return (result);
}
*/



/*
// INDICS
int     ft_count_words(char *str, char *charset)
{
    int count;
    int i;

    count = 0;
    i = 0;
    while (str[i])
	{
		// skip separators
        while (str[i] && is_sep(str[i], charset))
            i++;

        // start of word
        if (str[i] && !is_sep(str[i], charset))
        {
            count++;
            // skip string
            while (str[i] && !is_sep(str[i], charset))
                i++;
        }
    }
    return (count);
}

char	*ft_putword(char *str, int start, int end)
{
	char	*word;
	int		i;

	word = malloc((end - start + 2) * sizeof(char));
	if (!word)
		return (NULL);

	i = 0;
	while (start <= end)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**ptr_words;
	int		start;
	int		end;
	int		i;
	int		j;

	ptr_words = malloc((ft_count_words(str, charset) + 1) * sizeof(char *));
	if (!ptr_words)
		return (NULL);

	j = 0;
	i = 0;
	while(str[i])
	{
		while(str[i] && is_sep(str[i], charset))
			i++;
		/* Prevent creating empty strings *//*
		if (!str[i])
			break;

		start = i;
		while(str[i] && !is_sep(str[i], charset))
			i++;

		end = i - 1;
		/*
			*ptr_words++ == *(ptr_words++) (kayjib current addr kaydkhal lvalue li fih mn b3d kayzid addr 1)
			(*ptr_words)++  (kayjib value dyal current addr w kayzid 3liha 1 mn ba3d)
		 *//*
		ptr_words[j] = ft_putword(str, start, end);
		if (ptr_words[j] == NULL)
		{
			while (j > 0)
				free(ptr_words[--j]);
			free(ptr_words);
			return (NULL);		// NULL is pointer to void
		}
		j++;
	}
	ptr_words[j] = NULL;
	return (ptr_words);
}
*/