/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 16:54:50 by vorhansa          #+#    #+#             */
/*   Updated: 2026/05/26 18:19:49 by vorhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

static int	ft_find_start(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (x < map->height)
	{
		y = 0;
		while (y < map->width)
		{
			if (map->parsed_map[x][y] == START_POSITION)
			{
				map->position.start_position_x = x;
				map->position.start_position_y = y;
				return (1);
			}
			y++;
		}
		x++;
	}
	return (0);
}

static char	**ft_duplicate_map(t_map *map)
{
	char	**duplicate;
	int		i;

	duplicate = ft_calloc(map->height + 1, sizeof(char *));
	if (!duplicate)
		return (NULL);
	i = 0;
	while (i < map->height)
	{
		duplicate[i] = ft_strdup(map->parsed_map[i]);
		if (!duplicate[i])
			return (ft_free_2d(duplicate));
		i++;
	}
	return (duplicate);
}

static void	ft_flood_fill(char **grid, int x, int y, t_map *map)
{
	if (x < 0 || y < 0 || x >= map->height || y >= map->width)
		return ;
	if (grid[x][y] == WALL || grid[x][y] == 'F')
		return ;
	if (grid[x][y] == EMPTY_SPACE || grid[x][y] == COLLECTIBLE
		|| grid[x][y] == START_POSITION || grid[x][y] == EXIT)
	{
		grid[x][y] = 'F';
		ft_flood_fill(grid, x + 1, y, map);
		ft_flood_fill(grid, x - 1, y, map);
		ft_flood_fill(grid, x, y + 1, map);
		ft_flood_fill(grid, x, y - 1, map);
	}
}

int	ft_validate_reachability(t_map *map)
{
	char	**duplicate;
	int		x;
	int		y;

	if (!ft_find_start(map))
		return (0);
	duplicate = ft_duplicate_map(map);
	if (!duplicate)
		return (0);
	ft_flood_fill(duplicate, map->position.start_position_x,
		map->position.start_position_y, map);
	x = 0;
	while (x < map->height)
	{
		y = 0;
		while (y < map->width)
		{
			if (duplicate[x][y] == COLLECTIBLE || duplicate[x][y] == EXIT)
				return (ft_free_2d(duplicate), 0);
			y++;
		}
		x++;
	}
	ft_free_2d(duplicate);
	return (1);
}
