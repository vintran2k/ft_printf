/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <vintran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 17:41:33 by vintran           #+#    #+#             */
/*   Updated: 2020/11/27 15:39:43 by vintran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hex(unsigned int nb, char flag)
{
	char 			*base_min;
	char 			*base_maj;

	base_min = "0123456789abcdef";
	base_maj = "0123456789ABCDEF";
	if (nb >= 16)
		ft_putnbr_hex(nb / 16, flag);
	if (flag == 'x')
		ft_putchar(base_min[nb % 16]);
	else
		ft_putchar(base_maj[nb % 16]);
}

void	ft_putnbr_u(unsigned int nb)
{
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

void	print_nb(int nb, char flag)
{
	if (flag == 'd' || flag == 'i')
		ft_putnbr(nb);
	else if (flag == 'u')
		ft_putnbr_u((unsigned int)nb);
	else
		ft_putnbr_hex(nb, flag);
}

void	print_addr(unsigned long long addr)
{
	char *base = "0123456789abcdef";

	if (!addr)
	{
		ft_putchar('0');
		ft_putchar('x');
		return ;
	}
	print_addr(addr / 16);
	ft_putchar(base[addr % 16]);
}

int		real_len(int nb, char flag)
{
	if (flag == 'd' || flag == 'i')
		return (nbr_len(nb));
	if (flag == 'u')
		return (nbr_unsigned_len(nb, 10));
	if (flag == 'x' || flag == 'X')
		return (nbr_unsigned_len(nb, 16));
	return (0);
}
