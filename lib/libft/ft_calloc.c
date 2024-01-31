/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 02:04:59 by bluzi             #+#    #+#             */
/*   Updated: 2022/11/21 16:47:52 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*t;

	t = malloc(size * count);
	if (t == NULL || (count != 0 && (((size * count) / count != size))))
		return (NULL);
	ft_bzero(t, size * count);
	return (t);
}
