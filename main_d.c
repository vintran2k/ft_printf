#include "ft_printf.h"

int main(void)
{
	printf(" <- [%d]\n", ft_printf("|%*d|", -13, 17));
	printf(" <- [%d]\n\n", printf("|%*d|", -13, 17));

	printf(" <- [%d]\n", ft_printf("|%-20d|", -17));
	printf(" <- [%d]\n\n", printf("|%-20d|", -17));

	printf(" <- [%d]\n", ft_printf("|%*.*d|", 2, -11, 0));
	printf(" <- [%d]\n\n", printf("|%*.*d|", 2, -11, 0));

	printf(" <- [%d]\n", ft_printf("|%-*.*d|", -7, 2, 6));
	printf(" <- [%d]\n\n", printf("|%-*.*d|", -7, 2, 6));

	printf(" <- [%d]\n", ft_printf("|%13.*d|", 9, -9));
	printf(" <- [%d]\n\n", printf("|%13.*d|", 9, -9));

	printf(" <- [%d]\n", ft_printf("|%-20d|", -11));
	printf(" <- [%d]\n\n", printf("|%-20d|", -11));

	printf(" <- [%d]\n", ft_printf("|%-*.12d|", -4, -18));
	printf(" <- [%d]\n\n", printf("|%-*.12d|", -4, -18));

	printf(" <- [%d]\n", ft_printf("|%-*d|", 2, 16));
	printf(" <- [%d]\n\n", printf("|%-*d|", 2, 16));

	printf(" <- [%d]\n", ft_printf("|%*.*d|", -7, -3, 7));
	printf(" <- [%d]\n\n", printf("|%*.*d|", -7, -3, 7));

	printf(" <- [%d]\n", ft_printf("|%-*.*d|", -4, 19, 11));
	printf(" <- [%d]\n\n", printf("|%-*.*d|", -4, 19, 11));

	printf(" <- [%d]\n", ft_printf("|%*d|", -17, 8));
	printf(" <- [%d]\n\n", printf("|%*d|", -17, 8));

	printf(" <- [%d]\n", ft_printf("|%-*.3d|", 16, -13));
	printf(" <- [%d]\n\n", printf("|%-*.3d|", 16, -13));

	printf(" <- [%d]\n", ft_printf("|%17.9d|", -6));
	printf(" <- [%d]\n\n", printf("|%17.9d|", -6));

	printf(" <- [%d]\n", ft_printf("|%15.*d|", 7, -7));
	printf(" <- [%d]\n\n", printf("|%15.*d|", 7, -7));

	printf(" <- [%d]\n", ft_printf("|%13.19d|", -16));
	printf(" <- [%d]\n\n", printf("|%13.19d|", -16));

	printf(" <- [%d]\n", ft_printf("|%15.*d|", 15, 12));
	printf(" <- [%d]\n\n", printf("|%15.*d|", 15, 12));

	printf(" <- [%d]\n", ft_printf("|%11.12d|", -16));
	printf(" <- [%d]\n\n", printf("|%11.12d|", -16));

	printf(" <- [%d]\n", ft_printf("|%*d|", -2, -4));
	printf(" <- [%d]\n\n", printf("|%*d|", -2, -4));

	printf(" <- [%d]\n", ft_printf("|%17.*d|", -14, -20));
	printf(" <- [%d]\n\n", printf("|%17.*d|", -14, -20));

	printf(" <- [%d]\n", ft_printf("|%-*.7d|", 5, 12));
	printf(" <- [%d]\n\n", printf("|%-*.7d|", 5, 12));

	printf(" <- [%d]\n", ft_printf("|%4.*d|", -16, -1));
	printf(" <- [%d]\n\n", printf("|%4.*d|", -16, -1));

	printf(" <- [%d]\n", ft_printf("|%7.*d|", 4, -17));
	printf(" <- [%d]\n\n", printf("|%7.*d|", 4, -17));

	printf(" <- [%d]\n", ft_printf("|%.1d|", 8));
	printf(" <- [%d]\n\n", printf("|%.1d|", 8));

	printf(" <- [%d]\n", ft_printf("|%*d|", -2, 12));
	printf(" <- [%d]\n\n", printf("|%*d|", -2, 12));

	printf(" <- [%d]\n", ft_printf("|%20d|", -13));
	printf(" <- [%d]\n\n", printf("|%20d|", -13));

	return (0);
}
