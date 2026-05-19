/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaadi <ybaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 16:11:59 by ybaadi            #+#    #+#             */
/*   Updated: 2026/05/11 18:24:11 by ybaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	size;
	int	i;
	
	if (min >= max)
	{
		return (NULL);
	}

	size = max - min;
	range = (int *)malloc(size * sizeof(int));
	if (range == NULL)
	{
		return (NULL);
	}

	i = 0;
	while (i < size)
	{
		range[i] = min + i;
		i++;
	}
	return (range);
}

#include <stdio.h>
int main()
{
	int min = 4, max = 9;
	int size = max - min;
	int *arr = ft_range(min, max);

	if (arr == NULL)
		printf("Allocation failed\n");
	else
		for (int i = 0; i < size; i++)
			printf("%d", arr[i]);
	free(arr);
	return (0);
}
