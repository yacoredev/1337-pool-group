#include "ft_boolean.h"

void	ft_putstr(char* str)
{
	while (*str)
		write(1, str++, 1);
}

// c 9dima makantch fiha bool, true, false dakchi 3lach kansawbohom bohdna
// had function katkhdm bhal bool system
t_bool	ft_is_even(int nbr)
{
	return ((EVEN(nbr)) ? TRUE : FALSE);
}

int		main(int argc, char** argv)
{
	(void)argv;
	if (ft_is_even(argc - 1) == TRUE)
		ft_putstr(EVEN_MSG);
	else
		ft_putstr(ODD_MSG);
	return (SUCCESS);
}