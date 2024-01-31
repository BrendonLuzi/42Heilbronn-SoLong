/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 23:32:58 by bluzi             #+#    #+#             */
/*   Updated: 2022/10/23 05:36:11 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*t;

	t = (char *)s;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)t[i] == (unsigned char)c)
			return (&t[i]);
		i++;
	}
	if (i < n && t[i] == c)
		return (&t[i]);
	return (NULL);
}
