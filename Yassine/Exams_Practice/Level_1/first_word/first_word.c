#include <unistd.h>

int is_space(char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

int main(int c, char **v)
{
	int i;
	char *str;

	if (c == 2)
	{
		str = v[1];
		i = 0;
		while (is_space(str[i]))
			i++;

		while (str[i] && !is_space(str[i]))
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}