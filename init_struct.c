/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <vintran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 17:46:08 by vintran           #+#    #+#             */
/*   Updated: 2021/01/19 11:53:52 by vintran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_params(t_params *prm, va_list *args, char flag)
{
	prm->args = args;
	prm->flag = flag;
	prm->before = 0;
	prm->after = 0;
	prm->n = 0;
	prm->zero_arg = ' ';
}

void	init_var_apos_diux(t_params prm, t_pos *var, int nb)
{
	var->len = real_len(nb, prm.flag);
	var->zero = 0;
	var->space = 0;
	if (prm.after > var->len)
		var->zero = prm.after - var->len;
	if (nb < 0 && (prm.flag == 'd' || prm.flag == 'i'))
		var->len++;
	if (prm.before < 0)
		prm.before = -(prm.before);
	if (prm.before > (var->zero + var->len))
		var->space = prm.before - (var->zero + var->len);
	var->ret = var->len + var->space + var->zero;
}

void	init_var_aneg_diux(t_params prm, t_pos *var, int nb)
{
	var->len = real_len(nb, prm.flag);
	if (prm.before < 0)
		prm.before = -(prm.before);
	var->space = 0;
	if (prm.before > var->len)
		var->space = prm.before - var->len;
	if (nb < 0 && (prm.flag == 'd' || prm.flag == 'i'))
	{
		var->space--;
		var->len++;
	}
	if (prm.before > var->len)
		var->ret = prm.before;
	else
		var->ret = var->len;
}

void	init_var_apos_cs(t_params prm, t_pos *var, int length)
{
	var->len = length;
	if (prm.before < 0)
		prm.before = -(prm.before);
	if (prm.flag == 's' && prm.after < var->len)
		var->len = prm.after;
	var->space = 0;
	if (prm.before > var->len)
		var->space = prm.before - var->len;
	var->ret = var->space + var->len;
}

void	init_var_aneg_cs(t_params prm, t_pos *var, int length)
{
	var->len = length;
	if (prm.before < 0)
		prm.before = -(prm.before);
	var->space = 0;
	if (prm.before > var->len)
		var->space = prm.before - var->len;
	var->ret = var->len + var->space;
}
