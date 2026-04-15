/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_characters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 20:03:09 by vorhansa          #+#    #+#             */
/*   Updated: 2026/04/15 23:14:32 by vorhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

static void	ft_put_asset(char component, int x, int y, t_main *main)
{
	if (component != WALL)
		mlx_put_image_to_window(main->mlx, main->win.mlx_win,
			main->map.assets.empty_space, x, y);
	if (component == WALL)
		mlx_put_image_to_window(main->mlx, main->win.mlx_win,
			main->map.assets.wall, x, y);
	else if (component == COLLECTIBLE)
		mlx_put_image_to_window(main->mlx, main->win.mlx_win,
			main->map.assets.gemstone, x, y);
	else if (component == EXIT)
	{
		if (x > main->win.width)
			mlx_put_image_to_window(main->mlx, main->win.mlx_win,
				main->map.assets.right_exit, x, y);
		else
			mlx_put_image_to_window(main->mlx, main->win.mlx_win,
				main->map.assets.left_exit, x, y);
	}
	else if (component == START_POSITION)
	{
		if (main->map.game_ended)
			ft_put_asset(EXIT, x, y, main);
		mlx_put_image_to_window(main->mlx, main->win.mlx_win,
			main->map.assets.player, x, y);
	}
}

void	ft_render_assets(t_main *main)
{
	int	i;
	int	j;
	int	x;
	int	y;

	y = 0;
	i = 0;
	while (main->map.parsed_map[i])
	{
		x = 0;
		j = 0;
		while (main->map.parsed_map[i][j])
		{
			ft_put_asset(main->map.parsed_map[i][j], x, y, main);
			x += main->map.assets.width;
			j ++;
		}
		y += main->map.assets.height;
		i ++;
	}
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
