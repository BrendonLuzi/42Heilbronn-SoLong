/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:51:15 by bluzi             #+#    #+#             */
/*   Updated: 2023/05/24 18:48:12 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	change_player_side(t_sl *sl, t_object *player, int dx)
{
	mlx_t	*mlx;
	t_coord	p_coord;

	mlx = sl -> mlx;
	p_coord = player -> coord;
	mlx_delete_image(mlx, player -> img);
	if (dx < 0)
		create_image(mlx, &player -> img, IMG_PLAYER_LEFT);
	if (dx > 0)
		create_image(mlx, &player -> img, IMG_PLAYER_RIGHT);
	player -> orientation.x = dx;
	mlx_image_to_window(mlx, player -> img, p_coord.x * 64, p_coord.y * 64);
}

void	change_enemy_side(t_sl *sl, t_object *enemy, int dx)
{
	mlx_t	*mlx;
	t_coord	e_coord;

	if (dx)
	{
		mlx = sl -> mlx;
		e_coord = enemy -> coord;
		mlx_delete_image(mlx, enemy -> img);
		if (dx < 0)
			create_image(mlx, &enemy -> img, IMG_ENEMY_LEFT);
		if (dx > 0)
			create_image(mlx, &enemy -> img, IMG_ENEMY_RIGHT);
		enemy -> orientation.x = dx;
		mlx_image_to_window(mlx, enemy -> img, e_coord.x * 64, e_coord.y * 64);
	}
}

void	animate_obj(t_object *object, int time, int interval, int dy)
{
	if (!(time % interval))
	{
		if (!(time % (2 * interval)))
			dy *= -1;
		while (object)
		{
			object -> img -> instances -> y += dy;
			object = object -> next;
		}
	}
}

void	animate_walls(t_sl *sl, int time, int interval, int dy)
{
	int	x;

	if (!(time % interval))
	{
		x = 0;
		if (!(time % (2 * interval)))
			while (x < (sl -> data -> wall_c + sl -> data -> width))
				sl -> wall -> instances[x++].y += dy;
		else
			while (x <= (sl -> data -> wall_c + sl -> data -> width))
				sl -> wall -> instances[x++].y -= dy;
	}
}
