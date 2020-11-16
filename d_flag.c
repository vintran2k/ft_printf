/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <vintran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:51:09 by vintran           #+#    #+#             */
/*   Updated: 2020/11/12 20:38:47 by vintran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		nbr_len(int nb)
{
	int len;

	len = 0;
	if (nb == 0)
		len++;
	while (nb)
	{
		nb /= 10;
		len ++;
	}
	return (len);
}

int		flag_len(const char *format)
{
	int i;

	i = 0;
	while (format[i] && format[i] != 'd' && format[i] != 'c'
			&& format[i] != 'p' && format[i] != 's')
		i++;
	return (i);
}

int		ft_atoi(const char *str)
{
	size_t	i;
	int		res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)&s[i]);
		i++;
	}
	return (NULL);
}

int		is_star(const char *format)
{
	int star;
	int i;

	star = 0;
	i = 0;
	if ((format = ft_memchr(format, '*', flag_len(format))))
	{
		if (format[1] == '.')
			return (1);
		if (format[1] == 'd')
			return (2);
	}
	return (0);
}

int		is_star_ret_one(const char *format, int *before, int *after, va_list *args)
{
	int ret;

	ret = 0;
	*before = va_arg(*args, int);
	ret = 1;
	*before = (*format == '-' && *before > 0) ? -(*before) : *before;
	format = ft_memchr(format, '*', flag_len(format)) + 1;
	if (is_star(format) == 2)
	{
		*after = va_arg(*args, int);
		ret = 3;
	}
	return (ret);
}

int		is_star_ret_two(const char *format, int *before, int *after, va_list *args)
{
	int ret;

	ret = 0;
	if (ft_memchr(format, '.', flag_len(format)))
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

int		get_flag_args(const char *format, int *before, int *after, va_list *args)
{
	int ret;

	ret = 0;
	if (is_star(format) == 1)
		ret = is_star_ret_one(format, before, after, args);
	else if (is_star(format) == 2)
		ret = is_star_ret_two(format, before, after, args);
	(ret != 1 && ret != 3) ? *before = ft_atoi(format) : 0;
	if (ret != 2 && ret != 3)
		if ((format = (const char *)ft_memchr(format, '.', flag_len(format))))
		{
			format++;
			*after = ft_atoi(format);
			ret = 3;
		}
	return (ret != 3) ? 0 : 1;
}

int		bpos_apos(int before, int after, int nb)
{
	int nblen;
    int space;
    int zero;
    int ret;

    space = 0;
	nblen = nbr_len(nb);
	zero = after > nblen ? after - nblen : 0;
    nb < 0 ? nblen++ : 0;
    space = before - (zero + nblen);
    space = (space < 0) ? 0 : space;
    ret = nblen + space + zero;
    while (space-- > 0)
        ft_putchar(' ');
    nb < 0 ? ft_putchar('-') : 0;
    while (zero-- > 0)
        ft_putchar('0');
	
    nb < 0 ? ft_putnbr(-nb) : ft_putnbr(nb);
    return (ret);
}

int		bpos_aneg(int before, int nb)
{
	int nblen;
	int space;
	int ret;

	nblen = nbr_len(nb);
	space = 0;
	if (before > nblen)
		space = before - nblen;
	nb < 0 ? space-- : 0;
	while (space-- > 0)
		ft_putchar(' ');
	ft_putnbr(nb);
	nb < 0 ? nblen++ : 0;
	ret = before > nblen ? before : nblen;
	return (ret);
}

int		bneg_aneg(int before, int nb)
{
	int nblen;
	int space;
	int ret;

	nblen = nbr_len(nb);
	space = 0;
	before = -before;
	if (before > nblen)
		space = before - nblen;
	nb < 0 ? space-- : 0;
	ft_putnbr(nb);
	while (space-- > 0)
		ft_putchar(' ');
	nb < 0 ? nblen++ : 0;
	ret = before > nblen ? before : nblen;
	return (ret);
}

int		bneg_apos(int before, int after, int nb)
{
	int nblen;
	int space;
	int zero;
	int ret;

	nblen = nbr_len(nb);
	space = 0;
	zero = 0;
	if (after > nblen)
		zero = after - nblen;
	nb < 0 ? nblen++ : 0;
	before = -before;
	space = before - (zero + nblen);
	space < 0 ? space = 0 : 0;
	ret = nblen + space + zero;
	nb < 0 ? ft_putchar('-') : 0;
	while (zero-- > 0)
		ft_putchar('0');
	nb < 0 ? ft_putnbr(-nb) : ft_putnbr(nb);
	while (space-- > 0)
		ft_putchar(' ');
	return (ret);
}

int		special_zero(int before)
{
	int ret;

	ret = before;
    while (before-- > 0)
        ft_putchar(' ');
    return (ret);	
}

int		fonction_choice(before, after, nb)
{
	if (before > 0)
	{
		if (after < 0)
			return (bpos_aneg(before, nb));
		else
			return (bpos_apos(before, after, nb));
	}
	else
	{
		if (after < 0)
			return (bneg_aneg(before, nb));
		else
			return (bneg_apos(before, after, nb));
	}
	return (0);
}

int		parsing_flag(const char *format, va_list *args)
{
	int before;
	int	after;
	int nb;

	before = 0;
	after = 0;
	format++;
	if (get_flag_args(format, &before, &after, args) == 1 && after == 0)
	{
		nb = va_arg(*args, int);
		if (nb == 0)
			return (special_zero(before));
	}
	else
		nb = va_arg(*args, int);
	return (fonction_choice(before, after, nb));
}
