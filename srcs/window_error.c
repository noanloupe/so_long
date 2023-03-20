/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:50:37 by noloupe           #+#    #+#             */
/*   Updated: 2023/02/28 14:23:14 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_error(t_data *data)
{
	ft_printf("\n[ERROR]\nMLX failed to init\n");
	free_map(data->map);
	exit(EXIT_FAILURE);
}

void	win_error(t_data *data)
{
	ft_printf("\n[ERROR]\nWindow failed to open\n");
	free_map(data->map);
	exit(EXIT_FAILURE);
}

void	sprite_error(t_data *data)
{
	ft_printf("\n[ERROR]\nSprite failed to load\n");
	mlx_destroy_window(data->mlx, data->win);
	free_map(data->map);
	free(data->mlx);
	exit(EXIT_FAILURE);
}
