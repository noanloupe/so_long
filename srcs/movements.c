/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:55:28 by noloupe           #+#    #+#             */
/*   Updated: 2023/03/02 11:11:24 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_data *data, int x, int y)
{
	char	next;

	next = data->map->bitmap[y - 1][x];
	if (next == '1')
		return ;
	data->moves += 1;
	ft_printf("%d\n", data->moves);
	if (next == 'C')
		data->map->col->count -= 1;
	else if (next == 'E' && data->map->col->count == 0)
		success(data);
	data->map->player->y -= 1;
	if (data->map->bitmap[y][x] != 'E')
		data->map->bitmap[y][x] = '0';
	if (data->map->bitmap[y - 1][x] != 'E')
		data->map->bitmap[y - 1][x] = 'P';
}

void	move_down(t_data *data, int x, int y)
{
	char	next;

	next = data->map->bitmap[y + 1][x];
	if (next == '1')
		return ;
	data->moves += 1;
	ft_printf("%d\n", data->moves);
	if (next == 'C')
		data->map->col->count -= 1;
	else if (next == 'E' && data->map->col->count == 0)
		success(data);
	data->map->player->y += 1;
	if (data->map->bitmap[y][x] != 'E')
		data->map->bitmap[y][x] = '0';
	if (data->map->bitmap[y + 1][x] != 'E')
		data->map->bitmap[y + 1][x] = 'P';
}

void	move_left(t_data *data, int x, int y)
{
	char	next;

	next = data->map->bitmap[y][x - 1];
	if (next == '1')
		return ;
	data->moves += 1;
	ft_printf("%d\n", data->moves);
	if (next == 'C')
		data->map->col->count -= 1;
	else if (next == 'E' && data->map->col->count == 0)
		success(data);
	data->map->player->x -= 1;
	if (data->map->bitmap[y][x] != 'E')
		data->map->bitmap[y][x] = '0';
	if (data->map->bitmap[y][x - 1] != 'E')
		data->map->bitmap[y][x - 1] = 'P';
}

void	move_right(t_data *data, int x, int y)
{
	char	next;

	next = data->map->bitmap[y][x + 1];
	if (next == '1')
		return ;
	data->moves += 1;
	ft_printf("%d\n", data->moves);
	if (next == 'C')
		data->map->col->count -= 1;
	else if (next == 'E' && data->map->col->count == 0)
		success(data);
	data->map->player->x += 1;
	if (data->map->bitmap[y][x] != 'E')
		data->map->bitmap[y][x] = '0';
	if (data->map->bitmap[y][x + 1] != 'E')
		data->map->bitmap[y][x + 1] = 'P';
}
