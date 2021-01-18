/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_flag2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <vintran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 16:23:39 by vintran           #+#    #+#             */
/*   Updated: 2021/01/15 11:54:26 by vintran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		c_bpos_apos(t_params prm, char c)
{
	t_pos	var;

	//printf("bpos apos\n");
	init_var_apos_char(prm, &var, 1);
	while (var.space--)
		ft_putchar(' ');
	ft_putchar(c);
	return (var.ret);
}

int		c_bpos_aneg_or_noafter(t_params prm, char c)
{
	t_pos	var;

	//printf("bpos aneg\n");
	init_var_aneg_char(prm, &var, 1);
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

	//printf("bneg aneg\n");
	init_var_aneg_char(prm, &var, 1);
	ft_putchar(c);
	while (var.space--)
		ft_putchar(' ');
	return (var.ret);
}

int		c_bneg_apos(t_params prm, char c)
{
	int		i;
	t_pos	var;

	//printf("bneg apos\n");
	i = 0;
	init_var_apos_char(prm, &var, 1);
	ft_putchar(c);
	//printf("space = %d\n", var.space);
	while (var.space--)
		ft_putchar(' ');
	return (var.ret);
}
