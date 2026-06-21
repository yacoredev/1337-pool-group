
int ft_div(int n1, int n2)
{
	if (n2 == 0)
		return (1);
	return (n1 / n2);
}

/*
#include <stdio.h>
int main(void)
{
	int n1 = 100;
	int n2 = -2;

	if (n2 != 0)
	{
		printf("%d/%d = %d\n", n1, n2, ft_div(n1, n2));
	}
	else
		printf("error! 'division of 0'\n");

	return (0);
}
*/