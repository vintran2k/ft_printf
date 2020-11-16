/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_flag2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <vintran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:25:23 by vintran           #+#    #+#             */
/*   Updated: 2020/11/17 00:03:11 by vintran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		s_bpos_apos(int before, int after, char *str)
{
	int i;
	int len;
	int space;
	int ret;

	i = 0;
	len = (int)ft_strlen(str);
	space = 0;
	len = after > len ? len : after;
	if (before > len)
		space = before - len;
	ret = space + len;
	while (space--)
		ft_putchar(' ');
	while (i < len)
		ft_putchar(str[i++]);
	return (ret);
}

int		s_bpos_aneg_or_noafter(int before, char *str)
{
	int len;
	int space;
	int ret;

	len = (int)ft_strlen(str);
	space = before > len ? before - len : 0;
	ret = space + len;
	while (space--)
		ft_putchar(' ');
	ft_putstr(str);
	return (ret);
}

int		s_bneg_aneg(int before, char *str)
{
	int len;
	int space;
	int ret;

	before = -before;
	len = (int)ft_strlen(str);
	space = before > len ? before - len : 0;
	ret = len + space;
	ft_putstr(str);
	while (space--)
		ft_putchar(' ');
	return (ret);
}

int		s_bneg_apos(int before, int after, char *str)
{
	int len;
	int space;
	int ret;
	int i;

	before = -before;
	len = (int)ft_strlen(str);
	len = after > len ? len : after;
	space = 0;
	if (before > len)
		space = before - len;
	ret = len + space;
	i = 0;
	while (len--)
		ft_putchar(str[i++]);
	while (space--)
		ft_putchar(' ');
	return (ret);
}
