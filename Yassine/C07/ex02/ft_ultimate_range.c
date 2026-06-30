/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacoredev <yacoredev@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 16:44:23 by ybaadi            #+#    #+#             */
/*   Updated: 2026/06/21 00:28:50 by yacoredev        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
        I have the right to change the original addr of 'arr'
	int **range = &arr      arr -> (int *)

	range == &arr
 	*range == arr == &arr[0]
	**range == value of arr: *arr == arr[0]

 	*(*range + i) == (*range)[i] == arr[i]
 */
int	ft_ultimate_range(int **range, int min, int max)
{
        int     size;
        int     i;

        if (min >= max)
        {
		*range = NULL;
                return (0);
        }

        size = max - min;
        // kankhzno address dyal had array dakhl pointer origin 'arr'
	*range = malloc(size * sizeof(int));
        if (*range == NULL)
        {
                return (-1);
        }

        i = 0;
        while (i < size)
        {
                (*range)[i] = min + i;
                i++;
        }
        return (size);
}

/*
#include <stdio.h>
int main()
{
        int min = 4, max = 9;
        int *arr;
	int size = ft_range(&arr, min, max);

        if (arr == NULL)
                printf("Allocation failed\n");
        else
                for (int i = 0; i < size; i++)
                        printf("%d", arr[i]);
        free(arr);
        return (0);
}
*/
