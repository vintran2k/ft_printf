/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <vintran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 15:20:45 by vintran           #+#    #+#             */
/*   Updated: 2020/11/27 15:49:48 by vintran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_var_apos_p(t_params prm, t_pos *var, unsigned long long addr)
{
	var->len = addrlen(addr) + 2;
	var->zero = 0;
	var->space = 0;
	if (prm.after > var->len)
		var->zero = prm.after - var->len;
	if (prm.before < 0)
		prm.before = -(prm.before);
	if (prm.before > (var->zero + var->len))
		var->space = prm.before - (var->zero + var->len);
	var->ret = var->len + var->space + var->zero;
//	printf("   NBLEN = %d  ZERO = %d  SPACE = %d  RET = %d  |", var->len, var->zero, var->space, var->ret);
}

void	init_var_aneg_p(t_params prm, t_pos *var, unsigned long long addr)
{
	var->len = addrlen(addr) + 2;
	if (prm.before < 0)
		prm.before = -(prm.before);
	var->space = 0;
	if (prm.before > var->len)
		var->space = prm.before - var->len;
	if (prm.before > var->len)
		var->ret = prm.before;
	else
		var->ret = var->len;
//	printf("   NBLEN = %d  SPACE = %d  RET = %d  |", var->len, var->space, var->ret);
}

int		p_bpos_apos(t_params prm, unsigned long long addr)
{
	t_pos var;

	init_var_apos_p(prm, &var, addr);
    while (var.space-- > 0)
        ft_putchar(' ');
    while (var.zero-- > 0)
        ft_putchar('0');
	print_addr(addr);
    return (var.ret);
}

int		p_bpos_aneg(t_params prm, unsigned long long addr)
{
	t_pos var;

	init_var_aneg_p(prm, &var, addr);
	while (var.space-- > 0)
		ft_putchar(prm.zero_arg);
	print_addr(addr);
	return (var.ret);
}

int		p_bneg_aneg(t_params prm, unsigned long long addr)
{
	t_pos var;

	init_var_aneg_p(prm, &var, addr);
	print_addr(addr);
	while (var.space-- > 0)
		ft_putchar(' ');
	return (var.ret);
}

int		p_bneg_apos(t_params prm, unsigned long long addr)
{
	t_pos var;

	init_var_apos_p(prm, &var, addr);
	while (var.zero-- > 0)
		ft_putchar('0');
	print_addr(addr);
	while (var.space-- > 0)
		ft_putchar(' ');
	return (var.ret);
}

int		p_fonction_choice(t_params prm, unsigned long long addr)
{
	if (prm.before > 0)
	{
		if (prm.after < 0)
			return (p_bpos_aneg(prm, addr));
		else
			return (p_bpos_apos(prm, addr));
	}
	else
	{
		if (prm.after < 0)
			return (p_bneg_aneg(prm, addr));
		else
			return (p_bneg_apos(prm, addr));
	}
	return (0);
}

int		parsing_p(const char *format, t_params *prm)
{
	unsigned long long addr;

	format++;
	get_flag_args(format, prm);
	addr = (unsigned long long)va_arg(*(prm->args), void *);
	return (p_fonction_choice(*prm, addr));
}
