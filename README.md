*This Project Has Been Created As Part Of The 42 Curriculum By **Vorhansa***

## Description
    
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
## Instrctions

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

## Resources

* [So_long tutorial](https://medium.com/@digitalpoolng/42-so-long-and-thanks-for-all-the-fish-building-your-first-2d-game-in-c-ccd24034bc8b)
* [minilibx](https://harm-smits.github.io/42docs/libs/minilibx)

## Additional

* LIBFT