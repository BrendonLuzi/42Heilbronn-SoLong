/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 01:38:12 by bluzi             #+#    #+#             */
/*   Updated: 2022/10/23 05:15:09 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*dst_t;
	const char	*t;

	if ((!dst && !src) || (!n && (!dst || !src)))
		return (NULL);
	dst_t = dst;
	t = src;
	i = n;
	if (src <= dst && src + n >= dst)
		while (i-- > 0)
			dst_t[i] = t[i];
	else
	{
		i = 0;
		while (i < n)
		{
			dst_t[i] = t[i];
			i++;
		}
	}
	return (dst);
}
