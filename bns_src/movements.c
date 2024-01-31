/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 02:25:54 by bluzi             #+#    #+#             */
/*   Updated: 2023/05/24 19:34:49 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	if (obj_id == ID_ENEMY)
		lose(sl);
	else if (obj_id == ID_EXIT && !sl -> collectible)
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

void	enemy_movement(t_sl *sl, t_object *enemy)
{
	t_coord	*new_coord;
	int		obj_id;

	while (enemy)
	{
		new_coord = find_path(sl, sl -> map, enemy -> coord);
		if (new_coord)
		{
			obj_id = find_object_id(sl, new_coord -> x, new_coord -> y);
			if (obj_id == ID_PLAYER)
				return (lose(sl), free(new_coord));
			enemy_hit(sl, *new_coord, enemy -> coord, obj_id);
			if (obj_id != ID_ENEMY && obj_id != ID_BULLET)
			{
				change_enemy_side(sl, enemy, new_coord -> x - enemy -> coord.x);
				enemy -> coord = *new_coord;
				enemy -> img -> instances -> x = new_coord -> x * 64;
				enemy -> img -> instances -> y = new_coord -> y * 64;
			}
			free(new_coord);
		}
		enemy = enemy -> next;
	}
}

void	enemy_hit(t_sl *sl, t_coord new_coord, t_coord en_coord, int obj_id)
{
	if (obj_id == ID_BULLET)
	{
		remove_object(sl, new_coord.x, new_coord.y, obj_id);
		remove_object(sl, en_coord.x, en_coord.y, ID_ENEMY);
	}
}

void	bullet_movement(t_sl *sl, t_object *bullet)
{
	int		obj_id;
	int		new_x;
	int		new_y;

	while (bullet)
	{
		new_x = bullet -> coord.x + bullet -> orientation.x;
		new_y = bullet -> coord.y + bullet -> orientation.y;
		obj_id = find_object_id(sl, new_x, new_y);
		if (obj_id == ID_ENEMY)
			remove_object(sl, new_x, new_y, obj_id);
		if (sl -> map[new_y][new_x] == '1' || obj_id == ID_ENEMY)
			remove_object(sl, bullet -> coord.x, bullet -> coord.y, ID_BULLET);
		else if (obj_id != ID_ENEMY)
		{
			bullet -> coord.x = new_x;
			bullet -> coord.y = new_y;
			bullet -> img -> instances -> x = new_x * 64;
			bullet -> img -> instances -> y = new_y * 64;
		}
		if (bullet)
			bullet = bullet -> next;
	}
}
