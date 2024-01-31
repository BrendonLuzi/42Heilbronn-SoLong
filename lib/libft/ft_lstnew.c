/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 03:32:53 by bluzi             #+#    #+#             */
/*   Updated: 2023/04/25 05:02:36 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*t_new;

	t_new = malloc(sizeof(t_list));
	if (!t_new)
		return (NULL);
	t_new -> content = content;
	t_new -> next = NULL;
	return (t_new);
}
