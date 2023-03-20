/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:12:27 by noloupe           #+#    #+#             */
/*   Updated: 2023/02/28 15:30:42 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	rect_error(t_map *map)
{
	ft_printf("\n[ERROR]\nMap is not rectangular\n");
	map->y += 1;
	free_map(map);
	exit(EXIT_FAILURE);
}

void	empty_map_error(void)
{
	ft_printf("\n[ERROR]\nMap is empty\n\n");
	exit(EXIT_FAILURE);
}

void	wall_error(t_map *map)
{
	ft_printf("\n[ERROR]\nMissing walls\n\n");
	free_map(map);
	exit(EXIT_FAILURE);
}

void	invalid_error(t_map *map, int x, int y, char c)
{
	ft_printf("\n[ERROR]\nInvalid character in map at x=%d ; y=%d ('%c')\n",
		x + 1, y + 1, c);
	free_map(map);
	exit(EXIT_FAILURE);
}

void	symbol_error(t_map *map, int n)
{
	if (n == 0)
		ft_printf("\n[ERROR]\nMissing symbol 'C' in map\n");
	else if (n == 1)
		ft_printf("\n[ERROR]\nDuplicate symbol 'E' in map\n");
	else if (n == -1)
		ft_printf("\n[ERROR]\nMissing symbol 'E' in map\n");
	else if (n == 2)
		ft_printf("\n[ERROR]\nDuplicate symbol 'P' in map\n");
	else if (n == -2)
		ft_printf("\n[ERROR]\nMissing symbol 'P' in map\n");
	free_map(map);
	exit(EXIT_FAILURE);
}
