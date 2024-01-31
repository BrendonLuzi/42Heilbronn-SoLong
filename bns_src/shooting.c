/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shooting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:52:20 by bluzi             #+#    #+#             */
/*   Updated: 2023/05/24 18:50:17 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	player_shooting(t_sl *sl, mlx_t *mlx, mlx_key_data_t keydata)
{
	t_object	*bullet;

	if (keydata.action == MLX_PRESS && sl -> data -> bullet_c)
	{
		if (keydata.key == MLX_KEY_D)
		{
			bullet = make_bullet(sl, mlx, 1, 0);
			bullet_movement(sl, bullet);
		}
		else if (keydata.key == MLX_KEY_A)
		{
			bullet = make_bullet(sl, mlx, -1, 0);
			bullet_movement(sl, bullet);
		}
		else if (keydata.key == MLX_KEY_W)
		{
			bullet = make_bullet(sl, mlx, 0, -1);
			bullet_movement(sl, bullet);
		}
		else if (keydata.key == MLX_KEY_S)
		{
			bullet = make_bullet(sl, mlx, 0, 1);
			bullet_movement(sl, bullet);
		}
	}
}

t_object	*make_bullet(t_sl *sl, mlx_t *mlx, int dx, int dy)
{
	t_object	*bullet;
	t_coord		p_coord;
	t_coord		b_coord;

	p_coord = sl -> player -> coord;
	bullet = create_object(sl, p_coord.x, p_coord.y, 'B');
	bullet -> orientation.x = dx;
	bullet -> orientation.y = dy;
	if (dx > 0)
		create_image(mlx, &bullet -> img, IMG_BULLET_RIGHT);
	else if (dx < 0)
		create_image(mlx, &bullet -> img, IMG_BULLET_LEFT);
	else if (dy > 0)
		create_image(mlx, &bullet -> img, IMG_BULLET_DOWN);
	else if (dy < 0)
		create_image(mlx, &bullet -> img, IMG_BULLET_UP);
	b_coord = bullet -> coord;
	mlx_image_to_window(mlx, bullet -> img, b_coord.x * 64, b_coord.y * 64);
	add_object(&sl -> bullet, bullet);
	sl -> data -> bullet_c--;
	return (bullet);
}
