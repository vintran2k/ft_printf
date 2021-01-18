/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <vintran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 10:38:00 by vintran           #+#    #+#             */
/*   Updated: 2020/11/27 15:05:37 by vintran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		nbr_len(int nb)
{
	int len;

	len = 0;
	if (nb == 0)
		len++;
	while (nb)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

int		nbr_unsigned_len(unsigned int nb, unsigned int base)
{
	int len;

	len = 1;
	while (nb >= base)
	{
		nb /= base;
		len++;
	}
	return (len);
}

int		addrlen(unsigned long long addr)
{
	int len;

	len = 0;
	while (addr)
	{
		addr /= 16;
		len++;
	}
	return (len);
}

int		flag_len(const char *format, char flag)
{
	int i;

	i = 0;
	while (format[i] && format[i] != flag)
		i++;
	return (i);
}

size_t	strlen(const char *s)
{
	size_t i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
		return (i);
	}
	return (6);
}
