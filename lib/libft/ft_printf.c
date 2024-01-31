/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 07:01:20 by bluzi             #+#    #+#             */
/*   Updated: 2023/02/15 14:03:13 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

struct s_flag	ft_percentage(struct s_flag flag)
{
	if (!flag.minus)
		flag = ft_print_pad(flag, 1);
	flag = ft_print_c('%', flag);
	if (flag.minus)
		flag = ft_print_pad(flag, 1);
	return (flag);
}

struct s_flag	ft_pre(const char *format, va_list args, struct s_flag flag)
{
	while (*format && !flag.fail)
	{
		if (*format == '%')
		{
			format++;
			flag = ft_flags((char *)format, flag);
			format = format + flag.len;
			if (*format == 'c' || *format == 'd' || *format == 'i')
				flag = ft_format_i(va_arg(args, int), flag, *format);
			else if (*format == 'u' || *format == 'x' || *format == 'X')
				flag = ft_format_u_i(va_arg(args, unsigned int), flag, *format);
			else if (*format == 's')
				flag = ft_format_s(va_arg(args, const char *), flag);
			else if (*format == 'p')
				flag = ft_format_p(va_arg(args, void *), flag);
			else if (*format == '%')
				flag = ft_percentage(flag);
		}
		else
			flag = ft_print_c(*format, flag);
		format++;
		flag = ft_reinit_flag(flag);
	}
	return (flag);
}

int	ft_printf(const char *format, ...)
{
	struct s_flag	flag;
	va_list			args;

	va_start(args, format);
	flag = ft_init_flag();
	flag = ft_pre(format, args, flag);
	va_end(args);
	if (flag.fail)
		return (flag.fail);
	return (flag.print_len);
}
