
char *ft_strcpy(char *dest, char *src)
{
	unsigned int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

#include <stdio.h>
int main(void)
{
	char src[] = "yacordev";
	char dest[9];

	printf("%s", ft_strcpy(dest, src));

	return (0);
}