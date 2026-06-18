int is_vowel(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (c == 'a' || c =='A' || c == 'e' || c == 'E' ||
				c == 'o' || c == 'O' || c == 'u' || c == 'U' ||
				c == 'i' || c == 'I');
	return (0);
}

#include <stdio.h>
int main(void)
{

	printf("%d\n", is_vowel('7'));

	/*
	if (is_vowel('b'))
		printf("vowel\n");
	else
		printf("Not vowel\n");
	*/

	return (0);
}