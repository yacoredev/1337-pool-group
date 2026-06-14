#include <unistd.h>

	/*
	take string as a param
	dispaly the first 'a' + \n
	If there are no 'a' just print \n
	If nbr of param isn't 1 print 'a' + \n
	*/
int		main(int c, char **v)
{
	int	i;

	if (c == 2)
	{
		i = 0;
		while (v[1][i])
		{
			if (v[1][i] == 'a') {
				write(1, &v[1][i], 1);
				break;
			}
			i++;
		}
		write(1, "\n", 1);
	}
	else
		write(1, "a\n", 2);
	return (0);
}