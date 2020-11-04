#include "ft_printf.h"

int main(void)
{
	printf(" <- [%d]\n", ft_printf("|%-17.7d|", 10));
	printf(" <- [%d]\n\n", printf("|%-17.7d|", 10));

	printf(" <- [%d]\n", ft_printf("|%-*.2d|", -15, 11));
	printf(" <- [%d]\n\n", printf("|%-*.2d|", -15, 11));

	printf(" <- [%d]\n", ft_printf("|%-20d|", -19));
	printf(" <- [%d]\n\n", printf("|%-20d|", -19));

	printf(" <- [%d]\n", ft_printf("|%-20d|", 5));
	printf(" <- [%d]\n\n", printf("|%-20d|", 5));

	printf(" <- [%d]\n", ft_printf("|%-20d|", 12));
	printf(" <- [%d]\n\n", printf("|%-20d|", 12));

	printf(" <- [%d]\n", ft_printf("|%*d|", 1, -1));
	printf(" <- [%d]\n\n", printf("|%*d|", 1, -1));

	printf(" <- [%d]\n", ft_printf("|%-*d|", -8, -15));
	printf(" <- [%d]\n\n", printf("|%-*d|", -8, -15));

	printf(" <- [%d]\n", ft_printf("|%20d|", -6));
	printf(" <- [%d]\n\n", printf("|%20d|", -6));

	printf(" <- [%d]\n", ft_printf("|%20d|", -4));
	printf(" <- [%d]\n\n", printf("|%20d|", -4));

	printf(" <- [%d]\n", ft_printf("|%-*.*d|", -13, 15, -6));
	printf(" <- [%d]\n\n", printf("|%-*.*d|", -13, 15, -6));

	printf(" <- [%d]\n", ft_printf("|%4.14d|", -18));
	printf(" <- [%d]\n\n", printf("|%4.14d|", -18));

	printf(" <- [%d]\n", ft_printf("|%15.*d|", 9, 15));
	printf(" <- [%d]\n\n", printf("|%15.*d|", 9, 15));

	printf(" <- [%d]\n", ft_printf("|%-*d|", 18, 11));
	printf(" <- [%d]\n\n", printf("|%-*d|", 18, 11));

	printf(" <- [%d]\n", ft_printf("|%-*d|", -7, -8));
	printf(" <- [%d]\n\n", printf("|%-*d|", -7, -8));

	printf(" <- [%d]\n", ft_printf("|%*.*d|", -14, -14, 4));
	printf(" <- [%d]\n\n", printf("|%*.*d|", -14, -14, 4));

	printf(" <- [%d]\n", ft_printf("|%16.13d|", 2));
	printf(" <- [%d]\n\n", printf("|%16.13d|", 2));

	printf(" <- [%d]\n", ft_printf("|%-*.17d|", 3, -3));
	printf(" <- [%d]\n\n", printf("|%-*.17d|", 3, -3));

	printf(" <- [%d]\n", ft_printf("|%-*.5d|", -4, 16));
	printf(" <- [%d]\n\n", printf("|%-*.5d|", -4, 16));

	printf(" <- [%d]\n", ft_printf("|%20d|", -10));
	printf(" <- [%d]\n\n", printf("|%20d|", -10));

	printf(" <- [%d]\n", ft_printf("|%*d|", 5, -5));
	printf(" <- [%d]\n\n", printf("|%*d|", 5, -5));

	printf(" <- [%d]\n", ft_printf("|%-*d|", 0, -12));
	printf(" <- [%d]\n\n", printf("|%-*d|", 0, -12));

	printf(" <- [%d]\n", ft_printf("|%*d|", -3, -2));
	printf(" <- [%d]\n\n", printf("|%*d|", -3, -2));

	printf(" <- [%d]\n", ft_printf("|%-20d|", -16));
	printf(" <- [%d]\n\n", printf("|%-20d|", -16));

	printf(" <- [%d]\n", ft_printf("|%-*.*d|", -9, 9, 14));
	printf(" <- [%d]\n\n", printf("|%-*.*d|", -9, 9, 14));

	printf(" <- [%d]\n", ft_printf("|%-11.11d|", -1));
	printf(" <- [%d]\n\n", printf("|%-11.11d|", -1));

	return (0);
}
