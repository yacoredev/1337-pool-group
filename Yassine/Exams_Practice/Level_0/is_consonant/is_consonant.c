
int is_consonant(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return !(c == 'a' || c =='A' || c == 'e' || c == 'E' ||
				c == 'o' || c == 'O' || c == 'u' || c == 'U' ||
				c == 'i' || c == 'I');
	return (0);
}

#include <stdio.h>
int main(void)
{

	printf("%d\n", is_consonant('$'));

	/*
	if (is_consonant('b'))
		printf("consonant\n");
	else
		printf("Not consonant\n");
	*/

	return (0);
}