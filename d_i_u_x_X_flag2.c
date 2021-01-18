/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_i_u_x_X_flag2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <vintran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 11:39:16 by vintran           #+#    #+#             */
/*   Updated: 2021/01/15 12:32:19 by vintran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		d_bpos_apos(t_params prm, int nb)
{
	t_pos var;
	//printf("bpos apos\n");
	init_var_apos(prm, &var, nb);
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

int		d_bpos_aneg(t_params prm, int nb)
{
	t_pos var;
	//printf("bpos aneg\n");
	if (prm.zero_arg == '0' && prm.after == 0 && prm.n == 3) 
		prm.zero_arg = ' ';
	init_var_aneg(prm, &var, nb);
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

int		d_bneg_aneg(t_params prm, int nb)
{
	t_pos var;
	//printf("bneg aneg\n");
	init_var_aneg(prm, &var, nb);
	print_nb(nb, prm.flag);
	while (var.space-- > 0)
		ft_putchar(' ');
	return (var.ret);
}

int		d_bneg_apos(t_params prm, int nb)
{
	t_pos var;
	//printf("bneg apos\n");
	init_var_apos(prm, &var, nb);
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
