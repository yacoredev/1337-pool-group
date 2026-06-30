#include "ft_boolean.h"

void	ft_putstr(char* str)
{
	while (*str)
		write(1, str++, 1);
}

/*
	c 9dima makantch fiha bool, true, false dakchi 3lach kansawbohom bohdna
	had function katkhdm bhal bool system

	Conditional Operator:
	(Condition) ? Value_If_True : Value_If_False;
*/
t_bool	ft_is_even(int nbr)
{
	return ((EVEN(nbr)) ? TRUE : FALSE);
}

/*
	(void)argv; typecasting to void 7it makanst3mlhach flcode
	To trick the compiler and prevent compilation errors if
	we use flags -Wall -Wextra -Werror
*/
int		main(int argc, char** argv)
{
	(void)argv;
	if (ft_is_even(argc - 1) == TRUE)
		ft_putstr(EVEN_MSG);
	else
		ft_putstr(ODD_MSG);
	return (SUCCESS);
}