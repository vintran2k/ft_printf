/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_i_u_x_X_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <vintran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:51:09 by vintran           #+#    #+#             */
/*   Updated: 2021/01/15 12:15:42 by vintran          ###   ########.fr       */
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

int		fonction_choice(t_params prm, int nb)
{
	if (prm.before > 0)
	{
		if (prm.after <= 0)
			return (d_bpos_aneg(prm, nb));
		else
			return (d_bpos_apos(prm, nb));
	}
	else
	{
		if (prm.after <= 0)
			return (d_bneg_aneg(prm, nb));
		else
			return (d_bneg_apos(prm, nb));
	}
	return (0);
}

int		parsing_d_i_u_x_X(const char *format, t_params *prm)
{
	int nb;
	format++;
	if (get_flag_args(format, prm) == 3 && prm->after == 0)
	{
		//printf("BEFORE = %d   AFTER = %d|", prm->before, prm->after);
		nb = va_arg(*(prm->args), int);
		if (nb == 0)
			return (special_zero(prm->before));
	}
	else
		nb = va_arg(*(prm->args), int);
	//printf("BEFORE = %d   AFTER = %d|", prm->before, prm->after);
	return (fonction_choice(*prm, nb));
}
