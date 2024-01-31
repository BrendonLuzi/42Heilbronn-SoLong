/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 04:09:32 by bluzi             #+#    #+#             */
/*   Updated: 2023/05/24 20:06:40 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_sl		*sl;
	mlx_t		*mlx;

	sl = param;
	mlx = sl -> mlx;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		sl_exit(sl, NULL, EXIT_SUCCESS);
	if (!sl -> data -> end)
	{
		if (mlx_is_key_down(mlx, MLX_KEY_UP))
			player_movement(sl, sl -> player, 0, -1);
		else if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
			player_movement(sl, sl -> player, 0, 1);
		else if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
			player_movement(sl, sl -> player, -1, 0);
		else if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
			player_movement(sl, sl -> player, 1, 0);
		player_shooting(sl, mlx, keydata);
	}
}

void	generic_hook(void *param)
{
	static int	g_time = 0;
	t_sl		*sl;

	sl = param;
	if (!sl -> data -> end)
	{
		g_time++;
		animate_walls(sl, g_time, 30, 3);
		if (!sl -> collectible)
			animate_obj(sl -> exit, g_time, 20, 10);
		animate_obj(sl -> collectible, g_time, 20, 5);
		animate_obj(sl -> player, g_time, 20, 10);
		animate_obj(sl -> enemy, g_time, 15, 10);
		if (!(g_time % 10))
			bullet_movement(sl, sl -> bullet);
		if (!(g_time % 15))
			enemy_movement(sl, sl -> enemy);
		g_time = g_time % 120;
	}
}
