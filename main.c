#include "ft_printf.h"

int		main()
{
	ft_printf("|%04.0d|\n", 198);
	printf("|%04.*d|\n", -5, 198);
	return (0);
}
