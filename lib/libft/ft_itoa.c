/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 05:58:14 by bluzi             #+#    #+#             */
/*   Updated: 2023/04/23 09:38:23 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size_num(int n)
{
	int	q;

	q = 1;
	if (n < 0)
		q++;
	while (n < -9 || n > 9)
	{
		q++;
		n = n / 10;
	}
	return (q);
}

static void	ft_fillnum(char *num, int n, int i, int q)
{
	while (q >= i)
	{	
		num[q--] = (n % 10) + '0';
		n = n / 10;
	}
}

char	*ft_itoa(int n)
{
	char	*num;
	int		q;
	int		i;

	i = 0;
	q = ft_size_num(n);
	num = malloc((q + 1) * sizeof(char));
	if (!num)
		return (NULL);
	num[q--] = '\0';
	if (n < 0)
	{
		num[i++] = '-';
		if (n == -2147483648)
		{	
			num[i++] = '2';
			n = -147483648;
		}
		n = -n;
	}
	ft_fillnum(num, n, i, q);
	return (num);
}
