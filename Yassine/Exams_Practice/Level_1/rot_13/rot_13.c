#include <unistd.h>

int is_alpha(char c)
{
	if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

int is_upper(char c)
{
	if(c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int main(int argc, char *argv[])
{
	char *str;
	char c;
	int i;

	if(argc == 2)
	{
		str = argv[1];
		i = 0;
		while(str[i])
		{
			c = str[i];
			if(is_alpha(c))
			{
				if(is_upper(c))
				{
					if(c >= 'A' && c <= 'M')
						c = str[i] + 13;
					else
						c = str[i] - 13;
				}
				else
				{
					if(c >= 'a' && c <= 'm')
						c = str[i] + 13;
					else
						c = str[i] - 13;
				}
			}
			write(1, &c, 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

/* 1. check if the character is an alphabet
 * 2. check if the character is uppercase or lowercase
 * 3. if it's uppercase, add 13 to it and check if it exceeds 'Z'
 * 4. if it exceeds 'Z', subtract 13 from it
 * 5. if it's lowercase, add 13 to it and check if it exceeds 'z'
 * 6. if it exceeds 'z', subtract 13 from it
 * 7. write a newline character at the end
 */
/*
int main(int argc, char *argv[])
{
	char *str;
	/* hit momkin yw93 overflow w ywli c negatif *//*
	unsigned char c;
	int i;

	if(argc == 2)
	{
		str = argv[1];
		i = 0;
		while(str[i])
		{
			c = str[i];
			if(is_alpha(c))
			{
				if(is_upper(c))
				{
					c = str[i] + 13;
					if(c > 'Z')
						c = str[i] - 13;
				}
				else
				{
					c = str[i] + 13;
					if(c > 'z')
						c = str[i] - 13;
				}
			}
			write(1, &c, 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
*/