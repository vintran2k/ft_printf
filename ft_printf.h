/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <vintran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:31:44 by vintran           #+#    #+#             */
/*   Updated: 2020/11/16 11:42:09 by vintran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
void	ft_putnbr(int nb);
void	ft_putchar(char c);
int		nbr_len(int nb);
void	ft_putstr(char *str);
int		ft_atoi(const char *str);
void	*ft_memchr(const void *s, int c, size_t n);
int		flag_len(const char *format, char flag);
int		is_star(const char *format, char flag);
int		is_star_ret_one(const char *format, int *before, int *after, va_list *args, char flag);
int		is_star_ret_two(const char *format, int *before, int *after, va_list *args, char flag);
int		get_flag_args(const char *format, int *before, int *after, va_list *args, char flag);
int		parsing_dflag(const char *format, va_list *args, char flag);
int		bpos_apos(int before, int after, int nb);
int		bpos_aneg(int before, int nb);
int		bneg_aneg(int before, int nb);
int		bneg_apos(int before, int after, int nb);
int		print_d(const char * format, va_list *args);

#endif
