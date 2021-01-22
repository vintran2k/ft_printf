/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <vintran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 15:20:45 by vintran           #+#    #+#             */
/*   Updated: 2021/01/19 11:35:28 by vintran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		special_bpos(int before)
{
	int ret;

	before *= -1;
	if (before > 3)
		ret = before;
	else
		ret = 3;
	before -= 3;
	ft_putstr("0x0");
	if (before > 0)
		while (before--)
			ft_putchar(' ');
	return (ret);
}

int		special_bneg(int before)
{
	int ret;

	if (before > 3)
		ret = before;
	else
		ret = 3;
	before -= 3;
	if (before > 0)
		while (before--)
			ft_putchar(' ');
	ft_putstr("0x0");
	return (ret);
}

int		special_null(int before)
{
	int ret;

	if (before < 0)
		ret = special_bpos(before);
	else
		ret = special_bneg(before);
	return (ret);
}

int		parsing_p(const char *format, t_params *prm)
{
	unsigned long long addr;

	format++;
	prm->n = get_flag_args(format, prm);
	addr = (unsigned long long)va_arg(*(prm->args), void *);
	if (!addr && prm->n != 3)
		return (special_null(prm->before));
	if (prm->before > 0)
		return (p_bpos(*prm, addr));
	return (p_bneg(*prm, addr));
}
