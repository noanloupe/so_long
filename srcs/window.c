/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:49:13 by noloupe           #+#    #+#             */
/*   Updated: 2023/03/02 11:04:56 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_window(t_map *map)
{
	void	*mlx;
	void	*win;
	t_data	data;

	data.map = map;
	data.moves = 0;
	mlx = mlx_init();
	if (!mlx)
		mlx_error(&data);
	win = mlx_new_window(mlx, data.map->x * 32, data.map->y * 32, "so_long");
	if (!win)
		win_error(&data);
	data.mlx = mlx;
	data.win = win;
	init_sprite(&data);
	load_map(&data);
	mlx_key_hook(win, key_hook, &data);
	mlx_hook(data.win, 17, 0, close_tab, &data);
	mlx_loop(mlx);
}

int	key_hook(int key, t_data *data)
{
	if (key == 53)
		close_tab(data);
	else if (key == 0 || key == 123)
		move_left(data, data->map->player->x, data->map->player->y);
	else if (key == 1 || key == 125)
		move_down(data, data->map->player->x, data->map->player->y);
	else if (key == 2 || key == 124)
		move_right(data, data->map->player->x, data->map->player->y);
	else if (key == 13 || key == 126)
		move_up(data, data->map->player->x, data->map->player->y);
	switch_sprites(data);
	return (0);
}

void	load_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map->y)
	{
		j = 0;
		while (j < data->map->x)
		{
			map_loader(data, i, j);
			j++;
		}
		i++;
	}
}

void	switch_sprites(t_data *data)
{
	int	i;
	int	j;

	i = data->map->player->y - 1;
	while (i <= data->map->player->y + 1 && i < data->map->y)
	{
		if (i < 0)
			i = 0;
		j = data->map->player->x - 1;
		while (j <= data->map->player->x + 1 && j < data->map->x)
		{
			if (j < 0)
				j = 0;
			map_loader(data, i, j);
			j++;
		}
		i++;
	}
	if (data->map->finish->x == data->map->player->x
		&& data->map->finish->y == data->map->player->y)
		mlx_put_image_to_window(data->mlx, data->win, data->sprite->sprite[3],
			data->map->player->x * 32, data->map->player->y * 32);
}

void	map_loader(t_data *data, int i, int j)
{
	if (data->map->bitmap[i][j] == '0')
		mlx_put_image_to_window(data->mlx, data->win,
			data->sprite->sprite[0], j * 32, i * 32);
	else if (data->map->bitmap[i][j] == '1')
		mlx_put_image_to_window(data->mlx, data->win,
			data->sprite->sprite[1], j * 32, i * 32);
	else if (data->map->bitmap[i][j] == 'C')
		mlx_put_image_to_window(data->mlx, data->win,
			data->sprite->sprite[2], j * 32, i * 32);
	else if (data->map->bitmap[i][j] == 'P')
		mlx_put_image_to_window(data->mlx, data->win,
			data->sprite->sprite[3], j * 32, i * 32);
	else if (data->map->bitmap[i][j] == 'E')
		mlx_put_image_to_window(data->mlx, data->win,
			data->sprite->sprite[4], j * 32, i * 32);
}
