/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <vintran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:31:44 by vintran           #+#    #+#             */
/*   Updated: 2020/11/26 17:54:57 by vintran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef	struct	s_params
{
	va_list		*args;
	char		flag;
	int 		before;
	int			after;
	char		zero_arg;
}				t_params;

typedef struct	s_pos
{
	int len;
	int space;
	int zero;
	int ret;
}				t_pos;

int		ft_printf(const char *format, ...);
void	ft_putnbr(int nb);
void	ft_putchar(char c);
size_t	ft_strlen(const char *s);
int		nbr_len(int nb);
int		nbr_unsigned_len(unsigned int nb, unsigned int base);
void	ft_putstr(char *str);
int		ft_atoi(const char *str);
void	ft_putnbr_hex(unsigned int nb, char flag);
void	ft_putnbr_u(unsigned int nb);
void	*ft_memchr(const void *s, int c, size_t n);
int		flag_len(const char *format, char flag);
void	print_nb(int nb, char flag);
int		real_len(int nb, char flag);
int		special_zero(int before);
int		is_star(const char *format, char flag);
int		is_star_ret_one(const char *format, t_params *prm);
int		is_star_ret_two(const char *format, t_params *prm);
int		get_flag_args(const char *format, t_params *prm);
void	init_params(t_params *prm, va_list *args, char flag);
void	init_var_apos(t_params prm, t_pos *var, int nb);
void	init_var_aneg(t_params prm, t_pos *var, int nb);
void	init_var_apos_s(t_params prm, t_pos *var, char *str);
void	init_var_aneg_s(t_params prm, t_pos *var, char *str);
int		parsing_d_i_u_x_X_flag(const char *format, t_params *prm);
int		print_d_i_u_x_X(const char *format, va_list *args, char flag);
int		d_bpos_apos(t_params prm, int nb);
int		d_bpos_aneg(t_params prm, int nb, char c);
int		d_bneg_aneg(t_params prm, int nb);
int		d_bneg_apos(t_params prm, int nb);
int		parsing_sflag(const char *format, t_params *prm);
int		print_s(const char *format, va_list *args);
int		s_bpos_apos(t_params prm, char *str);
int		s_bpos_aneg_or_noafter(t_params prm, char *str);
int		s_bneg_aneg(t_params prm, char *str);
int		s_bneg_apos(t_params prm, char *str);

#endif
