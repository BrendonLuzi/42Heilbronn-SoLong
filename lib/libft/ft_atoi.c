/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 00:42:24 by bluzi             #+#    #+#             */
/*   Updated: 2022/10/18 01:53:35 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_p10(int e)
{
	int	n;

	n = 1;
	while (e > 1)
	{
		n = n * 10;
		e--;
	}
	return (n);
}

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int	n;
	int	i;
	int	sign;
	int	len;

	n = 0;
	i = 0;
	len = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i + len] >= '0' && str[i + len] <= '9')
		len++;
	while (str[i] >= '0' && str[i] <= '9')
		n = n + ((str[i++] - '0') * ft_p10(len--));
	return (n * sign);
}
