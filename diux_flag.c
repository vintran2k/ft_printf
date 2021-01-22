/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diux_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <vintran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:51:09 by vintran           #+#    #+#             */
/*   Updated: 2021/01/22 11:43:43 by vintran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		special_zero(int before)
{
	int ret;

	if (before < 0)
		before *= -1;
	ret = before;
	while (before-- > 0)
		ft_putchar(' ');
	return (ret);
}

int		fonction_choice(t_params prm, long nb)
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

int		parsing_diux(const char *format, t_params *prm)
{
	int		nbr;
	long	nb;
	int		ret;

	ret = 0;
	format++;
	prm->n = get_flag_args(format, prm);
	nbr = va_arg(*(prm->args), int);
	nb = nbr;
	if (*format == ' ')
		ret = ft_printf(" ");
	if (prm->n == 3 && prm->after == 0 && nb == 0)
		ret += (special_zero(prm->before));
	else
		ret += (fonction_choice(*prm, nb));
	return (ret);
}
