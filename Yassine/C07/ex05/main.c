#include <stdio.h>
#include <stdlib.h>

char	**ft_split(char *str, char *charset);

/*
// SIMPLE TEST
int main()
{
  int i;

  char **arr = ft_split(" |    he||||||||llo cv     b|ik her ach khbark   |", " |");

  i = 0;
  while (arr[i])
    printf("%s\n", arr[i++]);

  free(*arr);
  free(arr);
  return(0);
}
*/


// HARD TEST
void	print_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		printf("[%s]\n", arr[i]);
		i++;
	}
	printf("-----------------------------\n");
}

int	main(void)
{
	char	**arr;

	/* basic */
	arr = ft_split("hello world", " ");
	print_split(arr);

	/* multiple separators */
	arr = ft_split("hello,world;1337:pool", ",;:");
	print_split(arr);

	/* repeated separators */
	arr = ft_split(",,,hello,,,world,,,", ",");
	print_split(arr);

	/* separators at start/end */
	arr = ft_split("   hello world   ", " ");
	print_split(arr);

	/* mixed separators */
	arr = ft_split("hello\tworld\n1337", "\t\n ");
	print_split(arr);

	/* no separators */
	arr = ft_split("helloworld", " ");
	print_split(arr);

	/* only separators */
	arr = ft_split(",,,,,,,,,,", ",");
	print_split(arr);

	/* empty string */
	arr = ft_split("", ",");
	print_split(arr);

	/* one word */
	arr = ft_split("hello", ",");
	print_split(arr);

	/* consecutive separators */
	arr = ft_split("hello,,,world;;42", ",;");
	print_split(arr);

	/* weird charset */
	arr = ft_split("abcXXdefYYghi", "XY");
	print_split(arr);

	/* spaces + tabs + newlines */
	arr = ft_split(" \t\nhello\t42\nworld\n", " \n\t");
	print_split(arr);

	/* separator every char */
	arr = ft_split("a,b,c,d,e", ",");
	print_split(arr);

	/* long separators chain */
	arr = ft_split(":::hello::::world:::", ":");
	print_split(arr);

	/* custom */
	arr = ft_split("42@@@1337###pool***C", "@#*");
	print_split(arr);

	return (0);
}
