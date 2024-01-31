/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:20:59 by bluzi             #+#    #+#             */
/*   Updated: 2023/04/23 04:46:28 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# include <stdio.h>
# include <fcntl.h>

# define  BUFFER_SIZE	1

void	*gnl_calloc(size_t count, size_t size);
size_t	ft_strlen_gnl(const char *s);
size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t dstsize);
int		ft_find_nl(const char *s);
int		ft_strealloc(char **str, size_t size);

char	*make_line(char **remainder, int nl_pos, int rem_len);
char	*get_next_line(int fd);

#endif
