/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <vintran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 16:12:20 by vintran           #+#    #+#             */
/*   Updated: 2020/11/16 11:38:02 by vintran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char        find_flag(const char *format)
{
	int i;

	i = 1;
	while (format[i] && format[i] != 'd' && format[i] != 'c'
			&& format[i] != 'p' && format[i] != 's' && format[i] != 'x'
			&& format[i] != 'X' && format[i] != 'i' && format[i] != '%')
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

/*int		main()
{
	printf(" <- [%d]\n", printf("|%-5.*d|", 3, -2));
	printf(" <- [%d]\n\n", ft_printf("|%-5.*d|", 3, -2));
	printf(" <- [%d]\n", printf("|%-3.*d|", 5, -2));
	printf(" <- [%d]\n\n", ft_printf("|%-3.*d|", 5, -2));
	printf(" <- [%d]\n", printf("|%-2.*d|", 5, 1225));
	printf(" <- [%d]\n\n", ft_printf("|%-2.*d|", 5, 1225));
	printf(" <- [%d]\n", printf("|%-5.*d|", 2, -1225));
	printf(" <- [%d]\n\n", ft_printf("|%-5.*d|", 2, -1225));
	printf(" <- [%d]\n", printf("|%-1.*d|", 8, -3));
	printf(" <- [%d]\n\n", ft_printf("|%-1.*d|", 8, -3));
	printf(" <- [%d]\n", printf("|%-8.*d|", 1, 3));
	printf(" <- [%d]\n\n", ft_printf("|%-8.*d|", 1, 3));
	printf(" <- [%d]\n", printf("|%-6.*d|", 6, -323));
	printf(" <- [%d]\n", ft_printf("|%-6.*d|", 6, -323));
}

int main()
{
	printf(" <- [%d]\n", ft_printf("|%7.0d|", 0));
	printf(" <- [%d]\n\n", printf("|%7.0d|", 0));
}*/

/*int		main()
{
	printf(" <- [%d]\n", ft_printf("|%20.*d|", 0, -1));
	printf(" <- [%d]\n\n", printf("|%20.*d|", 0, -1));
	printf(" <- [%d]\n", ft_printf("|%*.*d|", -6, 9, -17));
	printf(" <- [%d]\n\n", printf("|%*.*d|", -6, 9, -17));
	printf(" <- [%d]\n", ft_printf("|%*d|", -14, -2));
	printf(" <- [%d]\n\n", printf("|%*d|", -14, -2));
	printf(" <- [%d]\n", ft_printf("|%*.*d|", 16, -1, -20));
	printf(" <- [%d]\n\n", printf("|%-*.*d|", 16, -1, -20));
	printf(" <- [%d]\n", ft_printf("|%-4.*d|", -1, -20));
	printf(" <- [%d]\n\n", printf("|%-4.*d|", -1, -20));

}*/
