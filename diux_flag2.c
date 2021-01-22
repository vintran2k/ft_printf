/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diux_flag2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <vintran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 11:39:16 by vintran           #+#    #+#             */
/*   Updated: 2021/01/20 17:03:40 by vintran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		d_bpos_apos(t_params prm, long nb)
{
	t_pos var;

	init_var_apos_diux(prm, &var, nb);
	while (var.space-- > 0)
		ft_putchar(' ');
	if (nb < 0 && (prm.flag == 'd' || prm.flag == 'i'))
	{
		ft_putchar('-');
		nb = -nb;
	}
	while (var.zero-- > 0)
		ft_putchar('0');
	print_nb(nb, prm.flag);
	return (var.ret);
}

int		d_bpos_aneg(t_params prm, long nb)
{
	t_pos var;

	init_var_aneg_diux(prm, &var, nb);
	if (prm.zero_arg == '0' && prm.after == 0 && prm.n == 3)
		prm.zero_arg = ' ';
	if (prm.zero_arg == '0' && nb < 0 && (prm.flag == 'd' || prm.flag == 'i'))
	{
		ft_putchar('-');
		nb = -nb;
	}
	while (var.space-- > 0)
		ft_putchar(prm.zero_arg);
	print_nb(nb, prm.flag);
	return (var.ret);
}

int		d_bneg_aneg(t_params prm, long nb)
{
	t_pos var;

	init_var_aneg_diux(prm, &var, nb);
	print_nb(nb, prm.flag);
	while (var.space-- > 0)
		ft_putchar(' ');
	return (var.ret);
}

int		d_bneg_apos(t_params prm, long nb)
{
	t_pos var;

	init_var_apos_diux(prm, &var, nb);
	if (nb < 0 && (prm.flag == 'd' || prm.flag == 'i'))
	{
		ft_putchar('-');
		nb = -nb;
	}
	while (var.zero-- > 0)
		ft_putchar('0');
	print_nb(nb, prm.flag);
	while (var.space-- > 0)
		ft_putchar(' ');
	return (var.ret);
}
