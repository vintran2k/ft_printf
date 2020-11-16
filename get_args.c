/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <vintran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 11:30:03 by vintran           #+#    #+#             */
/*   Updated: 2020/11/16 11:35:20 by vintran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_star(const char *format, char flag)
{
	int star;
	int i;

	star = 0;
	i = 0;
	if ((format = ft_memchr(format, '*', flag_len(format, flag))))
	{
		if (format[1] == '.')
			return (1);
		if (format[1] == flag)
			return (2);
	}
	return (0);
}

int		is_star_ret_one(const char *format, int *before, int *after, va_list *args, char flag)
{
	int ret;

	ret = 0;
	*before = va_arg(*args, int);
	ret = 1;
	*before = (*format == '-' && *before > 0) ? -(*before) : *before;
	format = ft_memchr(format, '*', flag_len(format, flag)) + 1;
	if (is_star(format, flag) == 2)
	{
		*after = va_arg(*args, int);
		ret = 3;
	}
	return (ret);
}

int		is_star_ret_two(const char *format, int *before, int *after, va_list *args, char flag)
{
	int ret;

	ret = 0;
	if (ft_memchr(format, '.', flag_len(format, flag)))
	{
		*after = va_arg(*args, int);
		ret = 2;
	}
	else
	{
		*before = va_arg(*args, int);
		ret = 1;
		*before = (*format == '-' && *before > 0) ? -(*before) : *before;
	}
	return (ret);
}

int		get_flag_args(const char *format, int *before, int *after, va_list *args, char flag)
{
	int ret;

	ret = 0;
	if (is_star(format, flag) == 1)
		ret = is_star_ret_one(format, before, after, args, flag);
	else if (is_star(format, flag) == 2)
		ret = is_star_ret_two(format, before, after, args, flag);
	(ret != 1 && ret != 3) ? *before = ft_atoi(format) : 0;
	if (ret != 2 && ret != 3)
		if ((format = (const char *)ft_memchr(format, '.', flag_len(format, flag))))
		{
			format++;
			*after = ft_atoi(format);
			ret = 3;
		}
	return (ret != 3) ? 0 : 1;
}
