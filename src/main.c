/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 23:54:11 by vorhansa          #+#    #+#             */
/*   Updated: 2026/04/15 16:44:24 by vorhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

void	*ft_free(void *ptr)
{
	free(ptr);
	return (NULL);
}

void	*ft_free_2d(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
		free(ptr[i++]);
	free(ptr);
	return (NULL);
}

void	ft_exit(int	status, t_main *main)
{
	if (status == EXIT_FAILURE)
	{
		mlx_destroy_image(main->mlx, main->map.assets.empty_space);
		mlx_destroy_image(main->mlx, main->map.assets.wall);
		mlx_destroy_image(main->mlx, main->map.assets.gemstone);
		mlx_destroy_image(main->mlx, main->map.assets.right_exit);
		mlx_destroy_image(main->mlx, main->map.assets.left_exit);
		mlx_destroy_image(main->mlx, main->map.assets.player);
		mlx_destroy_window(main->mlx, main->win.mlx_win);
	}
	ft_free_2d(main->map.parsed_map);
	exit(status);
}

void	ft_xpm_to_img(t_main *main)
{
	main->map.assets.empty_space = mlx_xpm_file_to_image(main->mlx, SPACE_IMG, 
		&main->map.assets.width, &main->map.assets.height);
	main->map.assets.wall = mlx_xpm_file_to_image(main->mlx, WALL_IMG,
		&main->map.assets.width, &main->map.assets.height);
	main->map.assets.gemstone = mlx_xpm_file_to_image(main->mlx, GEMSTONE_IMG,
		&main->map.assets.width, &main->map.assets.height);
	main->map.assets.right_exit = mlx_xpm_file_to_image(main->mlx, R_EXIT_IMG,
		&main->map.assets.width, &main->map.assets.height);
	main->map.assets.left_exit = mlx_xpm_file_to_image(main->mlx, L_EXIT_IMG,
		&main->map.assets.width, &main->map.assets.height);
	main->map.assets.player = mlx_xpm_file_to_image(main->mlx, PLAYER_IMG,
		&main->map.assets.width, &main->map.assets.height);
	if (!main->map.assets.empty_space || !main->map.assets.wall
		|| !main->map.assets.gemstone || !main->map.assets.right_exit
		|| !main->map.assets.left_exit || !main->map.assets.player)
	{
		perror("Error\nCouldn't load assets");
		ft_exit(EXIT_FAILURE, main);
	}
}

t_main *main_init(char *path)
{
	t_main	*main;

	main = ft_calloc(1, sizeof(t_main));
	main->mlx = mlx_init();
	if (!main->mlx)
	{
		perror("Error\nMlx initialization failed");
		exit(EXIT_FAILURE);
	}
}

void	ft_parse_map(char *file, char ***map)
{
	int		fd;
	char	*line;
	char	*lines;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\nCouldn't open map");
		exit(EXIT_FAILURE);
	}
	lines = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		lines = ft_strnjoin(lines, line, ft_strlen(line));
		line = ft_free(line);
	}
	close(fd);
	*map = ft_split(lines, '\n');
	lines = ft_free(lines);
}

int	main(int ac, char **av)
{
	t_main	*main;
	
	if (ac != 2)
	{
		ft_putendl_fd("Error\nProgram must take 1 argument.", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (!ft_strnstr(av[1], ".ber", ft_strlen(av[1]))
		|| ft_strnstr(av[1], ".ber", ft_strlen(av[1]))[4])
	{
		ft_putendl_fd("Error\nProgram must take a <.ber> file.", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	ft_parse_map(av[1], main->map.parsed_map);
	if (!ft_is_map_valid(main->map))
	{
		ft_putendl_fd("Error\nInvalid map.", STDERR_FILENO);
		ft_exit(EXIT_FAILURE, main);
	}
}
