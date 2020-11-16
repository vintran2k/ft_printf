#include "ft_printf.h"

int main(void)
{
	printf(" <- [%d]\n", ft_printf("|%20d|", -10));
	printf(" <- [%d]\n\n", printf("|%20d|", -10));

	printf(" <- [%d]\n", ft_printf("|%-*d|", 5, 6));
	printf(" <- [%d]\n\n", printf("|%-*d|", 5, 6));

	printf(" <- [%d]\n", ft_printf("|%1.*d|", -15, -5));
	printf(" <- [%d]\n\n", printf("|%1.*d|", -15, -5));

	printf(" <- [%d]\n", ft_printf("|%-20d|", 2));
	printf(" <- [%d]\n\n", printf("|%-20d|", 2));

	printf(" <- [%d]\n", ft_printf("|%-*.*d|", -15, 15, -16));
	printf(" <- [%d]\n\n", printf("|%-*.*d|", -15, 15, -16));

	printf(" <- [%d]\n", ft_printf("|%-20d|", 9));
	printf(" <- [%d]\n\n", printf("|%-20d|", 9));

	printf(" <- [%d]\n", ft_printf("|%-15.14d|", 16));
	printf(" <- [%d]\n\n", printf("|%-15.14d|", 16));

	printf(" <- [%d]\n", ft_printf("|%*.*d|", -14, 17, -14));
	printf(" <- [%d]\n\n", printf("|%*.*d|", -14, 17, -14));

	printf(" <- [%d]\n", ft_printf("|%*.9d|", -15, 7));
	printf(" <- [%d]\n\n", printf("|%*.9d|", -15, 7));

	printf(" <- [%d]\n", ft_printf("|%*.19d|", -12, 15));
	printf(" <- [%d]\n\n", printf("|%*.19d|", -12, 15));

	printf(" <- [%d]\n", ft_printf("|%-*d|", 7, 10));
	printf(" <- [%d]\n\n", printf("|%-*d|", 7, 10));

	printf(" <- [%d]\n", ft_printf("|%20d|", 14));
	printf(" <- [%d]\n\n", printf("|%20d|", 14));

	printf(" <- [%d]\n", ft_printf("|%11.16d|", 1));
	printf(" <- [%d]\n\n", printf("|%11.16d|", 1));

	printf(" <- [%d]\n", ft_printf("|%-*d|", 17, -19));
	printf(" <- [%d]\n\n", printf("|%-*d|", 17, -19));

	printf(" <- [%d]\n", ft_printf("|%-*.19d|", -10, -12));
	printf(" <- [%d]\n\n", printf("|%-*.19d|", -10, -12));

	printf(" <- [%d]\n", ft_printf("|%-20d|", 1));
	printf(" <- [%d]\n\n", printf("|%-20d|", 1));

	printf(" <- [%d]\n", ft_printf("|%*.*d|", 16, 15, -5));
	printf(" <- [%d]\n\n", printf("|%*.*d|", 16, 15, -5));

	printf(" <- [%d]\n", ft_printf("|%20d|", 19));
	printf(" <- [%d]\n\n", printf("|%20d|", 19));

	printf(" <- [%d]\n", ft_printf("|%-19.2d|", -12));
	printf(" <- [%d]\n\n", printf("|%-19.2d|", -12));

	printf(" <- [%d]\n", ft_printf("|%-5.*d|", -19, -1));
	printf(" <- [%d]\n\n", printf("|%-5.*d|", -19, -1));

	printf(" <- [%d]\n", ft_printf("|%-*d|", 1, -15));
	printf(" <- [%d]\n\n", printf("|%-*d|", 1, -15));

	printf(" <- [%d]\n", ft_printf("|%*.13d|", -10, -15));
	printf(" <- [%d]\n\n", printf("|%*.13d|", -10, -15));

	printf(" <- [%d]\n", ft_printf("|%-15.*d|", -9, 16));
	printf(" <- [%d]\n\n", printf("|%-15.*d|", -9, 16));

	printf(" <- [%d]\n", ft_printf("|%20d|", 15));
	printf(" <- [%d]\n\n", printf("|%20d|", 15));

	printf(" <- [%d]\n", ft_printf("|%8.4d|", -1));
	printf(" <- [%d]\n\n", printf("|%8.4d|", -1));

	return (0);
}
