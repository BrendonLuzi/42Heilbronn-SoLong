/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utilities.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 04:45:13 by bluzi             #+#    #+#             */
/*   Updated: 2023/04/23 09:40:26 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_n_power(unsigned int n, unsigned int e)
{
	unsigned int	res;

	res = 1;
	while (e > 0)
	{
		res = res * n;
		e--;
	}
	return (res);
}

unsigned int	ft_size_n(unsigned int n, unsigned int base)
{
	unsigned int	q;

	q = 1;
	if (base == 0)
		return (q);
	while (n >= base)
	{
		q++;
		n = n / base;
	}
	return (q);
}

unsigned int	strlen_printf(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

struct s_flag	ft_init_flag(void)
{
	struct s_flag	ini_flag;

	ini_flag.min_fw = 0;
	ini_flag.max_fw = 0;
	ini_flag.minus = 0;
	ini_flag.zero = 0;
	ini_flag.plus = 0;
	ini_flag.blank = 0;
	ini_flag.hash = 0;
	ini_flag.point = 0;
	ini_flag.len = 0;
	ini_flag.print_len = 0;
	ini_flag.nisnegative = 0;
	ini_flag.fail = 0;
	return (ini_flag);
}

struct s_flag	ft_reinit_flag(struct s_flag flag)
{
	flag.min_fw = 0;
	flag.max_fw = 0;
	flag.minus = 0;
	flag.zero = 0;
	flag.plus = 0;
	flag.blank = 0;
	flag.hash = 0;
	flag.point = 0;
	flag.len = 0;
	flag.nisnegative = 0;
	return (flag);
}
