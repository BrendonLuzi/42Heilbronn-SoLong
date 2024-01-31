/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 00:24:27 by bluzi             #+#    #+#             */
/*   Updated: 2023/05/24 16:24:37 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	parse_map(t_sl *sl, t_sl_data *data, char *mapfile)
{
	char	*line;
	int		fd;
	int		y;

	y = 0;
	check_file_name(sl, mapfile);
	get_height(sl, mapfile, data);
	sl -> map = (char **)ft_calloc(data -> height + 1, sizeof(char *));
	if (!sl -> map)
		sl_exit(sl, ALLOC_FAIL, EXIT_FAILURE);
	fd = open_file(sl, mapfile);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (ft_strchr(line, '\n'))
			*ft_strchr(line, '\n') = '\0';
		check_line(sl, line, y);
		sl -> map[y++] = line;
	}
	sl -> map[y] = NULL;
	check_elements(sl, sl -> collectible);
	close(fd);
}

void	check_elements(t_sl *sl, t_object *collectible)
{
	t_coord		*temp;

	if (!sl -> player)
		sl_exit(sl, MAP_NO_PLAYER, EXIT_FAILURE);
	if (sl -> player -> next)
		sl_exit(sl, MAP_MULTI_PLAYER, EXIT_FAILURE);
	if (!sl -> exit)
		sl_exit(sl, MAP_NO_EXIT, EXIT_FAILURE);
	if (sl -> exit -> next)
		sl_exit(sl, MAP_MULTI_EXIT, EXIT_FAILURE);
	temp = find_path(sl, sl -> map, sl -> exit -> coord);
	if (!temp)
		sl_exit(sl, MAP_UNREACH_EXIT, EXIT_FAILURE);
	free(temp);
	if (!collectible)
		sl_exit(sl, MAP_NO_COLLEC, EXIT_FAILURE);
	collectible = sl -> collectible;
	while (collectible)
	{
		temp = find_path(sl, sl -> map, collectible -> coord);
		if (!temp)
			sl_exit(sl, MAP_UNREACH_COLLEC, EXIT_FAILURE);
		free(temp);
		collectible = collectible -> next;
	}
}

void	check_file_name(t_sl *sl, char *mapfile)
{
	char	*extension;

	extension = ft_strchr(mapfile, '.');
	if (!extension || ft_strcmp(extension, ".ber"))
		sl_exit(sl, INVAL_FILE, EXIT_FAILURE);
}

void	check_line(t_sl *sl, char *line, int y)
{
	int	x;

	x = 0;
	if ((int)ft_strlen(line) != sl -> data -> width)
		sl_exit(sl, MAP_NO_RECT, EXIT_FAILURE);
	if (y == 0 || y == sl -> data -> height)
	{
		while (*line)
			if (*line++ != '1')
				sl_exit(sl, MAP_NO_BORD, EXIT_FAILURE);
	}
	else
	{
		while (line[x])
		{
			if ((x == 0 || !line[x + 1]) && line[x] != '1')
				sl_exit(sl, MAP_NO_BORD, EXIT_FAILURE);
			if (!is_valid_char(sl, line[x], x, y))
				sl_exit(sl, MAP_INVAL_CHAR, EXIT_FAILURE);
			x++;
		}
	}
}

int	is_valid_char(t_sl *sl, char c, int x, int y)
{
	if (c == '0')
		return (1);
	if (c == '1')
		return (sl -> data -> wall_c++, 1);
	if (c == 'P')
		return (add_object(&sl -> player, create_object(sl, x, y, c)), 1);
	if (c == 'E')
		return (add_object(&sl -> exit, create_object(sl, x, y, c)), 1);
	if (c == 'C')
		return (add_object(&sl -> collectible, create_object(sl, x, y, c)), 1);
	if (c == '!')
	{
		sl -> data -> bullet_c++;
		return (add_object(&sl -> enemy, create_object(sl, x, y, c)), 1);
	}
	return (0);
}
