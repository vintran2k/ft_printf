/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <vintran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:31:44 by vintran           #+#    #+#             */
/*   Updated: 2021/01/20 17:03:32 by vintran          ###   ########.fr       */
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
	int			before;
	int			after;
	int			n;
	char		zero_arg;
}				t_params;

typedef struct	s_pos
{
	int			len;
	int			space;
	int			zero;
	int			ret;
}				t_pos;

int				ft_printf(const char *format, ...);
void			ft_putnbr(long nb);
void			ft_putchar(char c);
size_t			ft_strlen(const char *s);
int				nbr_len(long nb);
int				nbr_unsigned_len(unsigned int nb, unsigned int base);
int				addrlen(unsigned long long addr);
void			ft_putstr(char *str);
int				ft_atoi(const char *str);
void			ft_putnbr_hex(unsigned int nb, char flag);
void			ft_putnbr_u(unsigned int nb);
void			print_addr(unsigned long long addr);
void			*ft_memchr(const void *s, int c, size_t n);
int				flag_len(const char *format, char flag);
void			print_nb(long nb, char flag);
int				real_len(int nb, char flag);
int				special_zero(int before);
int				is_star(const char *format, char flag);
int				is_star_ret_one(const char *format, t_params *prm);
int				is_star_ret_two(const char *format, t_params *prm);
int				get_flag_args(const char *format, t_params *prm);
void			init_params(t_params *prm, va_list *args, char flag);
void			init_var_apos_diux(t_params prm, t_pos *var, int nb);
void			init_var_aneg_diux(t_params prm, t_pos *var, int nb);
void			init_var_apos_cs(t_params prm, t_pos *var, int length);
void			init_var_aneg_cs(t_params prm, t_pos *var, int length);
void			init_var_p(t_params prm, t_pos *var, unsigned long long addr);
int				parsing_diux(const char *format, t_params *prm);
int				print_diux(const char *format, va_list *args, char flag);
int				d_bpos_apos(t_params prm, long nb);
int				d_bpos_aneg(t_params prm, long nb);
int				d_bneg_aneg(t_params prm, long nb);
int				d_bneg_apos(t_params prm, long nb);
int				parsing_s(const char *format, t_params *prm);
int				print_s(const char *format, va_list *args);
int				s_bpos_apos(t_params prm, char *str);
int				s_bpos_aneg_or_noafter(t_params prm, char *str);
int				s_bneg_aneg(t_params prm, char *str);
int				s_bneg_apos(t_params prm, char *str);
int				parsing_c(const char *format, t_params *prm);
int				print_c(const char *format, va_list *args);
int				c_bpos_apos(t_params prm, char c);
int				c_bpos_aneg_or_noafter(t_params prm, char c);
int				c_bneg_aneg(t_params prm, char c);
int				c_bneg_apos(t_params prm, char c);
int				print_p(const char *format, va_list *args);
int				parsing_p(const char *format, t_params *prm);
int				p_bpos(t_params prm, unsigned long long addr);
int				p_bneg(t_params prm, unsigned long long addr);
int				c_fonction_choice(t_params prm, char c);
int				print_pourcent(const char *format, va_list *args);
int				pourcent_special_zero(int before);

#endif
