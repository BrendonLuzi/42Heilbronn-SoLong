/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:34:04 by bluzi             #+#    #+#             */
/*   Updated: 2023/04/23 09:47:47 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_pretrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	n;

	n = 0;
	i = 0;
	while (n < ft_strlen(set) && s1[i])
	{
		if (s1[i] == set[n++])
		{
			i++;
			n = 0;
		}
	}
	return (i);
}

static size_t	ft_posttrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	n;

	n = 0;
	i = ft_strlen(s1);
	while (n < ft_strlen(set))
	{
		if (s1[i - 1] == set[n++])
		{
			i--;
			n = 0;
		}
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1)
		return (NULL);
	i = ft_pretrim(s1, set);
	j = ft_strlen(s1);
	if (i >= j || (!s1 && !set))
	{
		str = malloc(sizeof(char));
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	j = ft_posttrim(s1, set);
	str = ft_substr(s1, i, j - i);
	if (!str)
		return (NULL);
	return (str);
}
