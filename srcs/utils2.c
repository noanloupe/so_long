/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:04:55 by noloupe           #+#    #+#             */
/*   Updated: 2023/02/28 15:56:53 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clear_sprite(t_data *data, int amount)
{
	int	i;

	i = 0;
	while (i < amount)
	{
		if (data->sprite->sprite[i])
			mlx_destroy_image(data->mlx, data->sprite->sprite[i]);
		i++;
	}
}

void	success(t_data *data)
{
	clear_sprite(data, 5);
	mlx_destroy_window(data->mlx, data->win);
	free(data->mlx);
	free_map(data->map);
	exit(EXIT_SUCCESS);
}

void	feature_count(t_map *map, int i, int j, int feature)
{
	if (feature == 0)
	{
		map->player->count += 1;
		map->player->x = j;
		map->player->y = i;
	}
	else if (feature == 1)
	{
		map->finish->count += 1;
		map->finish->x = j;
		map->finish->y = i;
	}
}
