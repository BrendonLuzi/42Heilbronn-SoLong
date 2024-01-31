/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 00:52:52 by bluzi             #+#    #+#             */
/*   Updated: 2023/05/24 17:08:05 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	get_height(t_sl *sl, char *mapfile, t_sl_data *data)
{
	int		fd;
	char	*line;

	fd = open_file(sl, mapfile);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		else
			data -> height++;
		if (!data -> width)
			data -> width = ft_strlen(line) - 1;
		free(line);
	}
	close(fd);
}

int	open_file(t_sl *sl, char *file_name)
{
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 1)
		sl_exit(sl, NO_OPEN_FILE, EXIT_FAILURE);
	return (fd);
}

void	player_steps(t_sl *sl)
{
	ft_printf("Number of movements:\t%d\n", ++sl -> data -> steps_c);
}
