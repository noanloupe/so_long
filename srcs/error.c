/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:43:52 by noloupe           #+#    #+#             */
/*   Updated: 2023/02/14 14:43:51 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	arg_error(int argc, char **argv)
{
	int	len;

	if (argc != 2)
	{
		ft_printf("[ERROR]\nWrong number of arguments\n");
		exit(EXIT_FAILURE);
	}
	len = (int)ft_strlen(argv[1]);
	if (ft_strncmp(&argv[1][len - 4], ".ber", 4) != 0)
	{
		ft_printf("[ERROR]\nMap is not .ber\n");
		exit(EXIT_FAILURE);
	}
}

void	fd_error(t_map *map)
{
	ft_printf("[ERROR]\nCan not read file\n");
	free_map(map);
	exit(EXIT_FAILURE);
}

void	pathfinding_error(t_map *map, t_map *map_cpy)
{
	ft_printf("[ERROR]\nMissing valid path\n");
	free_map(map);
	free_map(map_cpy);
	exit(EXIT_FAILURE);
}
