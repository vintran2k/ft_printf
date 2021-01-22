/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <vintran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 16:12:20 by vintran           #+#    #+#             */
/*   Updated: 2021/01/20 17:09:15 by vintran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	find_flag(const char *format)
{
	int i;

	i = 0;
	while (format[i] && format[i] != 'd' && format[i] != 'c' && format[i] != 'u'
			&& format[i] != 'p' && format[i] != 's' && format[i] != 'x'
			&& format[i] != 'X' && format[i] != 'i' && format[i] != '%')
		i++;
	return (format[i]);
}

int		through_flag(const char *format)
{
	int		i;
	char	flag;

	i = 0;
	flag = find_flag(format + 1);
	while (format[i + 1] && format[i + 1] != flag)
		i++;
	return (i + 1);
}

int		parsing_format(const char *format, va_list *args)
{
	char	flag;

	flag = find_flag(format + 1);
	if (flag == 'd' || flag == 'i' || flag == 'x' || flag == 'X' || flag == 'u')
		return (print_diux(format, args, flag));
	if (flag == 's')
		return (print_s(format, args));
	if (flag == 'p')
		return (print_p(format, args));
	if (flag == 'c')
		return (print_c(format, args));
	if (flag == '%')
		return (print_pourcent(format, args));
	return (0);
}

int		ft_printf(const char *format, ...)
{
	int		ret;
	va_list	args;

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
