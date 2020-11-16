/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <vintran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:31:44 by vintran           #+#    #+#             */
/*   Updated: 2020/11/17 00:04:05 by vintran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
void	ft_putnbr(int nb);
void	ft_putchar(char c);
size_t	ft_strlen(const char *s);
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
int		print_d(const char * format, va_list *args);
int		d_bpos_apos(int before, int after, int nb);
int		d_bpos_aneg(int before, int nb);
int		d_bneg_aneg(int before, int nb);
int		d_bneg_apos(int before, int after, int nb);
int		parsing_sflag(const char *format, va_list *args, char flag);
int		print_s(const char *format, va_list *args);
int		s_bpos_apos(int before, int after, char *str);
int		s_bpos_aneg_or_noafter(int before, char *str);
int		s_bneg_aneg(int before, char *str);
int		s_bneg_apos(int before, int after, char *str);

#endif
