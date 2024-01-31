/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 08:29:34 by bluzi             #+#    #+#             */
/*   Updated: 2023/04/26 00:34:21 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next_ptr;

	if (!lst || !*lst || !del)
		return ;
	while (*lst)
	{	
		next_ptr = (*lst) ->  next;
		ft_lstdelone(*lst, del);
		*lst = next_ptr;
	}
	*lst = NULL;
}
