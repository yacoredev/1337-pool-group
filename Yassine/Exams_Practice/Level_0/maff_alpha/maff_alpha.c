#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int main(void)
{
	char c;

	c = 'a';
	while(c <= 'z')
	{
		/* make even letter in uppercase */
		if(c % 2 == 0)
			ft_putchar(c-32);
		else
			ft_putchar(c);
		c++;
	}
	write(1, "\n", 1);
	return (0);
}