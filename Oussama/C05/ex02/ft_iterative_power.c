#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	res;

	if (power < 0)
		return (0);

	res = 1;
	while (power > 0)
	{
		res *= nb;
		power--;
	}
	return (res);
}

int	main()
{
	printf("%d\n", ft_iterative_power(7 , 7));
	return (0);
}
