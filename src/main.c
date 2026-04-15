/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 23:54:11 by vorhansa          #+#    #+#             */
/*   Updated: 2026/04/16 02:03:40 by vorhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

static void	ft_so_long(t_main *main)
{
	main->mlx = mlx_init();
	if (!main->mlx)
	{
		perror("Error\nMlx initialization failed");
		exit(EXIT_FAILURE);
	}
	ft_xpm_to_img(main);
	main->win.width = main->map.assets.width * main->map.width;
	main->win.height = main->map.assets.height * main->map.height;
	main->win.mlx_win = mlx_new_window(main->mlx,
			main->win.width, main->win.height, "so_long");
	ft_render_assets(main);
	mlx_key_hook(main->win.mlx_win, key_hook, main);
	mlx_hook(main->win.mlx_win, 17, 0, window_destroyed, main);
	mlx_loop(main->mlx);
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
	ft_so_long(&main);
	ft_exit(EXIT_FAILURE, main);
}
