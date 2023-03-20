/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:53:46 by noloupe           #+#    #+#             */
/*   Updated: 2023/02/28 15:25:37 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	map;
	t_map	map_cpy;
	int		fd;
	int		amount;

	arg_error(argc, argv);
	set_map(&map, argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		fd_error(&map);
	parsing(fd, &map);
	map_check(&map);
	set_map(&map_cpy, argv[1]);
	map_dup(&map, &map_cpy);
	amount = map.col->count + 1;
	if (!pathfinding(&map_cpy, map_cpy.player->y, map_cpy.player->x, &amount))
		pathfinding_error(&map, &map_cpy);
	free_map(&map_cpy);
	init_window(&map);
	free_map(&map);
	return (0);
}
