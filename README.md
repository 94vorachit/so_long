*This Project Has Been Created As Part Of The 42 Curriculum By **Vorhansa***

# Description
    
The objective of the So_Long project is to develop a fully functional game that incorporates various game elements, such as map rendering, player movement, collision detection, item collection, and win/lose conditions. By completing this project, you will enhance your understanding of game development concepts and gain practical experience in using the MinilibX library.

### Features

Map Rendering So_Long allows you to load and render game maps stored in a specific format, typically a file with a .ber extension. The map consists of different tiles representing walls, paths, collectible items, the player's starting position, and the exit. The MinilibX library provides functions to render graphical elements on the screen, enabling you to display the map with the appropriate textures and colors.

### Game play

The player can move in four directions: up, down, left, and right, within the bounds of the map. By handling keyboard inputs, you can update the player's position on the screen accordingly. The MinilibX library provides functions to capture key events and perform actions based on the pressed keys.

To ensure the player doesn't move through walls or outside the boundaries of the map, collision detection is implemented. The game checks if the player's desired movement will result in a collision with a wall or if the player has reached the exit. If a collision is detected, the player's movement is restricted.

### Mandatory

* The number of movements must be displayed in the shell.
* Pressing `ESC` or closing the window should result in quitting the program.
* The map must be constructed using five components: walls, collectibles (at least one), empty spaces, exits (at least one), and the player (only one). These five characters compose the map:
    * 0 for an empty space
    * 1 for a wall
    * C for a collectible
    * E for a map exit
    * P for the player’s starting position
* To move the main character, use the W A S D keys:
    * W to move up ↑
    * S to move down ↓
    * D to move right ➞
    * A to move left ←

# Instructions

Compile the project using the provided Makefile:
```c
make
```
Run the game executable:
```c
./so_long maps/map3.ber
```
Make sure you have the MinilibX library installed on your system. If it's not already installed, you can find the library and installation instructions in the project repository.

For the tester :
```
git clone https://github.com/augustobecker/so_long_tester.git
```
note : make m

# Resources

