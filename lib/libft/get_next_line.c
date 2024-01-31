/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:19:54 by bluzi             #+#    #+#             */
/*   Updated: 2023/04/23 04:46:28 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*make_line(char **remainder, int nl_pos, int rem_len)
{
	char	*line;
	char	*buf;

	if (!nl_pos || nl_pos == rem_len)
	{
		line = gnl_calloc(rem_len + 1, sizeof(char));
		ft_strlcpy_gnl(line, *remainder, rem_len + 1);
		free(*remainder);
		*remainder = NULL;
	}
	else
	{
		line = gnl_calloc(nl_pos + 1, sizeof(char));
		buf = gnl_calloc(rem_len - nl_pos + 1, sizeof(char));
		ft_strlcpy_gnl(line, *remainder, nl_pos + 1);
		ft_strlcpy_gnl(buf, *remainder + nl_pos, rem_len - nl_pos + 1);
		free(*remainder);
		*remainder = buf;
	}
	return (line);
}

void	set_null(char **pointer)
{
	if (*pointer)
	{
		free(*pointer);
		*pointer = NULL;
	}
}

char	*read_line(char **remainder, int fd, size_t size)
{
	int		r;
	char	*line;

	r = 1;
	line = NULL;
	while (r && *remainder)
	{
		r = read(fd, *remainder + size, BUFFER_SIZE);
		if (r < 0 || (r == 0 && !(**remainder)))
		{
			set_null(remainder);
			return (NULL);
		}
		size += r;
		if (ft_find_nl(*remainder) || (r == 0 && (**remainder)))
		{
			line = make_line(remainder,
					ft_find_nl(*remainder), ft_strlen_gnl(*remainder));
			return (line);
		}
		ft_strealloc(remainder, size + BUFFER_SIZE + 1);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	size_t		size;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	size = ft_strlen_gnl(remainder);
	if (!remainder)
	{
		remainder = gnl_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!remainder)
			return (NULL);
	}	
	else
		ft_strealloc(&remainder, size + BUFFER_SIZE + 1);
	return (read_line(&remainder, fd, size));
}
