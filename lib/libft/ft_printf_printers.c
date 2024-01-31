/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 04:58:54 by bluzi             #+#    #+#             */
/*   Updated: 2023/04/23 09:40:47 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

struct s_flag	ft_print_c(unsigned char c, struct s_flag flag)
{
	int	check;

	check = 0;
	if (!flag.fail)
	{
		check = write (1, &c, sizeof(unsigned char));
		flag.print_len++;
	}
	if (check == -1)
		flag.fail = -1;
	return (flag);
}

struct s_flag	ft_print_n(unsigned int n, struct s_flag flag, char c)
{
	int				size;
	unsigned int	num;
	char			*base;

	if (c == 'x')
		base = "0123456789abcdef\0";
	else if (c == 'X')
		base = "0123456789ABCDEF\0";
	else
		base = "0123456789\0";
	size = ft_size_n(n, strlen_printf(base));
	if (flag.hash && (c == 'x' || c == 'X') && n)
	{
		flag = ft_print_c('0', flag);
		flag = ft_print_c(c, flag);
	}
	flag = ft_print_precision(flag, size, base[0]);
	while (size > 0)
	{
		num = ((n / ft_n_power(strlen_printf(base), size - 1)) \
			% strlen_printf(base));
		flag = ft_print_c(base[num], flag);
		size--;
	}
	return (flag);
}

struct s_flag	ft_print_p(unsigned long long n, struct s_flag flag, int size)
{
	char				*base;
	unsigned long long	digit;
	unsigned long long	power;
	int					exp;

	base = "0123456789abcdef\0";
	flag = ft_print_c('0', flag);
	flag = ft_print_c('x', flag);
	flag = ft_print_precision(flag, size, base[0]);
	while (size > 0)
	{
		power = 1;
		exp = size - 1;
		while (exp > 0)
		{
			power = power * 16;
			exp--;
		}
		digit = (n / power) % 16;
		flag = ft_print_c(base[digit], flag);
		size--;
	}
	return (flag);
}

struct s_flag	ft_print_pad(struct s_flag flag, int size)
{
	int	diff;

	if (size > flag.max_fw)
		diff = flag.min_fw - size;
	else
		diff = flag.min_fw - flag.max_fw;
	if ((flag.plus && !flag.nisnegative) || (flag.blank && !flag.nisnegative)
		|| flag.hash)
		diff--;
	if (flag.hash)
		diff--;
	if (flag.nisnegative)
		diff--;
	if ((flag.zero && !flag.minus && !flag.point))
	{
		flag.max_fw = flag.max_fw + diff + size;
		return (flag);
	}
	while (diff-- > 0)
		flag = ft_print_c(' ', flag);
	return (flag);
}

struct s_flag	ft_print_precision(struct s_flag flag, int size, char zero)
{
	int	max_fw;

	max_fw = flag.max_fw;
	while (max_fw > size)
	{
		flag = ft_print_c(zero, flag);
		max_fw--;
	}
	return (flag);
}
