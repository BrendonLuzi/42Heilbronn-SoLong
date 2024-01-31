/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 02:53:27 by bluzi             #+#    #+#             */
/*   Updated: 2022/11/24 20:51:22 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_l;

	if (!src && !dstsize)
		return (0);
	if (!dst && !dstsize)
		return (ft_strlen(src));
	dst_l = ft_strlen(dst);
	if (dstsize == 0 || dst_l > dstsize - 1)
		return (ft_strlen(src) + dstsize);
	i = 0;
	while (i < dstsize - dst_l - 1 && src[i])
	{
		dst[dst_l + i] = src[i];
		i++;
	}
	dst[dst_l + i] = '\0';
	return (ft_strlen(src) + dst_l);
}
