/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <vintran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 11:26:19 by vintran           #+#    #+#             */
/*   Updated: 2020/11/16 16:14:52 by vintran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_d(const char *format, va_list *args)
{
	int nb;

	if (flag_len(format, 'd'))
		return (parsing_dflag(format, args, 'd'));
	nb = va_arg(*args, int);
	ft_putnbr(nb);
	return (nbr_len(nb));
}

int		print_s(const char *format, va_list *args)
{
	char *str;

	if (flag_len(format, 's'))
		return (parsing_sflag(format, args, 's'));
	str = va_arg(*args, char *);
	ft_putstr(str);
	return ((int)ft_strlen(str));
}
