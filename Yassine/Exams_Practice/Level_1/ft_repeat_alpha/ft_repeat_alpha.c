#include <unistd.h>

int		is_alpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int     main(int argc, char **argv)
{
	char *param;
	int repeat;
	int i;
	int j;

	if (argc == 2)
	{
		param = argv[1];
		i = 0;
		while(param[i])
		{
			repeat = 0;
			if (is_alpha(param[i]))
			{
				if (param[i] >= 'a' && param[i] <= 'z')
					repeat = param[i] - 96;
				else
					repeat = param[i] - 64;

				j = 0;
				while (j < repeat)
				{
					write(1, &param[i], 1);
					j++;
				}
			}
			else
				write(1, &param[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}