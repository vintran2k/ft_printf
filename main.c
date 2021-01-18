#include "ft_printf.h"

int		main()
{
	int c;

	c = 48;
	printf("|%-4.c|\n\n", c);
	ft_printf("|%-4.c|\n", c);
	return (0);
}
/*
int		main()
{
	printf("|%04d|\n\n", 198);
	ft_printf("|%04d|\n", 198);
}*/
