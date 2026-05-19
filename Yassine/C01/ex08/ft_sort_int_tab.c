/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaadi <ybaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 18:21:21 by ybaadi            #+#    #+#             */
/*   Updated: 2026/05/17 12:47:27 by ybaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

void    ft_swap(int *a, int *b)
{
    int     temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void    ft_sort_int_tab(int *tab, int size)
{
    int     i;
    int     j;
    int     indexMin;

    // Technique Selection Sort
    i = 0;
    while (i < size - 1)    // ila kan size <= 1 ghaykhrj mobachara
    {
        indexMin = i;
        j = i + 1;
        while (j < size)    // bach ycompari hta akhir element
        {
            // kan7tafd b index dyal minimum value
            if (tab[j] < tab[indexMin])
            {
                indexMin = j;
            }
            j++;
        }

        // kahat minimum value blasto flbidaya
        ft_swap((tab + i), (tab + indexMin));

        i++;
    }
}

/*int     main(void)
{
    int arr[] = {5,2,4,1,3};
    int size = sizeof(arr) / sizeof(arr[0]);

    ft_sort_int_tab(arr, size);

    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    return (0);
}*/