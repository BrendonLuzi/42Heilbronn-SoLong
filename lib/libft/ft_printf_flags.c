/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 06:18:34 by bluzi             #+#    #+#             */
/*   Updated: 2022/10/30 06:26:48 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

struct s_flag	ft_max_field_width(char *s, struct s_flag flag)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{	
		if (s[i] >= '0' && s[i] <= '9')
		{
			flag.len++;
			i++;
		}
		else
			break ;
	}
	while (i > 0)
		flag.max_fw = flag.max_fw + ((s[i-- - 1] - '0') * ft_n_power(10, j++));
	return (flag);
}

struct s_flag	ft_min_field_width(char *s, struct s_flag flag)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{	
		if (s[i] >= '0' && s[i] <= '9')
		{
			flag.len++;
			i++;
		}
		else if (s[i] == '.')
		{
			flag.point = 1;
			flag.len++;
			flag = ft_max_field_width(s + i + 1, flag);
			break ;
		}
		else
			break ;
	}
	while (i > 0)
		flag.min_fw = flag.min_fw + ((s[i-- - 1] - '0') * ft_n_power(10, j++));
	return (flag);
}

struct s_flag	ft_flags(char *s, struct s_flag flag)
{
	while (s[flag.len])
	{	
		if (s[flag.len] == '-')
			flag.minus = 1;
		else if (s[flag.len] == '0' && flag.zero != 1)
			flag.zero = 1;
		else if (s[flag.len] == '0' && flag.zero == 1)
			break ;
		else if (s[flag.len] == '+')
			flag.plus = 1;
		else if (s[flag.len] == ' ')
			flag.blank = 1;
		else if (s[flag.len] == '#')
			flag.hash = 1;
		else
			break ;
		flag.len++;
	}
	flag = ft_min_field_width(s + flag.len, flag);
	return (flag);
}
