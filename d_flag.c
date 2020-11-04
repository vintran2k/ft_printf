/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <vintran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:51:09 by vintran           #+#    #+#             */
/*   Updated: 2020/11/04 15:14:32 by vintran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		nbr_len(int nb)
{
	int len;

	len = 0;
	if (nb <= 0)
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

int		print_nb(int after, int nb)
{
	int nb_len;
	int i;
	int prnb_len;

	i = 0;
	prnb_len = 
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
		i++;
	}
	nb_len = nbr_len(nb);
	while (after > nb_len && i < after - nb_len)
	{
		ft_putchar('0');
		i++;
	}
	ft_putnbr(nb);
	i = after == 0 ? (i + nb_len) : 0;
	return (i);
}

void	print_flag(int before, int after, int nb)
{
	int i;

	i = 0;
	if (before > after)
	{
		after = after == 0 ? 1 : after;
		while (i < before - after)
		{
			ft_putchar(' ');
			i++;
		}
		print_nb(after, nb);
	}
	else
	{
		i = print_nb(after, nb);
		if (before < 0 && -before > after)
			while (i < -before - after)
			{
				ft_putchar(' ');
				i++;
			}
	}
}

int		is_star(const char *format)
{
	int star;
	int i;

	star = 0;
	i = 0;
	//printf("FORMAT = =%s=\nLEN = %d\n", format, flag_len(format));
	if ((format = ft_memchr(format, '*', flag_len(format))))
	{
		//printf("========a====");
		if (format[1] == '.')
			return (1);
		if (format[1] == 'd')
			return (2);
	}
	return (0);
}

void	get_flag_args(const char *format, int *before, int *after, va_list *args)
{
	int b;
	int a;

	b = 0;
	a = 0;
	if (is_star(format) == 1)
	{
		//printf("=====pa");
		*before = va_arg(*args, int);
		b = 1;
		format = ft_memchr(format, '*', flag_len(format)) + 1;
		if (format[-2] == '-')
			*before *= -1;
		if (is_star(format) == 2)
		{
			*after = va_arg(*args, int);
			a = 1;
		}
	}
	else if (is_star(format) == 2)
	{
		//printf("=====pass");
		if (ft_memchr(format, '.', flag_len(format)))
		{
			*after = va_arg(*args, int);
			a = 1;
		}
		else
		{
			//printf("=====passage");
			*before = va_arg(*args, int);
			b = 1;
		}
	}
	if (b == 0)
		*before = ft_atoi(format);
	if (a == 0)
		if ((format = (const char *)ft_memchr(format, '.', flag_len(format))))
		{
			format++;
			*after = ft_atoi(format);
		}
}

int		parsing_flag(const char *format, va_list *args) // seulement dans le cas ou on a des flags (pas pr %d tt seul)
{
	int before;
	int	after;
	int len;
	int nb;

	before = 0;
	after = 0;
	format++;
	get_flag_args(format, &before, &after, args);
	nb = va_arg(*args, int);
	print_flag(before, after, nb);
//	printf("          before = %d           after = %d\n", before, after);
	if (before > 0)
		len = (before >= after) ? before : after;
	else
		len = (-before >= after) ? -before : after;
	return (len);
}