* [So_long tutorial](https://medium.com/@digitalpoolng/42-so-long-and-thanks-for-all-the-fish-building-your-first-2d-game-in-c-ccd24034bc8b)
* [Minilibx](https://harm-smits.github.io/42docs/libs/minilibx)
* [Tester](https://github.com/augustobecker/so_long_tester)

# Additional

* LIBFT
* FT_PRINTF

### AI Usage
GitHub Copilot (GPT-5 mini backend) is used for
* Is used to analyze other's people code sample, comprehend the code logic.
* Is used to help with debugging where logic errors occured.
* Discussed about logic
* Used for finding information about micro-optimization, techniques, coding convention.

### Functions Explained

#### Argument & extension check:
* `main` expects exactly one argument (the map file).

```c
if (ac != 2)
{
	ft_putendl_fd("Error\nProgram must take 1 argument.", 1);
	return (1);
}
```
* It finds `.ber` with `ft_strnstr` and rejects the input if `.ber` is missing, at the start, not at the end, or preceded by `/`. This ensures a proper single `.ber` filename.
```c
ext = ft_strnstr(av[1], ".ber", ft_strlen(av[1]));
if (!ext || ext == av[1] || ext[4] || ext[-1] == '/')
{
	ft_putendl_fd("Error\nProgram must take a <.ber> file.", 1);
	return (1);
}
```

#### Map parsing (ft_parse_map in ft_validate.c):

* Opens the file, reads lines using `get_next_line`.
* Concatenates lines into a single string, then `ft_split` by `\n` to create `map.parsed_map` (a char ** grid).
```c
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
```

#### Map validation (ft_check_valid_map in ft_validate.c):

* Initializes map counters (collectibles, exit, start, dimensions).
* Ensures all rows have the same width (rectangular).
* Verifies top and bottom rows are all walls and that the first/last char of each row is a wall.
* Counts components: there must be exactly 1 start position, exactly 1 exit, and at least 1 collectible.
```c
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
```

* Calls `ft_validate_reachability` (in ft_validate_2.c) to ensure every collectible and the exit are reachable from the start using a flood-fill on a duplicated grid.
```c
int	ft_validate_reachability(t_map *map)
{
	char	**dup;
	int		x;
	int		y;

	if (!ft_find_start(map))
		return (0);
	dup = ft_duplicate_map(map);
	if (!dup)
		return (0);
	ft_flood_fill(dup, map->position.start_position_x,
		map->position.start_position_y, map);
	x = 0;
	while (x < map->height)
	{
		y = 0;
		while (y < map->width)
		{
			if (dup[x][y] == COLLECTIBLE || dup[x][y] == EXIT)
				return (ft_free_2d(dup), 0);
			y++;
		}
		x++;
	}
	ft_free_2d(dup);
	return (1);
}
```
#### Failure handling:

* If parsing/validation fail, the program prints an error and calls `ft_exit(1, &main)` which frees resources and exits.
```c
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
```

#### Graphics init and assets :
* Initializes MiniLibX with `mlx_init`.
```c
main->mlx = mlx_init();
if (!main->mlx)
{
	ft_putendl_fd("Error\nMlx initialization failed", 1);
	exit(1);
}
```
* Loads XPM images for tiles, exit, player via `mlx_xpm_file_to_image` and stores them in `main->map.assets`.
```c
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
		ft_putendl_fd("Error\nCouldn't load assets", 1);
		ft_exit(1, main);
	}
}
```
* Computes window size as (map width * asset width, map height * asset height).
* Creates window with `mlx_new_window`.
```c
main->win.width = main->map.assets.width * main->map.width;
main->win.height = main->map.assets.height * main->map.height;
main->win.mlx_win = mlx_new_window(main->mlx, main->win.width, main->win.height, "so_long");
```

#### Initial render :
* Iterates the `parsed_map` grid and places images with `mlx_put_image_to_window`.
* `ft_put_asset` chooses which image to draw for each grid cell (empty, wall, collectible, exit, player). If the player stands on the exit, it shows exit beneath player when needed.
```c
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
		if (main->map.player_on_exit)
			ft_put_asset(EXIT, x, y, main);
		mlx_put_image_to_window(main->mlx, main->win.mlx_win,
			main->map.assets.player, x, y);
	}
}
```

#### Input & game loop hooks:
* `mlx_key_hook` registers `key_hook` (in ft_movements.c) to handle key presses.
```c
mlx_key_hook(main->win.mlx_win, key_hook, main);
```
* `mlx_hook(..., 17, ...)` registers window_destroyed to handle window close events.
```c
mlx_hook(main->win.mlx_win, 17, 0, window_destroyed, main);
```
note : 

    1. The second argument (17) is the X11/MinilibX event code — here it means the window-destroy/close event (commonly used for the window manager close button).
    2. The third argument (0) is the event mask (bitmask of X11 event types). MiniLibX examples typically pass 0 because MLX doesn't require a specific mask for this hook.
* `mlx_loop` starts the event loop.
```c
mlx_loop(main->mlx);
```

#### Movement handling :
* `key_hook`:
    * ESC closes the window (calls `window_destroyed` → `ft_exit(0, main)`).
    * For movement keys (`A`, `D`, `W`, `S`) it calls `ft_key_move` unless the game already ended.
* `ft_key_move`:
    * Finds the player's current coordinates with `ft_get_start_pos`.
    * Calls `ft_move_to` to attempt moving into the target cell (left/right/up/down).
* `ft_move_to`:
    * Allows moving onto `EMPTY_SPACE`, `COLLECTIBLE`, or `EXIT`.
    * If moving onto a collectible, decrements `map.collectibles`.
    * Tracks whether the player is standing on the exit (`player_on_exit`) so stepping off can restore the exit tile underneath.
    * If stepping on `EXIT` and `collectibles == 0`, sets `game_ended = 1`.
    * Updates the grid: previous position becomes `EMPTY_SPACE` or `EXIT` (if player came from exit), new position becomes `START_POSITION`.
    * Increments and prints `map.movements`.
* After movement, `ft_render_assets` redraws the window. If `game_ended`, prints "You won!" and closes.

#### Cleanup :
* Destroys loaded images and the window (if present), frees `parsed_map`, then calls `exit(status)`.
