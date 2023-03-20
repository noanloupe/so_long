/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:24:18 by noloupe           #+#    #+#             */
/*   Updated: 2023/02/28 16:00:42 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (map->bitmap)
	{
		while (i < map->y)
		{
			free(map->bitmap[i]);
			i++;
		}
		free(map->bitmap);
	}
	if (map->col)
		free(map->col);
	if (map->player)
		free(map->player);
	if (map->finish)
		free(map->finish);
}

int	number_of_lines(t_map *map, char *mapfile)
{
	int		count;
	int		fd;
	char	*temp;

	fd = open(mapfile, O_RDONLY);
	if (fd == -1)
		fd_error(map);
	count = 0;
	while (1)
	{
		temp = get_next_line(fd);
		if (!temp && count == 0)
			empty_map_error();
		if (!temp)
			break ;
		count++;
		free(temp);
	}
	close(fd);
	return (count);
}

char	*quick_trim(char *line)
{
	char	*new_line;
	int		i;

	new_line = malloc(sizeof(char) * ft_strlen(line) + 1);
	if (!new_line)
		return (NULL);
	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
		{
			new_line[i] = '\0';
			break ;
		}
		new_line[i] = line[i];
		i++;
	}
	new_line[i] = '\0';
	free(line);
	return (new_line);
}

int	close_tab(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	free_map(data->map);
	free_sprite(data->sprite);
	free(data->mlx);
	exit(EXIT_SUCCESS);
}

void	free_sprite(t_sprite *sprite)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (sprite->sprite[i])
			free(sprite->sprite[i]);
		i++;
	}
}
