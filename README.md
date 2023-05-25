<h1 align="center">so_long</h1>
<p align="center">In this project, I created a 2D game from scratch using the minilibx library</p>

![game preview](./documentation/preview.png)

Find more informations about the project requirements [here](./documentation/project_requirements.pdf).

## About the game

Write a program that checks whether a given map is valid, me

The program must be able to read a given map, check if all elements of the map are valid*, display all sprites on a window, and be able to move the player and collect items before exiting the game.

The projects demends that we create a game based on a given map that follows certain rues:
- the map must be stored in a file with <code>.ber</code> extension
- the map can only contain these characters 1 (wall), 0 (empty space), C (collectible), P (starting position), E (exit).
- the map must be rectangular, surrounded by walls and have at least one collectible (C), starting position (P) and exit (E)
- there must be a valid path leading to the exit.

The game must be able to use any map that follows those rules.

Here is what a valid map looks like.

```bash
11111111111
10000E00001
11110001111
1C1110111C1
1C0000000C1
1C000P000C1
11111111111
```

## How it works
### 1. parsing the map
Since the game's foundation is the map, it's the first thing I implemented.

To be able to navigate the map easier, I store it in a matrix. This way, every element of the map will have a coordinate that is easy to access.

First by reading the content of the .ber file. 

I wrote the function ft_split_fd() which combines the get_next_line() and ft_split() functions. It allows me to read a file, save all its content then break it into substring I can store in my matrix.

```C
// game is a pointer to a structure that contains most variables of my game
int	map_checker(t_game *game)
{
	game->map = ft_split_fd(<path-to-mapfile>, <seperator>);
	if (!game->map)
		return (0);
}
```

### 2. path finding
For the map to be valid, I needed to check whether a viable path to the exit was present.
To do so, I opted for a graph algorithm: breath-first search. I chose it because it's implementation straight forward and since I only cared about 
### 2. displaying sprites on the window
### 3. game machanics
### 4. animation

### 5. improvements
- smoother animation
- monster follows the player
- player can move in between tiles instead of jumps
