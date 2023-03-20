/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:46:27 by noloupe           #+#    #+#             */
/*   Updated: 2023/02/28 15:43:29 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_dup(t_map *map, t_map *map_cpy)
{
	int	i;

	i = 0;
	while (i < map->y)
	{
		map_cpy->bitmap[i] = ft_strdup(map->bitmap[i]);
		i++;
	}
	map_cpy->x = map->x;
	map_cpy->y = map->y;
	map_cpy->player->x = map->player->x;
	map_cpy->player->y = map->player->y;
	map_cpy->player->count = map->player->count;
	map_cpy->finish->x = map->finish->x;
	map_cpy->finish->y = map->finish->y;
	map_cpy->finish->count = map->finish->count;
	map_cpy->col->count = map->col->count;
}

int	pathfinding(t_map *map_cpy, int y, int x, int *amount)
{
	char	up;
	char	down;
	char	left;
	char	right;

	if (*amount == 0)
		return (1);
	up = map_cpy->bitmap[y - 1][x];
	down = map_cpy->bitmap[y + 1][x];
	left = map_cpy->bitmap[y][x - 1];
	right = map_cpy->bitmap[y][x + 1];
	if (map_cpy->bitmap[y][x] == 'C' || map_cpy->bitmap[y][x] == 'E')
		*amount = *amount - 1;
	map_cpy->bitmap[y][x] = '9';
	if (up != '1' && up != '9')
		pathfinding(map_cpy, y - 1, x, amount);
	if (down != '1' && down != '9')
		pathfinding(map_cpy, y + 1, x, amount);
	if (left != '1' && left != '9')
		pathfinding(map_cpy, y, x - 1, amount);
	if (right != '1' && right != '9')
		pathfinding(map_cpy, y, x + 1, amount);
	if (*amount == 0)
		return (1);
	return (0);
}
