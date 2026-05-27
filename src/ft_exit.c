/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 01:53:56 by vorhansa          #+#    #+#             */
/*   Updated: 2026/05/27 18:00:10 by vorhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

void	ft_exit(int status, t_main *main)
{
	if (!main)
		exit(status);
	if (status == 1 && main->mlx)
	{
		if (main->map.assets.empty_space)
			mlx_destroy_image(main->mlx, main->map.assets.empty_space);
		if (main->map.assets.wall)
			mlx_destroy_image(main->mlx, main->map.assets.wall);
		if (main->map.assets.gemstone)
			mlx_destroy_image(main->mlx, main->map.assets.gemstone);
		if (main->map.assets.right_exit)
			mlx_destroy_image(main->mlx, main->map.assets.right_exit);
		if (main->map.assets.left_exit)
			mlx_destroy_image(main->mlx, main->map.assets.left_exit);
		if (main->map.assets.player)
			mlx_destroy_image(main->mlx, main->map.assets.player);
		if (main->win.mlx_win)
			mlx_destroy_window(main->mlx, main->win.mlx_win);
	}
	if (main->map.parsed_map)
		ft_free_2d(main->map.parsed_map);
	exit(status);
}

int	window_destroyed(t_main *main)
{
	ft_exit(0, main);
	return (0);
}
