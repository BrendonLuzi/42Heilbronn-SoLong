/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 02:25:54 by bluzi             #+#    #+#             */
/*   Updated: 2023/05/24 16:20:01 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_movement(t_sl *sl, t_object *player, int dx, int dy)
{
	int	obj_id;
	int	new_x;
	int	new_y;

	new_x = player -> coord.x + dx;
	new_y = player -> coord.y + dy;
	if (dx && dx != player -> orientation.x)
		change_player_side(sl, player, dx);
	if (sl -> map[new_y][new_x] == '1')
		return ;
	obj_id = find_object_id(sl, new_x, new_y);
	if (obj_id == ID_EXIT && !sl -> collectible)
		win(sl);
	else
	{	
		if (obj_id == ID_COLLECTIBLE)
			remove_object(sl, new_x, new_y, obj_id);
		player -> coord.x = new_x;
		player -> coord.y = new_y;
		player -> img -> instances -> x = new_x * 64;
		player -> img -> instances -> y = new_y * 64;
		player_steps(sl);
	}
}
