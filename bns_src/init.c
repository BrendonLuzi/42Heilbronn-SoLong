/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 00:18:08 by bluzi             #+#    #+#             */
/*   Updated: 2023/05/24 19:55:49 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_sl	*init_so_long(void)
{
	t_sl	*sl;

	sl = (t_sl *)ft_calloc(1, sizeof(t_sl));
	if (!sl)
		sl_exit(NULL, ALLOC_FAIL, EXIT_FAILURE);
	sl -> data = (t_sl_data *)ft_calloc(1, sizeof(t_sl_data));
	if (!sl -> data)
		sl_exit(sl, ALLOC_FAIL, EXIT_FAILURE);
	sl -> data -> steps_c = -1;
	sl -> player = NULL;
	sl -> exit = NULL;
	sl -> enemy = NULL;
	sl -> collectible = NULL;
	sl -> bullet = NULL;
	return (sl);
}

void	create_background(t_sl *sl, t_sl_data *data, char **map)
{
	int			x;
	int			y;

	x = 0;
	y = 0;
	create_image(sl -> mlx, &sl -> grass, IMG_BACKGROUND);
	create_image(sl -> mlx, &sl -> wall, IMG_WALL);
	while (y < data -> height)
	{
		x = 0;
		while (x < data -> width)
		{
			if (map[y][x] != '1' || 1)
				mlx_image_to_window(sl -> mlx, sl -> grass, x * 64, y * 64);
			if (map[y][x] == '1')
				mlx_image_to_window(sl -> mlx, sl -> wall, x * 64, y * 64);
			x++;
		}
		y++;
	}
	player_steps(sl);
}

void	init_window(t_sl *sl, t_sl_data *data)
{
	int	width;
	int	height;

	width = data -> width * 64;
	height = data -> height * 64;
	sl -> mlx = mlx_init(width, height + 64, "so_long", false);
	if (!sl -> mlx)
		sl_exit(sl, MLX_FAIL, EXIT_FAILURE);
}
