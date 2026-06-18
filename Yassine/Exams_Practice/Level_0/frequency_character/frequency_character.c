
int frequency_character(char c, char *str)
{
	/*
		if (!str) == true	--> pointer is NULL

		if (!*str) == true	--> pointer is valide but string is empty ("")
	*/
	if (!str)
		return (0);

	int i = 0;
	while(str[i])
	{
		if (str[i] == c)
			return (i + 1);
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
int main(void)
{
	printf("%d\n", frequency_character('r', "Hello world!"));
	return (0);
}
*/