#include <stdio.h>


int	ft_is_prime(int nb)
{
	int	i;

	if (nb < 2)
		return (0);

	i = 2;
	while (nb >= i * i)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}



int	main()
{
	printf("%d\n", ft_is_prime(7));
}
