/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 23:54:11 by vorhansa          #+#    #+#             */
/*   Updated: 2026/05/27 18:02:09 by vorhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

static void	ft_so_long(t_main *main)
{
	main->mlx = mlx_init();
	if (!main->mlx)
	{
		ft_putendl_fd("Error\nMlx initialization failed", 1);
		exit(1);
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
	t_main	main;
	char	*ext;

	if (ac != 2)
	{
		ft_putendl_fd("Error\nProgram must take 1 argument.", 1);
		return (1);
	}
	main = (t_main){0};
	ext = ft_strnstr(av[1], ".ber", ft_strlen(av[1]));
	if (!ext || ext == av[1] || ext[4] || ext[-1] == '/')
	{
		ft_putendl_fd("Error\nProgram must take a <.ber> file.", 1);
		return (1);
	}
	ft_parse_map(av[1], &main.map.parsed_map);
	if (!ft_check_valid_map(&main.map))
	{
		ft_putendl_fd("Error\nInvalid map.", 1);
		ft_exit(1, &main);
	}
	ft_so_long(&main);
	ft_exit(0, &main);
}
