/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 22:26:04 by bluzi             #+#    #+#             */
/*   Updated: 2022/10/23 04:44:53 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;

	if (n < 0)
	{
		num = (unsigned int)(-n);
		ft_putchar_fd('-', fd);
	}
	else
		num = (unsigned int)n;
	if (num >= 10)
		ft_putnbr_fd((num / 10), fd);
	ft_putchar_fd((char)(num % 10 + '0'), fd);
}
