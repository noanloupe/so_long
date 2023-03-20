/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:38:18 by noloupe           #+#    #+#             */
/*   Updated: 2023/02/28 15:56:56 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../gnl/get_next_line.h"
# include <mlx.h>
# include <fcntl.h>

/* STRUCTURES */

typedef struct s_col
{
	int			count;
}	t_col;

typedef struct s_player
{
	int			x;
	int			y;
	int			count;
}	t_player;

typedef struct s_finish
{
	int			x;
	int			y;
	int			count;
}	t_finish;

typedef struct s_map
{
	int			x;
	int			y;
	char		*mapfile;
	char		**bitmap;
	t_col		*col;
	t_player	*player;
	t_finish	*finish;
}	t_map;

typedef struct s_sprite
{
	int			hgt;
	int			wth;
	void		*sprite[5];
}	t_sprite;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			moves;
	t_map		*map;
	t_sprite	*sprite;
}	t_data;

/* BASE */

void		add_line(t_map *map, char *line);
void		check_features(t_map *map);
void		check_walls(t_map *map);
void		clear_sprite(t_data *data, int amount);
int			close_tab(t_data *data);
void		feature_count(t_map *map, int i, int j, int featutre);
void		fr_ex(t_data *data);
void		free_map(t_map *map);
void		free_sprite(t_sprite *sprite);
t_col		*init_col(void);
t_finish	*init_finish(void);
t_player	*init_player(void);
void		init_window(t_map *map);
void		init_sprite(t_data *data);
int			key_hook(int key, t_data *data);
void		load_map(t_data *data);
void		map_check(t_map *map);
void		map_loader(t_data *data, int i, int j);
void		map_dup(t_map *map, t_map *map_cpy);
void		move_down(t_data *data, int x, int y);
void		move_left(t_data *data, int x, int y);
void		move_right(t_data *data, int x, int y);
void		move_up(t_data *data, int x, int y);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			number_of_lines(t_map *map, char *mapfile);
void		parsing(int fd, t_map *map);
int			pathfinding(t_map *map_cpy, int y, int x, int *amount);
char		*quick_trim(char *line);
void		set_map(t_map *map, char *mapfile);
void		success(t_data *data);
void		switch_sprites(t_data *data);

/* ERRORS */

void		arg_error(int argc, char **argv);
void		empty_map_error(void);
void		fd_error(t_map *map);
void		invalid_error(t_map *map, int x, int y, char c);
void		mlx_error(t_data *data);
void		pathfinding_error(t_map *map, t_map *map_cpy);
void		rect_error(t_map *map);
void		sprite_error(t_data *data);
void		symbol_error(t_map *map, int n);
void		wall_error(t_map *map);
void		win_error(t_data *data);

#endif
