/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 22:12:57 by bluzi             #+#    #+#             */
/*   Updated: 2022/10/25 02:41:42 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;
	int		len;

	if (!s)
		return ;
	i = 0;
	len = (int)ft_strlen(s);
	while ((i < len) && s[i])
	{
		f(i, s + i);
		i++;
	}
}
