/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oussama <oussama@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 17:00:26 by oussama           #+#    #+#             */
/*   Updated: 2026/06/16 17:03:53 by oussama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	i;

	if (min >= max)
		return (NULL);
	arr = malloc((max - min) * (sizeof(int)));
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (i < (max - min))
	{
		arr[i] = min + i;
		i++;
	}
	return (arr);
}

/*int	main(void)
{
	int	min;
	int	max;

	min = 1;
	max = 8;
	int *arr = ft_range(min, max);
	free(arr);
	arr = NULL;
	return 0;
}*/
