/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 01:04:58 by vorhansa          #+#    #+#             */
/*   Updated: 2026/04/14 05:00:00 by vorhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# include "../libft/libft.h"

# ifdef __linux__
#  include "../minilibx-linux/mlx.h"
// #  include "../minilibx/mlx.h"
# endif

# ifdef __linux__
#  define W_UP 119
#  define S_DOWN 115
#  define A_LEFT 97
#  define D_RIGHT 100
#  define ESC 65307
# endif

# define EMPTY_SPACE 48
# define WALL 49
# define COLLECTIBLE 67
# define EXIT 69
# define START_POSITION 80

# define SPACE_IMG "img/space.png"
# define WALL_IMG "img/wall.png"
# define GEMSTONE_IMG "img/gemstone.png"
# define R_EXIT_IMG "img/right_exit.png"
# define L_EXIT_IMG "img/left_exit.png"
# define PLAYER_IMG "img/miner.png"

typedef struct s_win {
	void		*mlx_win;
	int			width;
	int			height;
}	t_win;

typedef struct s_assets {
	void		*empty_space;
	void		*wall;
	void		*gemstone;
	void		*right_exit;
	void		*left_exit;
	void		*player;
	int			width;
	int			height;
}	t_assets;

typedef struct s_map {
	char		**parsed_map;
	int			collectibles;
	int			exit;
	int			start_position;
	int			movements;
	int			game_ended;
	int			width;
	int			height;
	t_assets	assets;
}	t_map;

typedef struct s_main {
	void		*mlx;
	t_win		win;
	t_map		map;
}	t_main;

# define BUFFER_SIZE 1

typedef struct s_line
{
	int				fd;
	char			content[BUFFER_SIZE + 1];
	struct s_line	*next;
}	t_line;

char	*get_next_line(int fd);

#endif