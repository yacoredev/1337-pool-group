int	ft_strlen(char *str)
{
	char *start;

	start = str;
	while (*str)
		str++;
	return (str - start);
}

/*
#include <stdio.h>
int main(void)
{
	printf("%d\n", ft_strlen("strong life"));
	return 0;
}
*/
