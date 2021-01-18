/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <vintran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:06:37 by vintran           #+#    #+#             */
/*   Updated: 2020/11/27 15:14:38 by vintran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		s_fonction_choice(t_params prm, char *str)
{
	if (prm.before > 0)
	{
		if (prm.after < 0)
			return (s_bpos_aneg_or_noafter(prm, str));
		else
			return (s_bpos_apos(prm, str));
	}
	else
	{
		if (prm.after < 0)
			return (s_bneg_aneg(prm, str));
		else
			return (s_bneg_apos(prm, str));
	}
	return (0);
}

int		parsing_s(const char *format, t_params *prm)
{
	char	*str;

	format++;
	prm->n = get_flag_args(format, prm);
	str = va_arg(*(prm->args), char *);
	if (!str)
		str = "(null)";
	if (prm->n == 1)
		return (s_bpos_aneg_or_noafter(*prm, str));
	if (prm->n == 3 && prm->after == 0 && !str)
		return(special_zero(prm->before));
	return (s_fonction_choice(*prm, str));
}
