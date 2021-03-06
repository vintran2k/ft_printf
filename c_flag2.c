/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_flag2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <vintran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 16:23:39 by vintran           #+#    #+#             */
/*   Updated: 2021/01/20 17:08:49 by vintran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		c_bpos_apos(t_params prm, char c)
{
	t_pos	var;

	init_var_apos_cs(prm, &var, 1);
	while (var.space--)
		ft_putchar(' ');
	ft_putchar(c);
	return (var.ret);
}

int		c_bpos_aneg_or_noafter(t_params prm, char c)
{
	t_pos	var;

	init_var_aneg_cs(prm, &var, 1);
	if (prm.before < 0)
	{
		ft_putchar(c);
		while (var.space--)
			ft_putchar(' ');
	}
	else
	{
		while (var.space--)
			ft_putchar(' ');
		ft_putchar(c);
	}
	return (var.ret);
}

int		c_bneg_aneg(t_params prm, char c)
{
	t_pos	var;

	init_var_aneg_cs(prm, &var, 1);
	ft_putchar(c);
	while (var.space--)
		ft_putchar(' ');
	return (var.ret);
}

int		c_bneg_apos(t_params prm, char c)
{
	int		i;
	t_pos	var;

	i = 0;
	init_var_apos_cs(prm, &var, 1);
	ft_putchar(c);
	while (var.space--)
		ft_putchar(' ');
	return (var.ret);
}
