/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 00:04:46 by bluzi             #+#    #+#             */
/*   Updated: 2023/05/24 19:54:58 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	leaks(void)
// {
// 	system("leaks so_long");
// 	atexit(&leaks);
// }

int	main(int argc, char *argv[])
{
	t_sl	*sl;

	if (argc != 2)
		sl_exit(NULL, ARG_ERR, EXIT_FAILURE);
	sl = init_so_long();
	parse_map(sl, sl -> data, argv[1]);
	init_window(sl, sl -> data);
	create_background(sl, sl -> data, sl -> map);
	init_obj_imgs(sl, sl -> mlx);
	update_window(sl);
	mlx_key_hook(sl -> mlx, &key_hook, sl);
	mlx_loop_hook(sl -> mlx, &generic_hook, sl);
	mlx_loop(sl -> mlx);
	sl_exit(sl, NULL, EXIT_SUCCESS);
}
