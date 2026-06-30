#include <unistd.h>

void ft_rev_print(char *str)
{
	if (*str == '\0')
		return ;
	ft_rev_print(str + 1);
	write(1, str, 1);
}

int main(int c, char **v)
{
	char *str;
	int i;

	if (c == 2)
	{
		// str = v[1];
		// i = 0;
		// while (str[i])
		// 	i++;

		// while(i > 0)
		// 	write(1, &str[--i], 1);

		ft_rev_print(v[1]);
	}
	write(1, "\n", 1);
	return (0);
}

/*
// assume nbr = 134
void f(int nbr)
{
	if (nbr != 0)
		f(nbr / 10);		// ila bghit nkhdm bakhir value (li f2akhir frame = 0)

	char c = (nbr % 10) + '0';
	write(1, &c, 1);		// output: 0134
}
/*
	flow:

		f(134) ==> f(13) ==> f(1) ==> f(0)
			^	   	 ^	   	  ^   		^
			|	   	 |	   	  |   		|
		   0134		013		  01		0
*/

/*
// assume nbr = 134
void f(int nbr)
{
	if (nbr == 0)
		return ;
	f(nbr / 10);			// ila mabghitch akhir value

	char c = (nbr % 10) + '0';
	write(1, &c, 1);		// output: 134
}
/*
	flow:

		f(134) ==> f(13) ==> f(1) <== f(0)
			^	   	 ^	   	  ^   		^
			|	   	 |	   	  |   		|
		   134		13	 	  1	   	 return
*/
