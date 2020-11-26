/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_flag2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <vintran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:25:23 by vintran           #+#    #+#             */
/*   Updated: 2020/11/26 17:55:18 by vintran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		s_bpos_apos(t_params prm, char *str)
{
	int		i;
	t_pos	var;

	i = 0;
	init_var_apos_s(prm, &var, str);
	while (var.space--)
		ft_putchar(' ');
	while (i < var.len)
		ft_putchar(str[i++]);
	return (var.ret);
}

int		s_bpos_aneg_or_noafter(t_params prm, char *str)
{
	t_pos	var;

	init_var_aneg_s(prm, &var, str);
	if (prm.before < 0)
	{
		ft_putstr(str);
		while (var.space--)
			ft_putchar(' ');
	}
	else
	{
		while (var.space--)
			ft_putchar(' ');
		ft_putstr(str);
	}
	return (var.ret);
}

int		s_bneg_aneg(t_params prm, char *str)
{
	t_pos	var;

	init_var_aneg_s(prm, &var, str);
	ft_putstr(str);
	while (var.space--)
		ft_putchar(' ');
	return (var.ret);
}

int		s_bneg_apos(t_params prm, char *str)
{
	int		i;
	t_pos	var;

	i = 0;
	init_var_apos_s(prm, &var, str);
	while (var.len--)
		ft_putchar(str[i++]);
	while (var.space--)
		ft_putchar(' ');
	return (var.ret);
}
