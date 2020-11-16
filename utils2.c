/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <vintran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 10:38:00 by vintran           #+#    #+#             */
/*   Updated: 2020/11/16 16:02:34 by vintran          ###   ########.fr       */
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
		len ++;
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

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
