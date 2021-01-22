/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <vintran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 13:14:30 by vintran           #+#    #+#             */
/*   Updated: 2021/01/19 11:31:18 by vintran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_var_p(t_params prm, t_pos *var, unsigned long long addr)
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
}
