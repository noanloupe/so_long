/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:17:43 by noloupe           #+#    #+#             */
/*   Updated: 2023/02/28 15:57:57 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_map(t_map *map, char *mapfile)
{
	int	count;

	count = number_of_lines(map, mapfile);
	map->x = 0;
	map->y = 0;
	map->bitmap = malloc(sizeof(char *) * count);
	map->col = init_col();
	map->player = init_player();
	map->finish = init_finish();
	if (!map->bitmap || !map->col || !map->player || !map->finish)
	{
		free_map(map);
		exit(EXIT_FAILURE);
	}
}

t_col	*init_col(void)
{
	t_col	*col;

	col = malloc(sizeof(t_col));
	if (!col)
		return (NULL);
	col->count = 0;
	return (col);
}

t_player	*init_player(void)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->x = 0;
	player->y = 0;
	player->count = 0;
	return (player);
}

t_finish	*init_finish(void)
{
	t_finish	*finish;

	finish = malloc(sizeof(t_finish));
	if (!finish)
		return (NULL);
	finish->x = 0;
	finish->y = 0;
	finish->count = 0;
	return (finish);
}

void	init_sprite(t_data *data)
{
	t_sprite	*sprite;

	sprite = malloc(sizeof(t_sprite));
	if (!sprite)
		sprite_error(data);
	data->sprite = sprite;
	sprite->sprite[0] = mlx_xpm_file_to_image(data->mlx,
			"./img/ground", &sprite->wth, &sprite->hgt);
	sprite->sprite[1] = mlx_xpm_file_to_image(data->mlx,
			"./img/wall", &sprite->wth, &sprite->hgt);
	sprite->sprite[2] = mlx_xpm_file_to_image(data->mlx,
			"./img/collectible", &sprite->wth, &sprite->hgt);
	sprite->sprite[3] = mlx_xpm_file_to_image(data->mlx,
			"./img/player", &sprite->wth, &sprite->hgt);
	sprite->sprite[4] = mlx_xpm_file_to_image(data->mlx,
			"./img/finish", &sprite->wth, &sprite->hgt);
	if (!sprite->sprite[0] || !sprite->sprite[1]
		|| !sprite->sprite[2] || !sprite->sprite[3] || !sprite->sprite[4])
	{
		clear_sprite(data, 5);
		sprite_error(data);
	}
}
