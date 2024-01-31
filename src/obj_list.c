/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 00:20:48 by bluzi             #+#    #+#             */
/*   Updated: 2023/05/24 16:19:36 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_object	**get_list(t_sl *sl, int obj_id)
{
	if (obj_id == ID_PLAYER)
		return (&sl -> player);
	else if (obj_id == ID_EXIT)
		return (&sl -> exit);
	else if (obj_id == ID_COLLECTIBLE)
		return (&sl -> collectible);
	else
		return (NULL);
}

int	search_list(t_object *list, int x, int y)
{
	while (list)
	{
		if (list -> coord.x == x && list -> coord.y == y)
			return (1);
		list = list -> next;
	}
	return (0);
}
