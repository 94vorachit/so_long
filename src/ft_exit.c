/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 01:53:56 by vorhansa          #+#    #+#             */
/*   Updated: 2026/04/16 01:54:34 by vorhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

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

int	window_destroyed(t_main *main)
{
	ft_quit_program(EXIT_SUCCESS, main);
	return (EXIT_SUCCESS);
}
