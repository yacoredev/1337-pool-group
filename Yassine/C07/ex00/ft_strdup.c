/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaadi <ybaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 13:39:51 by ybaadi            #+#    #+#             */
/*   Updated: 2026/05/16 15:57:56 by ybaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*	NAME:
		strdup - duplicate a string

	DESCRIPTION:
	The strdup() function returns a pointer to a new string which is a
	duplicate (copy) of the string src.  Memory for the new string is obtained with
       	malloc(3), and can be freed with free(3).

	RETURN VALUE:
	On success, the strdup() function returns a pointer to copy string.
	It returns NULL if insufficient

	Errors:
	nsufficient memory available to allocate duplicate string.
*/

int     ft_strlen(char *str)
{
    int     index;

    index = 0;
    while (str[index])
    {
        index++;
    }
    return (index);
}

char    *ft_strdup(char *src)
{
	char	*ptr;
	int	i;

	ptr = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
	if (ptr == NULL)
	{
		return (NULL);
	}

	i = 0;
	while (src[i] != '\0')
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}


/*
#include <stdio.h>
int main()
{
	char str[] = "Hello";
	char *heap_copy = ft_strdup(str);

	if (heap_copy == NULL)
		printf("malloc failed\n");
	else
		printf("Heap copy: %s\n", heap_copy);

	// Don't forget it
	free(heap_copy);
	return(0);
}
*/
