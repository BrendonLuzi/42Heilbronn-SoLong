/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:54:52 by bluzi             #+#    #+#             */
/*   Updated: 2022/11/21 16:55:51 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	else if (start >= ft_strlen(s))
	{
		sub = (char *)malloc(1 * sizeof(char));
		if (!sub)
			return (NULL);
	}
	else if (len <= ft_strlen(s) - start)
		sub = (char *)malloc((len + 1) * sizeof(char));
	else
		sub = (char *)malloc((ft_strlen(s) - start + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	while (i < len && start + i < ft_strlen(s))
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
