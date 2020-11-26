/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <vintran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 11:26:19 by vintran           #+#    #+#             */
/*   Updated: 2020/11/26 17:47:02 by vintran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_d_i_u_x_X(const char *format, va_list *args, char flag)
{
	int 		nb;
	t_params	prm;

	init_params(&prm, args, flag);
	if (flag_len(format, flag))
		return (parsing_d_i_u_x_X_flag(format, &prm));
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
		return (parsing_sflag(format, &prm));
	str = va_arg(*args, char *);
	ft_putstr(str);
	return ((int)ft_strlen(str));
}
