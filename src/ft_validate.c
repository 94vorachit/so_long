/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 20:38:46 by vorhansa          #+#    #+#             */
/*   Updated: 2026/04/15 03:24:36 by vorhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

static void	ft_init_map(t_map *map)
{
	map->collectibles = 0;
	map->exit = 0;
	map->start_position = 0;
	map->movements = 0;
	map->game_ended = 0;
	map->width = 0;
	map->height = 0;
}

static int	ft_valid_walls(char *parsed_map)
{
	int	i;

	i = 0;
	while (parsed_map[i])
	{
		if (parsed_map[i] != WALL)
			return (0);
		i++;
	}
	return (1);
}
int	ft_check_valid_map(t_map *map)
{
	ft_init_map(map);
}
