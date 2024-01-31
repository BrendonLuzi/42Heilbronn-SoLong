/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 22:23:35 by bluzi             #+#    #+#             */
/*   Updated: 2022/10/25 02:42:14 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	i;
	char	nl;

	if (!s)
		return ;
	i = 0;
	nl = '\n';
	while (s[i])
		write(fd, s + i++, sizeof(char));
	write(fd, &nl, sizeof(char));
}
