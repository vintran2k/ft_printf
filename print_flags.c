/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <vintran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 11:26:19 by vintran           #+#    #+#             */
/*   Updated: 2021/01/15 11:54:55 by vintran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_d_i_u_x_X(const char *format, va_list *args, char flag)
{
	int 		nb;
	t_params	prm;

	init_params(&prm, args, flag);
	if (flag_len(format, flag))
		return (parsing_d_i_u_x_X(format, &prm));
	nb = va_arg(*args, int);
	if (flag == 'd' || flag == 'i')
		ft_putnbr(nb);
	else if (flag == 'u')
		ft_putnbr_u(nb);
	else
		ft_putnbr_hex(nb, flag);
	return (real_len(nb, flag));
}

int		print_s(const char *format, va_list *args)
{
	char		*str;
	t_params	prm;

	init_params(&prm, args, 's');
	if (flag_len(format, 's'))
		return (parsing_s(format, &prm));
	str = va_arg(*args, char *);
	if (!str)
		str = "(null)";
	ft_putstr(str);
	return ((int)strlen(str));
}

int		print_p(const char *format, va_list *args)
{
	unsigned long long	addr;
	t_params			prm;

	init_params(&prm, args, 'p');
	if (flag_len(format, 'p'))
		return (parsing_p(format, &prm));
	addr = (unsigned long long)va_arg(*args, void *);
	print_addr(addr);
	return (addrlen(addr) + 2);
}

int		print_c(const char *format, va_list *args)
{
	char		c;
	t_params	prm;

	init_params(&prm, args, 'c');
	if (flag_len(format, 'c'))
		return (parsing_c(format, &prm));
	c = va_arg(*args, int);
	ft_putchar(c);
	return (1);
}
