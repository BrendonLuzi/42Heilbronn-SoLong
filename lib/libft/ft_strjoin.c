/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:19:08 by bluzi             #+#    #+#             */
/*   Updated: 2023/04/21 06:06:45 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*conc_s;
	size_t	len;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	conc_s = malloc(len + 1);
	if (!conc_s)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		conc_s[i] = s1[i];
		i++;
	}
	while (i < len)
	{
		conc_s[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	conc_s[i] = '\0';
	return (conc_s);
}
