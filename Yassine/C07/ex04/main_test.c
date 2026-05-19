#include <stdio.h>
#include <stdlib.h>

char    *ft_convert_base(char *nbr, char *base_from, char *base_to);

/*
int     main(void) {
    
    char    *dec = "0123456789";
    char    *hex = "0123456789abcdef";
    char    *oct = "01234567";
    char    *bin = "01";
    // char *new = "poneyvif";
    char    *result;
    
    // convert a string number from a base_from to a base_to
    // works like ft_atoi (spaces, signs, stop on invalid char)
    result = ft_convert_base("  --2147483648", dec, hex);
    printf("\nbase[%d]\tto\tbase[%d]\n\t\t->\t(%s)\n", ft_strlen(dec), 
        ft_strlen(hex), result);

    result = ft_convert_base("  --4acf8Gu-mm", hex, dec);
    printf("\nbase[%d]\tto\tbase[%d]\n\t\t->\t(%s)\n", ft_strlen(hex), 
        ft_strlen(dec), result);
    
    result = ft_convert_base("  --2147488a48", oct, hex);
    printf("\nbase[%d]\t\tto\tbase[%d]\n\t\t->\t(%s)\n", ft_strlen(oct), 
        ft_strlen(hex), result);
        
    result = ft_convert_base("  --4acf8Gu-mm", hex, bin);
    printf("\nbase[%d]\tto\tbase[%d]\n\t\t->\t(%s)\n", ft_strlen(hex), 
        ft_strlen(bin), result);
    
    free(result);
    return (0);
}
*/

void	test(char *nbr, char *from, char *to)
{
	char	*result;

	result = ft_convert_base(nbr, from, to);

	printf("nbr      : [%s]\n", nbr);
	printf("from     : [%s]\n", from);
	printf("to       : [%s]\n", to);

	if (result)
	{
		printf("result   : [%s]\n", result);
		free(result);
	}
	else
	{
		printf("result   : [NULL]\n");
	}

	printf("----------------------------------------\n");
}

// HARD TEST
int	main(void)
{
	// Basic conversions
	test("42", "0123456789", "01");
	test("101010", "01", "0123456789");
	test("2A", "0123456789ABCDEF", "0123456789");

	// Negative numbers
	test("-42", "0123456789", "01");
	test("-101010", "01", "0123456789");

	// Whitespaces + signs
	test("   ---+--+42", "0123456789", "01");

	// Invalid chars stop
	test("42abc", "0123456789", "01");
	test("101010xyz", "01", "0123456789");

	// Zero cases
	test("0", "0123456789", "01");
	test("-0", "0123456789", "01");

	// INT limits
	test("2147483647", "0123456789", "01");
	test("-2147483648", "0123456789", "01");

	// Invalid bases
	test("42", "012233", "01");
	test("42", "0", "01");
	test("42", "", "01");
	test("42", "012+345", "01");
	test("42", "01-2345", "01");
	test("42", "01 2345", "01");

	// Custom bases
	test("aaa", "abc", "0123456789");
	test("bca", "abc", "0123456789");

	// Same base
	test("42", "0123456789", "0123456789");

	// Large binary
	test("1111111111111111111111111111111",
		"01",
		"0123456789");

	// Hex tests
	test("ff", "0123456789abcdef", "0123456789");
	test("FF", "0123456789ABCDEF", "0123456789");

	// Garbage input
	test("hello", "0123456789", "01");

	// Decimal to hex
	test("2147483647", "0123456789", "0123456789abcdef");

	return (0);
}