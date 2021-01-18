/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <vintran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 16:20:54 by vintran           #+#    #+#             */
/*   Updated: 2021/01/15 11:58:05 by vintran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		c_fonction_choice(t_params prm, char c)
{
	if (prm.before > 0)
	{
		if (prm.after < 0)
			return (c_bpos_aneg_or_noafter(prm, c));
		else
			return (c_bpos_apos(prm, c));
	}
	else
	{
		if (prm.after < 0)
			return (c_bneg_aneg(prm, c));
		else
			return (c_bneg_apos(prm, c));
	}
	return (0);
}

int		parsing_c(const char *format, t_params *prm)
{
	int	c;

	format++;
	prm->n = get_flag_args(format, prm);
	c = va_arg(*(prm->args), int);
	if (prm->n == 1)
		return (c_bpos_aneg_or_noafter(*prm, c));
	//if (prm->n == 3 && prm->after == 0 && c < 0)
	//	return(special_zero(prm->before));
	return (c_fonction_choice(*prm, c));
}
