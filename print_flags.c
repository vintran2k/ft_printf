/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <vintran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 11:26:19 by vintran           #+#    #+#             */
/*   Updated: 2021/01/22 11:45:37 by vintran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_diux(const char *format, va_list *args, char flag)
{
	int			nb;
	t_params	prm;

	init_params(&prm, args, flag);
	if (flag_len(format, flag))
		return (parsing_diux(format, &prm));
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
	return ((int)ft_strlen(str));
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

int		print_pourcent(const char *format, va_list *args)
{
	t_params	prm;

	init_params(&prm, args, '%');
	format++;
	if (flag_len(format, '%'))
	{
		prm.n = get_flag_args(format, &prm);
		if (prm.before > 0 && prm.zero_arg == '0')
			return (pourcent_special_zero(prm.before));
		return (c_fonction_choice(prm, '%'));
	}
	ft_putchar('%');
	return (1);
}
