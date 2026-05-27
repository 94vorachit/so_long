/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 20:38:46 by vorhansa          #+#    #+#             */
/*   Updated: 2026/05/27 18:01:54 by vorhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

static void	ft_init_map(t_map *map)
{
	map->collectibles = 0;
	map->exit = 0;
	map->position.start_position = 0;
	map->movements = 0;
	map->game_ended = 0;
	map->width = 0;
	map->height = 0;
}

static int	ft_validate_components(t_map *map, char *parsed_map)
{
	int	i;

	i = 0;
	while (parsed_map[i])
	{
		if ((i == 0 || parsed_map[i + 1] == '\0')
			&& parsed_map[i] != WALL)
			return (0);
		if (parsed_map[i] == COLLECTIBLE)
			map->collectibles++;
		else if (parsed_map[i] == EXIT)
			map->exit++;
		else if (parsed_map[i] == START_POSITION)
			map->position.start_position++;
		else if (parsed_map[i] != EMPTY_SPACE && parsed_map[i] != WALL)
			return (0);
		i++;
	}
	return (1);
}

static int	ft_validate_walls(char *parsed_map)
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
	while (map->parsed_map[map->height])
	{
		if (map->height == 0)
			map->width = ft_strlen(map->parsed_map[map->height]);
		else if ((int)ft_strlen(map->parsed_map[map->height]) != map->width)
			return (0);
		if ((map->height == 0 || !map->parsed_map[map->height + 1])
			&& !ft_validate_walls(map->parsed_map[map->height]))
			return (0);
		if ((map->height == 0 || !map->parsed_map[map->height + 1])
			&& !ft_validate_components(map, map->parsed_map[map->height]))
			return (0);
		if (!ft_validate_components(map, map->parsed_map[map->height]))
			return (0);
		map->height++;
	}
	if (map->exit != 1 || map->collectibles < 1
		|| map->position.start_position != 1)
		return (0);
	if (!ft_validate_reachability(map))
		return (0);
	return (1);
}

void	ft_parse_map(char *file, char ***map)
{
	int		fd;
	char	*line;
	char	*lines;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("Error\nCouldn't open map", 1);
		exit(1);
	}
	lines = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		lines = ft_strnjoin(lines, line, ft_strlen(line));
		line = ft_free_ptr(line);
	}
	close(fd);
	*map = ft_split(lines, '\n');
	lines = ft_free_ptr(lines);
}
