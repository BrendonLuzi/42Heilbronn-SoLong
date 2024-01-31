/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 21:03:48 by bluzi             #+#    #+#             */
/*   Updated: 2023/05/24 20:11:39 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	free_queue(t_queue **queue_ptr)
{
	t_node	*temp;
	t_queue	*queue;

	queue = *queue_ptr;
	while (queue -> frontier)
	{
		temp = queue -> frontier;
		queue -> frontier = queue -> frontier -> next;
		free(temp);
	}
	while (queue -> visited)
	{
		temp = queue -> visited;
		queue -> visited = queue -> visited -> next;
		free(temp);
	}
	while (queue -> not_visited)
	{
		temp = queue -> not_visited;
		queue -> not_visited = queue -> not_visited -> next;
		free(temp);
	}
	free(queue);
	*queue_ptr = NULL;
}

void	free_obj(t_sl *sl, t_object **head)
{
	t_object	*temp;
	t_object	*object;

	if (head)
	{
		object = *head;
		while (object)
		{
			temp = object;
			if (temp -> img)
				mlx_delete_image(sl -> mlx, temp -> img);
			object = object -> next;
			free(temp);
			temp = NULL;
		}
		*head = NULL;
	}
}

void	free_objects(t_sl *sl)
{
	if (sl -> steps)
		mlx_delete_image(sl -> mlx, sl -> steps);
	if (sl -> wall)
		mlx_delete_image(sl -> mlx, sl -> wall);
	if (sl -> win)
		mlx_delete_image(sl -> mlx, sl -> win);
	if (sl -> lose)
		mlx_delete_image(sl -> mlx, sl -> lose);
	if (sl -> grass)
		mlx_delete_image(sl -> mlx, sl -> grass);
	free_obj(sl, &sl -> player);
	free_obj(sl, &sl -> exit);
	free_obj(sl, &sl -> enemy);
	free_obj(sl, &sl -> collectible);
	free_obj(sl, &sl -> bullet);
}

void	sl_exit(t_sl *sl, char *error_msg, int exit_status)
{
	if (error_msg)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		ft_putstr_fd(error_msg, STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
	}
	if (sl)
	{
		if (sl -> map)
			free_map(sl -> map);
		if (sl -> queue)
			free_queue(&sl -> queue);
		free_objects(sl);
		if (sl -> mlx)
			mlx_terminate(sl -> mlx);
		if (sl -> data)
			free(sl -> data);
		free(sl);
	}
	exit(exit_status);
}
