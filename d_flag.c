/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <vintran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:51:09 by vintran           #+#    #+#             */
/*   Updated: 2020/11/16 17:23:19 by vintran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		special_zero(int before)
{
	int ret;

	ret = before;
    while (before-- > 0)
        ft_putchar(' ');
    return (ret);	
}

int		d_fonction_choice(int before, int after, int nb)
{
	if (before > 0)
	{
		if (after < 0)
			return (d_bpos_aneg(before, nb));
		else
			return (d_bpos_apos(before, after, nb));
	}
	else
	{
		if (after < 0)
			return (d_bneg_aneg(before, nb));
		else
			return (d_bneg_apos(before, after, nb));
	}
	return (0);
}

int		parsing_dflag(const char *format, va_list *args, char flag)
{
	int before;
	int	after;
	int nb;

	before = 0;
	after = 0;
	format++;
	if (get_flag_args(format, &before, &after, args, flag) == 1 && after == 0)
	{
		nb = va_arg(*args, int);
		if (nb == 0)
			return (special_zero(before));
	}
	else
		nb = va_arg(*args, int);
	return (d_fonction_choice(before, after, nb));
}
