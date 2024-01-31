/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_star.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 04:46:10 by bluzi             #+#    #+#             */
/*   Updated: 2023/05/15 19:21:05 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_list(t_list **lst)
{
	t_list	*next_ptr;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{	
		next_ptr = (*lst)-> next;
		free(*lst);
		*lst = next_ptr;
	}
	*lst = NULL;
}

t_coord	*find_path(t_sl *sl, char **map, t_coord goal)
{
	t_node	*current;
	t_coord	*next_coord;

	sl -> queue = ft_calloc(1, sizeof(t_queue));
	if (!sl -> queue)
		sl_exit(sl, ALLOC_FAIL, EXIT_FAILURE);
	next_coord = ft_calloc(1, sizeof(t_coord));
	if (!next_coord)
		sl_exit(sl, ALLOC_FAIL, EXIT_FAILURE);
	pop_queues(sl, sl -> queue, map, goal);
	while (sl -> queue -> frontier && \
		!is_goal_node(sl -> queue -> frontier -> coord, goal))
	{
		current = de_queue_pri(&sl -> queue -> frontier);
		in_queue_pri(&sl -> queue -> visited, current);
		check_neighbours(sl -> queue, current);
	}
	if (sl -> queue -> frontier && sl -> queue -> frontier -> previous_step)
	{
		*next_coord = sl -> queue -> frontier -> previous_step -> coord;
		return (free_queue(&sl -> queue), next_coord);
	}
	else
		return (free_queue(&sl -> queue), free(next_coord), NULL);
}

int	is_goal_node(t_coord current_coord, t_coord goal_coord)
{
	if (current_coord.x == goal_coord.x && current_coord.y == goal_coord.y)
		return (1);
	else
		return (0);
}

void	check_neighbours(t_queue *queue, t_node *current)
{
	in_queue_pri(&queue -> frontier, \
		de_queue_neighbour(&queue -> not_visited, \
			current, current -> coord.x + 1, current -> coord.y));
	in_queue_pri(&queue -> frontier, \
		de_queue_neighbour(&queue -> not_visited, \
			current, current -> coord.x - 1, current -> coord.y));
	in_queue_pri(&queue -> frontier, \
		de_queue_neighbour(&queue -> not_visited, \
			current, current -> coord.x, current -> coord.y + 1));
	in_queue_pri(&queue -> frontier, \
		de_queue_neighbour(&queue -> not_visited, \
			current, current -> coord.x, current -> coord.y - 1));
}

int	h_distance(int x, int y, int exit_x, int exit_y)
{
	int	distance;

	if (exit_x - x > 0)
		distance = exit_x - x;
	else
		distance = x - exit_x;
	if (exit_y - y > 0)
		distance += exit_y - y;
	else
		distance += y - exit_y;
	return (distance);
}
