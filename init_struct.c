/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <vintran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 17:46:08 by vintran           #+#    #+#             */
/*   Updated: 2021/01/15 11:46:02 by vintran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_params(t_params *prm, va_list *args, char flag)
{
	prm->args = args;
	prm->flag = flag;
	prm->before = 0;
	prm->after = 0;
	prm->zero_arg = ' ';
}

void	init_var_apos(t_params prm, t_pos *var, int nb)
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
//	printf("   NBLEN = %d  ZERO = %d  SPACE = %d  RET = %d  |", var->len, var->zero, var->space, var->ret);
}

void	init_var_aneg(t_params prm, t_pos *var, int nb)
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
//	printf("   NBLEN = %d  SPACE = %d  RET = %d  |", var->len, var->space, var->ret);
}

void	init_var_apos_char(t_params prm, t_pos *var, int len)
{
	var->len = len;
	if (prm.before < 0)
		prm.before = -(prm.before);
	if (prm.after < var->len)
		var->len = prm.after;
	var->space = 0;
	if (prm.before > var->len)
		var->space = prm.before - var->len;
	var->ret = var->space + var->len;
}

void	init_var_aneg_char(t_params prm, t_pos *var, int len)
{
	var->len = len;
	if (prm.before < 0)
		prm.before = -(prm.before);
	var->space = 0;
	if (prm.before > var->len)
		var->space = prm.before - var->len;
	var->ret = var->len + var->space;
}
