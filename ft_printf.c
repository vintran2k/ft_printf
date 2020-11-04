/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <vintran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 16:12:20 by vintran           #+#    #+#             */
/*   Updated: 2020/11/04 14:22:50 by vintran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		if (nb == -2147483648)
		{
			write(1, "2147483648", 10);
			return ;
		}
		nb *= -1;
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

int		print_d(const char * format, va_list *args)
{
	int nb;

	if (flag_len(format))
		return (parsing_flag(format, args));
	nb = va_arg(*args, int);
	ft_putnbr(nb);
	return (nbr_len(nb));
}

char        find_flag(const char *format)
{
	int i;

	i = 0;
	while (format[i] && format[i] != 'd' && format[i] != 'c'
			&& format[i] != 'p' && format[i] != 's')
		i++;
	return (format[i]);
}

int		through_flag(const char *format)
{
	int i;
	char flag;

	i = 0;
	flag = find_flag(format);
	while (format[i] && format[i] != flag)
		i++;
	return (i);
}

int		parsing_format(const char *format, va_list *args)
{
	char	flag;

	flag = find_flag(format);
	if (format[1] == '%')
	{
		ft_putchar('%');
		return (1);
	}
	if (flag == 'd')
		return (print_d(format, args));
	return (0);//
}

int		ft_printf(const char *format, ...)
{
	int ret;
	va_list args;

	ret = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			ret += parsing_format(format, &args);
			format += through_flag(format);
		}
		else
		{
			ft_putchar(*format);
			ret++;
		}
		format++;
	}
	return (ret);
}

/*int		main()
{
	printf(" <- [%d]\n", printf("|%5.3d|", 8));
	printf(" <- [%d]\n", ft_printf("|%5.3d|", 8));
	printf(" <- [%d]\n", printf("|%-5.3d|", 8));
	printf(" <- [%d]\n", ft_printf("|%-5.3d|", 8));
	printf(" <- [%d]\n", printf("|%3.5d|", 8));
	printf(" <- [%d]\n", ft_printf("|%3.5d|", 8));
	printf(" <- [%d]\n", printf("|%-3.5d|", 8));
	printf(" <- [%d]\n", ft_printf("|%-3.5d|", 8));
	printf(" <- [%d]\n", printf("|%3*d|", 4, 8));
	printf(" <- [%d]\n", printf("|%*3d|", 4, 8));
	printf(" <- [%d]\n", printf("|%-*d|", 4, 8));
	printf(" <- [%d]\n", printf("|%*d|", -4, 8));
	printf(" <- [%d]\n", printf("|%-2d|", 8));
	return (0);
}*/

/*int		main()
{
	printf(" <- [%d]\n", printf("|%*.3d|", 4, 8));
	printf(" <- [%d]\n\n", ft_printf("|%*.3d|", 4, 8));
	printf(" <- [%d]\n", printf("|%5.*d|", 4, 8));
	printf(" <- [%d]\n\n", ft_printf("|%5.*d|", 4, 8));
	printf(" <- [%d]\n", printf("|%**5.3d|", 4, 8));
	printf(" <- [%d]\n\n", ft_printf("|%**5.3d|", 4, 8));
}*/

int		main()
{
	printf(" <- [%d]\n", printf("|%*.*d|", -17, -18, -14));
	printf(" <- [%d]\n", ft_printf("|%*.*d|", -17, -18, -14));
	printf(" <- [%d]\n", printf("|%10.5d|", -5));
	printf(" <- [%d]\n\n", ft_printf("|%10.5d|", -5));
	printf(" <- [%d]\n", printf("|%10.5d|", 25));
	printf(" <- [%d]\n\n", ft_printf("|%10.5d|", 25));
}
