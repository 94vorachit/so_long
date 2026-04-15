/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 20:11:56 by vorhansa          #+#    #+#             */
/*   Updated: 2026/04/15 23:16:55 by vorhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

static void	ft_get_start_pos(int *x, int *y, t_main *main)
{
	*x = 0;
	while (main->map.parsed_map[*x])
	{
		*y = 0;
		while (main->map.parsed_map[*x][*y])
		{
			if (main->map.parsed_map[*x][*y] == START_POSITION)
				return ;
			*y += 1;
		}
		*x += 1;
	}
}

static void	ft_move_to(char *current_pos, char *new_pos, t_main *main)
{
	if (*new_pos == EMPTY_SPACE
		|| *new_pos == COLLECTIBLE
		|| (*new_pos == EXIT && main->map.collectibles == 0))
	{
		if (*new_pos == COLLECTIBLE)
			main->map.collectibles--;
		else if (*new_pos == EXIT)
			main->map.game_ended = 1;
		*current_pos = EMPTY_SPACE;
		*new_pos = START_POSITION;
		main->map.movements++;
		printf("Movement count: %d\n", main->map.movements);
	}
}

static void	ft_key_move(int keycode, t_main *main)
{
	int	x;
	int	y;

	ft_get_start_pos(&x, &y, main);
	if (keycode == A_LEFT)
		ft_move_to(&main->map.parsed_map[x][y],
			&main->map.parsed_map[x][y - 1], main);
	else if (keycode == D_RIGHT)
		ft_move_to(&main->map.parsed_map[x][y],
			&main->map.parsed_map[x][y + 1], main);
	else if (keycode == W_UP)
		ft_move_to(&main->map.parsed_map[x][y],
			&main->map.parsed_map[x - 1][y], main);
	else if (keycode == S_DOWN)
		ft_move_to(&main->map.parsed_map[x][y],
			&main->map.parsed_map[x + 1][y], main);
}

int	key_hook(int keycode, t_main *main)
{
	if (keycode == ESC)
		ft_quit_program(EXIT_SUCCESS, main);
	if ((keycode != A_LEFT && keycode != D_RIGHT
			&& keycode != W_UP && keycode != S_DOWN)
		|| main->map.game_ended)
		return (0);
	ft_key_move(keycode, main);
	ft_render_assets(main);
	if (main->map.game_ended)
		printf("You won!\n");
	return (1);
}
