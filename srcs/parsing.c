/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:22:20 by noloupe           #+#    #+#             */
/*   Updated: 2023/02/28 15:38:43 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parsing(int fd, t_map *map)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		line = quick_trim(line);
		if (!line)
			free_map(map);
		add_line(map, line);
	}
	close(fd);
}

void	add_line(t_map *map, char *line)
{
	map->bitmap[map->y] = line;
	if (!map->bitmap[map->y])
	{
		free_map(map);
		exit(EXIT_FAILURE);
	}
	if (map->y == 0)
		map->x = (int)ft_strlen(map->bitmap[0]);
	if (map->x != (int)ft_strlen(map->bitmap[map->y]))
		rect_error(map);
	map->y += 1;
}

void	map_check(t_map *map)
{
	check_walls(map);
	check_features(map);
	if (map->col->count < 1)
		symbol_error(map, 0);
	else if (map->finish->count > 1)
		symbol_error(map, 1);
	else if (map->finish->count < 1)
		symbol_error(map, -1);
	else if (map->player->count > 1)
		symbol_error(map, 2);
	else if (map->player->count < 1)
		symbol_error(map, -2);
}

void	check_walls(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->y)
	{
		j = 0;
		if (i == 0 || i == map->y - 1)
		{
			while (map->bitmap[i][j])
			{
				if (map->bitmap[i][j] != '1')
					wall_error(map);
				j++;
			}
		}
		else
		{
			if (map->bitmap[i][0] != '1' || map->bitmap[i][map->x - 1] != '1')
				wall_error(map);
		}
		i++;
	}
}

void	check_features(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->y)
	{
		j = 0;
		while (map->bitmap[i][j])
		{
			if (map->bitmap[i][j] == 'C')
				map->col->count += 1;
			else if (map->bitmap[i][j] == 'P')
				feature_count(map, i, j, 0);
			else if (map->bitmap[i][j] == 'E')
				feature_count(map, i, j, 1);
			else if (map->bitmap[i][j] != '1' && map->bitmap[i][j] != '0')
				invalid_error(map, j, i, map->bitmap[i][j]);
			j++;
		}
		i++;
	}
}
