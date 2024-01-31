/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 21:54:41 by bluzi             #+#    #+#             */
/*   Updated: 2023/04/23 09:40:26 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

struct s_flag
{
	int	min_fw;
	int	max_fw;
	int	minus;
	int	zero;
	int	plus;
	int	blank;
	int	hash;
	int	point;
	int	len;
	int	print_len;
	int	nisnegative;
	int	fail;
};

struct s_flag	ft_max_field_width(char *s, struct s_flag flag);
struct s_flag	ft_min_field_width(char *s, struct s_flag flag);
struct s_flag	ft_flags(char *s, struct s_flag flag);

struct s_flag	ft_format_i(int n, struct s_flag flag, char c);
struct s_flag	ft_pre_print_i(unsigned int uns_n, struct s_flag flag, char c);
struct s_flag	ft_format_u_i(unsigned int n, struct s_flag flag, char c);
struct s_flag	ft_format_s(const char *str, struct s_flag flag);
struct s_flag	ft_format_p(void *ptr, struct s_flag flag);

struct s_flag	ft_print_c(unsigned char c, struct s_flag flag);
struct s_flag	ft_print_n(unsigned int n, struct s_flag flag, char c);
struct s_flag	ft_print_p(unsigned long long n, struct s_flag flag, int size);
struct s_flag	ft_print_precision(struct s_flag flag, int size, char zero);
struct s_flag	ft_print_pad(struct s_flag flag, int size);

unsigned int	ft_n_power(unsigned int n, unsigned int e);
unsigned int	ft_size_n(unsigned int n, unsigned int base);
unsigned int	strlen_printf(const char *s);
struct s_flag	ft_init_flag(void);
struct s_flag	ft_reinit_flag(struct s_flag flag);

struct s_flag	ft_percentage(struct s_flag flag);
struct s_flag	ft_pre(const char *format, va_list args, struct s_flag flag);
int				ft_printf(const char *format, ...);

#endif