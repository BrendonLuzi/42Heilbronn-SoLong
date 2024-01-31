/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:11:43 by bluzi             #+#    #+#             */
/*   Updated: 2023/05/24 19:46:35 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>

# include <ctype.h>

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/libft.h"

//	object IDs
# define ID_PLAYER			1
# define ID_EXIT			2	
# define ID_COLLECTIBLE		3
# define ID_ENEMY			4	
# define ID_BULLET			5

//	error messages
# define ARG_ERR			"Invalid number of arguments"
# define ALLOC_FAIL			"Allocation failed!"
# define INVAL_FILE			"Invalid file name or extension!"
# define NO_OPEN_FILE		"Open file failed!"
# define MAP_NO_RECT		"Invalid map: not a rectangle!"
# define MAP_NO_BORD		"Invalid map: border incomplete!"
# define MAP_INVAL_CHAR		"Invalid map: invalid character!"
# define MLX_FAIL			"Initialization of MLX window failed!"
# define MAP_NO_PLAYER		"Invalid map: no player found!"
# define MAP_MULTI_PLAYER	"Invalid map: more than one player found!"
# define MAP_NO_EXIT		"Invalid map: no exit found!"
# define MAP_MULTI_EXIT		"Invalid map: more than one exit found!"
# define MAP_UNREACH_EXIT	"Invalid map: unreachable exit!"
# define MAP_NO_COLLEC		"Invalid map: no collectible found!"
# define MAP_UNREACH_COLLEC	"Invalid map: unreachable collectible!"

// xpm42 images paths
# define IMG_BACKGROUND		"imgs/grass_64.xpm42"
# define IMG_WALL			"imgs/fire_64.xpm42"
# define IMG_PLAYER_RIGHT	"imgs/chicken_hat_64.xpm42"
# define IMG_PLAYER_LEFT	"imgs/chicken_hat_left_64.xpm42"
# define IMG_EXIT			"imgs/coop.xpm42"
# define IMG_COLLECTIBLE	"imgs/watermelon_64.xpm42"
# define IMG_ENEMY_RIGHT	"imgs/fox.xpm42"
# define IMG_ENEMY_LEFT		"imgs/fox_left.xpm42"
# define IMG_BULLET_RIGHT	"imgs/egg_right.xpm42"
# define IMG_BULLET_LEFT	"imgs/egg_left.xpm42"
# define IMG_BULLET_UP		"imgs/egg_up.xpm42"
# define IMG_BULLET_DOWN	"imgs/egg_down.xpm42"
# define IMG_LOSE			"imgs/loss.xpm42"
# define IMG_WIN			"imgs/win.xpm42"

typedef struct s_coord
{
	int					x;
	int					y;
}	t_coord;

typedef struct s_sl_data
{
	int					width;
	int					height;
	int					wall_c;
	int					bullet_c;
	int					steps_c;
	int					end;
}	t_sl_data;

typedef struct s_object
{
	int					id;
	t_coord				orientation;
	mlx_image_t			*img;
	t_coord				coord;
	struct s_object		*next;
}	t_object;

typedef struct s_a_node
{
	t_coord				coord;
	int					g_cost;
	int					h_cost;
	int					priority;
	struct s_a_node		*previous_step;
	struct s_a_node		*next;
}	t_node;

typedef struct s_a_queue
{
	t_node			*frontier;
	t_node			*visited;
	t_node			*not_visited;
}	t_queue;

typedef struct s_sl
{
	mlx_t				*mlx;
	char				**map;
	struct s_sl_data	*data;
	mlx_image_t			*steps;
	mlx_image_t			*wall;
	mlx_image_t			*grass;
	mlx_image_t			*win;
	mlx_image_t			*lose;
	t_object			*player;
	t_object			*exit;
	t_object			*enemy;
	t_object			*collectible;
	t_object			*bullet;
	t_queue				*queue;
}	t_sl;

//	init funcs
t_sl		*init_so_long(void);
void		init_window(t_sl *sl, t_sl_data *data);
void		create_background(t_sl *sl, t_sl_data *data, char **map);

//	hooks
void		generic_hook(void *param);
void		key_hook(mlx_key_data_t keydata, void *param);

//	object handling
void		add_object(t_object **obj_list, t_object *obj);
t_object	*create_object(t_sl *sl, int x, int y, char c);
void		remove_object(t_sl *sl, int x, int y, int obj_id);
int			find_object_id(t_sl *sl, int x, int y);
void		update_exit_and_bullet(t_sl *sl, t_object *exit);

//	extra object list utilities
int			search_list(t_object *list, int x, int y);
t_object	**get_list(t_sl *sl, int obj_id);

//	image handling
void		init_obj_imgs(t_sl *sl, mlx_t *mlx);
void		create_image(mlx_t *mlx, mlx_image_t **img, char *img_file);
void		update_image(mlx_t *mlx, t_object *obj);
void		update_window(t_sl *sl);

//	handle movement
void		player_movement(t_sl *sl, t_object *player, int new_x, int new_y);
void		enemy_movement(t_sl *sl, t_object *enemy);
void		bullet_movement(t_sl *sl, t_object *bullet);
void		enemy_hit(t_sl *sl, t_coord new_c, t_coord en_c, int obj_id);

//	animations
void		change_player_side(t_sl *sl, t_object *player, int dx);
void		change_enemy_side(t_sl *sl, t_object *enemy, int dx);
void		animate_obj(t_object *object, int time, int interval, int dy);
void		animate_walls(t_sl *sl, int time, int interval, int dy);

//	shooting
void		player_shooting(t_sl *sl, mlx_t *mlx, mlx_key_data_t keydata);
t_object	*make_bullet(t_sl *sl, mlx_t *mlx, int dx, int dy);

//	a* pathfinding funcs
t_coord		*find_path(t_sl *sl, char **map, t_coord goal);
void		check_neighbours(t_queue *queue, t_node *current);
int			h_distance(int x, int y, int exit_x, int exit_y);
int			is_goal_node(t_coord current_coord, t_coord goal_coord);

//	queue functions
void		pop_queues(t_sl *sl, t_queue *queue, char **map, t_coord goal);
t_node		*de_queue_neighbour(t_node **queue, t_node *parent, int x, int y);
t_node		*de_queue_pri(t_node **queue);
void		in_queue_pri(t_node **queue, t_node *node);
t_node		*create_node(t_sl *sl, int x, int y, t_coord goal);

//	parser fucntions
void		parse_map(t_sl *sl, t_sl_data *data, char *mapfile);
int			is_valid_char(t_sl *sl, char c, int x, int y);
void		check_line(t_sl *sl, char *line, int y);
void		check_file_name(t_sl *sl, char *mapfile);
void		check_elements(t_sl *sl, t_object *collectible);

//	utils
int			ft_strcmp(char *s1, char *s2);
void		get_height(t_sl *sl, char *mapfile, t_sl_data *data);
int			open_file(t_sl *sl, char *file_name);
void		player_steps(t_sl *sl);

//	free functions
void		free_map(char **map);
void		free_queue(t_queue **queue_ptr);
void		free_obj(t_sl *sl, t_object **object);
void		free_objects(t_sl *sl);
void		sl_exit(t_sl *sl, char *error_msg, int exit_status);

//	endgame screens
void		win(t_sl *sl);
void		lose(t_sl *sl);

#endif
