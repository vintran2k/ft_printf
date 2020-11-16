/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_flag2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <vintran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 11:39:16 by vintran           #+#    #+#             */
/*   Updated: 2020/11/16 16:12:42 by vintran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		d_bpos_apos(int before, int after, int nb)
{
	int nblen;
    int space;
    int zero;
    int ret;

    space = 0;
	nblen = nbr_len(nb);
	zero = after > nblen ? after - nblen : 0;
    nb < 0 ? nblen++ : 0;
    space = before - (zero + nblen);
    space = (space < 0) ? 0 : space;
    ret = nblen + space + zero;
    while (space-- > 0)
        ft_putchar(' ');
    nb < 0 ? ft_putchar('-') : 0;
    while (zero-- > 0)
        ft_putchar('0');

    nb < 0 ? ft_putnbr(-nb) : ft_putnbr(nb);
    return (ret);
}

int		d_bpos_aneg(int before, int nb)
{
	int nblen;
	int space;
	int ret;

	nblen = nbr_len(nb);
	space = 0;
	if (before > nblen)
		space = before - nblen;
	nb < 0 ? space-- : 0;
	while (space-- > 0)
		ft_putchar(' ');
	ft_putnbr(nb);
	nb < 0 ? nblen++ : 0;
	ret = before > nblen ? before : nblen;
	return (ret);
}

int		d_bneg_aneg(int before, int nb)
{
	int nblen;
	int space;
	int ret;

	nblen = nbr_len(nb);
	space = 0;
	before = -before;
	if (before > nblen)
		space = before - nblen;
	nb < 0 ? space-- : 0;
	ft_putnbr(nb);
	while (space-- > 0)
		ft_putchar(' ');
	nb < 0 ? nblen++ : 0;
	ret = before > nblen ? before : nblen;
	return (ret);
}

int		d_bneg_apos(int before, int after, int nb)
{
	int nblen;
	int space;
	int zero;
	int ret;

	nblen = nbr_len(nb);
	space = 0;
	zero = 0;
	if (after > nblen)
		zero = after - nblen;
	nb < 0 ? nblen++ : 0;
	before = -before;
	space = before - (zero + nblen);
	space < 0 ? space = 0 : 0;
	ret = nblen + space + zero;
	nb < 0 ? ft_putchar('-') : 0;
	while (zero-- > 0)
		ft_putchar('0');
	nb < 0 ? ft_putnbr(-nb) : ft_putnbr(nb);
	while (space-- > 0)
		ft_putchar(' ');
	return (ret);
}
