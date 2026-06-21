int ft_pow(int num, int pow)
{
	int result;

	/* trap !! */
	if (pow < 0 && num != 0)
		return (0);

	result = 1;
	while(pow > 0)
	{
		result *= num;
		pow--;
	}
	return (result);
}

/*
#include <stdio.h>
int main(void)
{
	int n1 = 2;
	int n2 = 4;

	printf("%d^%d = %d\n", n1, n2, ft_pow(n1, n2));

	return (0);
}
*/