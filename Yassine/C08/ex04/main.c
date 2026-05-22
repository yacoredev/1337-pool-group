#include "ft_stock_str.h"
#include <stdio.h>

int		main(int c, char **v)
{
	t_stock_str *stock = ft_strs_to_tab(c, v);

	int i = 0;
	while (stock[i].str != NULL)
	{
		printf("\n  ----------------------\n");
		printf(" | size\t: %d\t\t|\n", stock[i].size);
		printf(" | string: %s\t|\n", stock[i].str);
		printf(" | copy\t: %s\t|\n", stock[i].copy);
		printf("  ----------------stock[%d]\n", i+1);
		i++;
	}
	printf("\n");

	ft_free_mem(stock, i);
	return (0);
}