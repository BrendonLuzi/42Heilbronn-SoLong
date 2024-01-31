/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 22:26:43 by bluzi             #+#    #+#             */
/*   Updated: 2023/05/24 16:24:37 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	win(t_sl *sl)
{
	mlx_t	*mlx;

	mlx = sl -> mlx;
	sl -> data -> end = 1;
	free_objects(sl);
	create_image(sl -> mlx, &sl -> win, IMG_WIN);
	mlx_image_to_window(mlx, sl -> win, \
		mlx -> width / 2 - sl -> win -> width / 2, \
			mlx -> height / 2 - sl -> win -> height / 2);
}

void	lose(t_sl *sl)
{
	mlx_t	*mlx;

	mlx = sl -> mlx;
	sl -> data -> end = 1;
	free_objects(sl);
	create_image(sl -> mlx, &sl -> lose, IMG_LOSE);
	mlx_image_to_window(mlx, sl -> lose, \
		mlx -> width / 2 - sl -> lose -> width / 2, \
			mlx -> height / 2 - sl -> lose -> height / 2);
}
