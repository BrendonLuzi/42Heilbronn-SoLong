/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_formats.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 05:40:04 by bluzi             #+#    #+#             */
/*   Updated: 2023/04/23 09:50:47 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

struct s_flag	ft_format_i(int n, struct s_flag flag, char c)
{
	unsigned int	uns_n;
	unsigned int	size;

	if (n < 0)
	{
		flag.nisnegative++;
		uns_n = (unsigned int)-n;
	}
	else
		uns_n = n;
	if (c == 'c' && n >= 0)
		size = 1;
	else if ((n == 0 && flag.max_fw == 0 && flag.point) || (n < 0 && c == 'c'))
		size = 0;
	else
		size = ft_size_n(uns_n, 10);
	if (!flag.minus)
		flag = ft_print_pad(flag, size);
	if (c == 'c')
		flag = ft_print_c((unsigned char)n, flag);
	else
		flag = ft_pre_print_i(uns_n, flag, c);
	if (flag.minus)
		flag = ft_print_pad(flag, size);
	return (flag);
}

struct s_flag	ft_pre_print_i(unsigned int uns_n, struct s_flag flag, char c)
{
	if (flag.plus && !flag.nisnegative)
		flag = ft_print_c('+', flag);
	else if (flag.blank && !flag.nisnegative)
		flag = ft_print_c(' ', flag);
	if (!(uns_n == 0 && flag.max_fw == 0 && flag.point))
	{
		if (flag.nisnegative)
			flag = ft_print_c('-', flag);
		flag = ft_print_n(uns_n, flag, c);
	}
	return (flag);
}

struct s_flag	ft_format_u_i(unsigned int n, struct s_flag flag, char c)
{
	int	base_size;
	int	size;

	if (c == 'u')
		base_size = 10;
	else
		base_size = 16;
	if (n == 0 && flag.hash)
	{
		flag.hash = 0;
		size = 1;
	}
	if (n == 0 && (flag.max_fw == 0 && flag.point))
		size = 0;
	else
		size = ft_size_n(n, base_size);
	if (!flag.minus)
		flag = ft_print_pad(flag, size);
	if (!(n == 0 && flag.max_fw == 0 && flag.point))
		flag = ft_print_n(n, flag, c);
	if (flag.minus)
		flag = ft_print_pad(flag, size);
	return (flag);
}

struct s_flag	ft_format_s(const char *str, struct s_flag flag)
{
	int	i;
	int	len;

	i = 0;
	if (!str)
	{
		flag = ft_format_s("(null)", flag);
		return (flag);
	}
	else if ((int)strlen_printf(str) > flag.max_fw && flag.point)
		len = flag.max_fw;
	else
		len = strlen_printf(str);
	flag.max_fw = 0;
	flag.blank = 0;
	if (!flag.minus)
		flag = ft_print_pad(flag, len);
	while (i < len)
		flag = ft_print_c(str[i++], flag);
	if (flag.minus)
		flag = ft_print_pad(flag, len);
	return (flag);
}

struct s_flag	ft_format_p(void *ptr, struct s_flag flag)
{
	unsigned int				size;
	unsigned long long			n;

	size = 1;
	flag.hash = 0;
	n = (unsigned long long)ptr;
	while (n >= 16)
	{
		size++;
		n = n / 16;
	}
	n = (unsigned long long)ptr;
	if (!flag.minus)
		flag = ft_print_pad(flag, size + 2);
	flag = ft_print_p(n, flag, size);
	if (flag.minus)
		flag = ft_print_pad(flag, size + 2);
	return (flag);
}
