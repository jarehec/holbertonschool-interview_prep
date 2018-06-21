# Menger sponge
Function that draws a 2D Menger Sponge

## Compilation
* `gcc -Wall -Werror -Wextra -pedantic main.c menger.c -o menger`

## Usage
* `./menger <int>`

## Helper Functions
```
/**
 * free_grid - frees memory allocated by 2d array
 * @grid: 2d array of chars
 * @size: size of rows and cols
*/
void free_grid(char **grid, size_t size)

/**
 * fill_perimeter - fills grid perimeter with a pattern
 * @pattern: 2d array of chars
 * @grid: empty 2d array of chars
 * @size: size of grid rows and cols
 */
void fill_perimeter(char **pattern, char **grid, size_t size)

/**
 * print_grid - prints a 2d array of chars
 * @grid: pointer to 2d array
 * @size: size x size grid
*/
void print_grid(char **grid, size_t size)
```

## Authors
* Jared Heck
