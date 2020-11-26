/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_i_u_x_X_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <vintran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:51:09 by vintran           #+#    #+#             */
/*   Updated: 2020/11/26 17:44:55 by vintran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		fonction_choice(t_params prm, int nb)
{
	if (prm.before > 0)
	{
		if (prm.after < 0)
			return (d_bpos_aneg(prm, nb, prm.zero_arg));
		else
			return (d_bpos_apos(prm, nb));
	}
	else
	{
		if (prm.after < 0)
			return (d_bneg_aneg(prm, nb));
		else
			return (d_bneg_apos(prm, nb));
	}
	return (0);
}

int		parsing_d_i_u_x_X_flag(const char *format, t_params *prm)
{
	int nb;
	format++;
	if (get_flag_args(format, prm) == 3 && prm->after == 0)
	{
		nb = va_arg(*(prm->args), int);
		if (nb == 0)
			return (special_zero(prm->before));
	}
	else
		nb = va_arg(*(prm->args), int);
	//printf("BEFORE = %d   AFTER = %d|", prm->before, prm->after);
	return (fonction_choice(*prm, nb));
}