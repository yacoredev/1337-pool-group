#include <stdio.h>

void	ft_putchar(char c);
void    ft_putstr(char *str);
int     ft_strcmp(char *s1, char *s2);
int     ft_strlen(char *str);
void    ft_swap(int *a, int *b);

int		main(void)
{
	int a = 10, b = 20;

	ft_putchar('A');
	ft_putchar('\n');
	ft_putstr("string\n");
	printf("deff:%d\n", ft_strcmp("AZC", "AAC"));
	printf("len=%d\n", ft_strlen("HELLO"));
	ft_swap(&a, &b);
	printf("a=%d\nb=%d\n", a, b);

	return (0);
}