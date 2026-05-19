/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaadi <ybaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 20:00:23 by ybaadi            #+#    #+#             */
/*   Updated: 2026/05/12 10:45:00 by ybaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

void	ft_push_to_arr(char *arr, char *str, int *idx)
{
	int	i;
	
	i = 0;
	while (str[i] != '\0')
	{
		arr[(*idx)++] = str[i++];
	}
}

int		ft_total_size(char **strs, int size, char *sep)
{
	int		total_size;
	int		sep_len;
	int		i;

	sep_len = ft_strlen(sep);

	total_size = 0;
	i = 0;
	while (i < size)
	{
		total_size += ft_strlen(strs[i]);
		i++;
	}
	total_size += (sep_len * (size - 1) + 1);
	return (total_size);
}

void	ft_strjoin_sep(int size, char **strs, char *sep, char *new_arr)
{
	int		j;
	int		i;

	j = 0;
	i = 0;
	while (i < size)
	{
		ft_push_to_arr(new_arr, strs[i], &j);
		// condation of last sep
		if (i != size - 1)
		{
			ft_push_to_arr(new_arr, sep, &j);
		}
		i++;
	}
	new_arr[j] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*new_arr;
	char	*empty_str;

	if (size <= 0)
	{
		// return empty string
		empty_str = malloc(1);
		if (empty_str == NULL)
		{
			return (NULL);
		}

		*empty_str = '\0';
		return (empty_str);
	}

	new_arr = (char *)malloc(ft_total_size(strs, size, sep));
	if (new_arr == NULL)
	{
		return (NULL);
	}

	ft_strjoin_sep(size, strs, sep, new_arr);

	return (new_arr);
}

/*
#include <stdio.h>
int main()
{

	char *arr[] = {"One", "Two", "Three"};
	int size = 3;

	char *ret_arr = ft_strjoin(size, arr, " -> ");

	if (!ret_arr)
		printf("Allocation failed\n");
	else
		printf("%s\n", ret_arr);
	free(ret_arr);
	return (0);
}
*/