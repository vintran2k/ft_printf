/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <vintran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:06:37 by vintran           #+#    #+#             */
/*   Updated: 2020/11/17 00:03:29 by vintran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		s_fonction_choice(int before, int after, char *str)
{
	if (before > 0)
	{
		if (after < 0)
			return (s_bpos_aneg_or_noafter(before, str));
		else
			return (s_bpos_apos(before, after, str));
	}
	else
	{
		if (after < 0)
			return (s_bneg_aneg(before, str));
		else
			return (s_bneg_apos(before, after, str));
	}
	return (0);
}

int		parsing_sflag(const char *format, va_list *args, char flag)
{
	int		before;
	int		after;
	char	*str;

	before = 0;
	after = 0;
	format++;
	if (!get_flag_args(format, &before, &after, args, flag))
	{
		str = va_arg(*args, char *);
		return (s_bpos_aneg_or_noafter(before, str));
	}
	str = va_arg(*args, char *);
	return (s_fonction_choice(before, after, str));
}
