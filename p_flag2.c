/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_flag2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <vintran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 13:12:47 by vintran           #+#    #+#             */
/*   Updated: 2021/01/19 12:06:04 by vintran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		p_bpos(t_params prm, unsigned long long addr)
{
	t_pos var;

	init_var_p(prm, &var, addr);
	while (var.space-- > 0)
		ft_putchar(' ');
	print_addr(addr);
	return (var.ret);
}

int		p_bneg(t_params prm, unsigned long long addr)
{
	t_pos var;

	init_var_p(prm, &var, addr);
	print_addr(addr);
	while (var.space-- > 0)
		ft_putchar(' ');
	return (var.ret);
}
