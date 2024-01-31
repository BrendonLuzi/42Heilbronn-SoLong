/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 03:29:35 by bluzi             #+#    #+#             */
/*   Updated: 2023/05/24 16:24:37 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	in_queue_pri(t_node **queue, t_node *node)
{
	t_node	*current;
	t_node	*temp;

	if (!node)
		return ;
	if (!queue || !*queue)
	{
		*queue = node;
		return ;
	}
	current = *queue;
	while (current -> next && current -> next -> priority < node -> priority)
			current = current -> next;
	if (current -> priority > node -> priority)
	{
		node -> next = current;
		*queue = node;
	}
	else
	{
		temp = current -> next;
		current -> next = node;
		node -> next = temp;
	}
}

t_node	*de_queue_pri(t_node **queue)
{
	t_node	*node;

	if (!queue || !*queue)
		return (NULL);
	node = *queue;
	*queue = node -> next;
	node -> next = NULL;
	return (node);
}

t_node	*create_node(t_sl *sl, int x, int y, t_coord goal)
{
	t_node	*node;

	node = ft_calloc(1, sizeof(t_node));
	if (!node)
		sl_exit(sl, ALLOC_FAIL, EXIT_FAILURE);
	node -> coord.x = x;
	node -> coord.y = y;
	node -> next = NULL;
	node -> previous_step = NULL;
	node -> h_cost = h_distance(x, y, goal.x, goal.y);
	node -> g_cost = 0;
	node -> priority = 0;
	return (node);
}

t_node	*de_queue_neighbour(t_node **queue, t_node *parent, int x, int y)
{
	t_node	*current;
	t_node	*previous;

	if (!queue || !*queue)
		return (NULL);
	current = *queue;
	previous = NULL;
	while (current && !(current -> coord.x == x && current -> coord.y == y))
	{
		previous = current;
		current = current -> next;
	}
	if (current && current -> coord.x == x && current -> coord.y == y)
	{
		if (!previous)
			*queue = current -> next;
		else
			previous -> next = current -> next;
		current -> next = NULL;
		current -> previous_step = parent;
		current -> g_cost = parent -> g_cost + 1;
		current -> priority = current -> g_cost + current -> h_cost;
		return (current);
	}
	return (NULL);
}

void	pop_queues(t_sl *sl, t_queue *queue, char **map, t_coord goal)
{
	int	x;
	int	y;

	queue -> frontier = NULL;
	queue -> visited = NULL;
	queue -> not_visited = NULL;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (y == sl -> player -> coord.y && x == sl -> player -> coord.x)
			{
				in_queue_pri(&queue -> frontier, \
					create_node(sl, x, y, goal));
				queue -> frontier -> previous_step = NULL;
			}
			else if (map[y][x] != '1')
				in_queue_pri(&queue -> not_visited, \
					create_node(sl, x, y, goal));
			x++;
		}
		y++;
	}
}
