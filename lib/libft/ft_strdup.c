/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 03:45:06 by bluzi             #+#    #+#             */
/*   Updated: 2022/10/21 00:09:26 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cpy;

	cpy = malloc(ft_strlen(s1) + 1);
	if (!cpy)
		return (NULL);
	ft_strlcpy(cpy, s1, ft_strlen(s1) + 1);
	return (cpy);
}
