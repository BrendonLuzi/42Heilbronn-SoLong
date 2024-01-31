/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 04:54:58 by bluzi             #+#    #+#             */
/*   Updated: 2023/05/24 16:21:25 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_window(t_sl *sl)
{
	mlx_t	*mlx;

	mlx = sl -> mlx;
	update_image(mlx, sl -> collectible);
	if (!sl -> collectible)
		update_image(mlx, sl -> exit);
	update_image(mlx, sl -> player);
}

void	update_image(mlx_t *mlx, t_object *obj)
{
	t_coord	coord;

	while (obj)
	{
		coord = obj -> coord;
		mlx_image_to_window(mlx, obj -> img, coord.x * 64, coord.y * 64);
		obj = obj -> next;
	}
}

void	init_obj_imgs(t_sl *sl, mlx_t *mlx)
{
	t_object	*temp;

	temp = sl -> collectible;
	while (temp)
	{
		create_image(mlx, &temp -> img, IMG_COLLECTIBLE);
		temp = temp -> next;
	}
	temp = sl -> exit;
	create_image(mlx, &temp -> img, IMG_EXIT);
	temp = sl -> player;
	create_image(mlx, &temp -> img, IMG_PLAYER_RIGHT);
}

void	create_image(mlx_t *mlx, mlx_image_t **img, char *img_file)
{
	xpm_t	*xpm;

	if (*img)
		mlx_delete_image(mlx, *img);
	xpm = mlx_load_xpm42(img_file);
	*img = mlx_texture_to_image(mlx, &xpm -> texture);
	mlx_delete_xpm42(xpm);
}
