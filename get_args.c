/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <vintran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 11:30:03 by vintran           #+#    #+#             */
/*   Updated: 2020/11/21 14:55:59 by vintran          ###   ########.fr       */
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

int		is_star_ret_one(const char *format, t_params *prm)
{
	int ret;

	ret = 0;
	prm->before = va_arg(*(prm->args), int);
	ret = 1;
	if (*format == '-' && prm->before > 0)
		prm->before = -(prm->before);
	format = ft_memchr(format, '*', flag_len(format, prm->flag)) + 1;
	if (is_star(format, prm->flag) == 2)
	{
		prm->after = va_arg(*(prm->args), int);
		ret = 3;
	}
	return (ret);
}

int		is_star_ret_two(const char *format, t_params *prm)
{
	int ret;

	ret = 0;
	if (ft_memchr(format, '.', flag_len(format, prm->flag)))
	{
		prm->after = va_arg(*(prm->args), int);
		ret = 2;
	}
	else
	{
		prm->before = va_arg(*(prm->args), int);
		ret = 1;
		if (*format == '-' && prm->before > 0)
			prm->before = -(prm->before);
	}
	return (ret);
}

int		get_star_args(const char *format, t_params *prm)
{
	int ret;

	ret = 0;
	if (is_star(format, prm->flag) == 1)
		ret = is_star_ret_one(format, prm);
	else if (is_star(format, prm->flag) == 2)
		ret = is_star_ret_two(format, prm);
	return (ret);
}

int		get_flag_args(const char *format, t_params *prm)
{
	int ret;

	ret = get_star_args(format, prm);
	if (ret != 1 && ret != 3)
	{
		prm->before = ft_atoi(format);
		if (ret == 2)
			ret = 3;
		else
			ret = 1;
	}
	if (*format == '0' && prm->before)
		prm->zero_arg = '0';
	if (ret != 2 && ret != 3)
		if ((format = (const char *)ft_memchr(format, '.', flag_len(format, prm->flag))))
		{
			format++;
			prm->after = ft_atoi(format);
			ret = 3;
		}
	return (ret);
}
