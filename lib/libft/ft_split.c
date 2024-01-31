/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 21:07:07 by bluzi             #+#    #+#             */
/*   Updated: 2022/10/24 07:39:10 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_pre_num_split(char const *s, char c)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	if (!s)
		return (0);
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{		
		if (s[i] != c)
		{
			n++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (n);
}

static size_t	ft_len_word_split(char const *s, char c)
{
	size_t	j;

	j = 0;
	while (s[j] != c && s[j])
		j++;
	return (j);
}

static void	ft_free_split(char **spl, size_t n)
{
	while (n > 0)
		free(spl[--n]);
	free(spl);
}

static void	ft_fill_split(char *src, char *dst, size_t len)
{	
	size_t	i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char	**ft_split(char const *s, char c)
{
	char	**spl;
	size_t	i;
	size_t	m;

	m = 0;
	i = 0;
	spl = malloc((ft_pre_num_split(s, c) + 1) * sizeof(char *));
	if (!s || !spl)
		return (NULL);
	while (m < ft_pre_num_split(s, c))
	{
		while (s[i] == c)
			i++;
		spl[m] = malloc((ft_len_word_split(s + i, c) + 1) * sizeof(char));
		if (!spl[m])
		{
			ft_free_split(spl, m);
			return (NULL);
		}
		ft_fill_split((char *)(s + i), spl[m++], ft_len_word_split(s + i, c));
		i = i + ft_len_word_split(s + i, c);
	}
	spl[m] = NULL;
	return (spl);
}
