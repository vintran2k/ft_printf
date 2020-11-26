/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_i_u_x_X_flag2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <vintran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 11:39:16 by vintran           #+#    #+#             */
/*   Updated: 2020/11/26 17:47:34 by vintran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		d_bpos_apos(t_params prm, int nb)
{
	t_pos var;

	init_var_apos(prm, &var, nb);
    while (var.space-- > 0)
        ft_putchar(' ');
	if (prm.flag == 'd' || prm.flag == 'i')
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb = -nb;
		}
	}
    while (var.zero-- > 0)
        ft_putchar('0');
	print_nb(nb, prm.flag);
    return (var.ret);
}

int		d_bpos_aneg(t_params prm, int nb, char c)
{
	t_pos var;

	init_var_aneg(prm, &var, nb);
	if (c == '0' && nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	while (var.space-- > 0)
		ft_putchar(c);
	print_nb(nb, prm.flag);
	return (var.ret);
}

int		d_bneg_aneg(t_params prm, int nb)
{
	t_pos var;

	init_var_aneg(prm, &var, nb);
	print_nb(nb, prm.flag);
	while (var.space-- > 0)
		ft_putchar(' ');
	return (var.ret);
}

int		d_bneg_apos(t_params prm, int nb)
{
	t_pos var;

	init_var_apos(prm, &var, nb);
	if (prm.flag == 'd' || prm.flag == 'i')
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb = -nb;
		}
	}
	while (var.zero-- > 0)
		ft_putchar('0');
	print_nb(nb, prm.flag);
	while (var.space-- > 0)
		ft_putchar(' ');
	return (var.ret);
}
