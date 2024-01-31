/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 04:54:13 by bluzi             #+#    #+#             */
/*   Updated: 2023/05/24 16:19:12 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_object(t_object **obj_list, t_object *obj)
{
	t_object	*temp;

	if (!obj_list || !*obj_list)
		*obj_list = obj;
	else
	{
		temp = *obj_list;
		while (temp -> next)
			temp = temp -> next;
		temp -> next = obj;
	}
}

t_object	*create_object(t_sl *sl, int x, int y, char c)
{
	t_object	*object;

	object = ft_calloc(1, sizeof(t_object));
	if (!object)
		sl_exit(sl, ALLOC_FAIL, EXIT_FAILURE);
	if (c == 'C')
		object -> id = ID_COLLECTIBLE;
	else if (c == 'E')
		object -> id = ID_EXIT;
	else if (c == 'P')
		object -> id = ID_PLAYER;
	else
		return (free(object), NULL);
	object -> coord.x = x;
	object -> coord.y = y;
	return (object);
}

int	find_object_id(t_sl *sl, int x, int y)
{
	if (search_list(sl -> player, x, y))
		return (ID_PLAYER);
	else if (search_list(sl -> exit, x, y))
		return (ID_EXIT);
	else if (search_list(sl -> collectible, x, y))
		return (ID_COLLECTIBLE);
	else
		return (0);
}

void	remove_object(t_sl *sl, int x, int y, int obj_id)
{
	t_object	**list;
	t_object	*current;
	t_object	*previous;

	list = get_list(sl, obj_id);
	current = *list;
	previous = NULL;
	while (current && !(current -> coord.x == x && current -> coord.y == y))
	{
		previous = current;
		current = current -> next;
	}
	if (current && current -> coord.x == x && current -> coord.y == y)
	{
		if (!previous)
			*list = current -> next;
		else
			previous -> next = current -> next;
		mlx_delete_image(sl -> mlx, current -> img);
		free(current);
	}
	if (obj_id == ID_COLLECTIBLE)
		update_exit(sl, sl -> exit);
}

void	update_exit(t_sl *sl, t_object *exit)
{
	t_coord	e_coord;
	mlx_t	*mlx;

	mlx = sl -> mlx;
	e_coord = exit -> coord;
	if (!sl -> collectible)
		mlx_image_to_window(mlx, exit -> img, e_coord.x * 64, e_coord.y * 64);
}
