#include "menger.h"

/**
 * free_grid - frees memory allocated by 2d array
 * @grid: 2d array of chars
 * @size: size of rows and cols
*/
void free_grid(char **grid, size_t size)
{
	size_t row;

	if (size == 0)
		return;
	for (row = 0; row < size; row++)
		free(grid[row]);
	free(grid);
}

/**
 * fill_perimeter - fills grid perimeter with a pattern
 * @pattern: 2d array of chars
 * @grid: empty 2d array of chars
 * @size: size of grid rows and cols
 */
void fill_perimeter(char **pattern, char **grid, size_t size)
{
	size_t i, j, k, row, col, stride = size / 3;

	if (!pattern)
	{
		grid[0][0] = '#';
		return;
	}
	for (i = 0, row = 0; row < size; row += stride, i++)
		for (col = 0; col < size; col += stride, i++)
		{
			for (j = 0; j < stride; j++)
				for (k = 0; k < stride; k++)
				{
					if (i != 5)
						grid[row + j][col + k] = pattern[j][k];
					else
						grid[row + j][col + k] = ' ';
				}
		}
}

/**
 * print_grid - prints a 2d array of chars
 * @grid: pointer to 2d array
 * @size: size x size grid
*/
void print_grid(char **grid, size_t size)
{
	size_t row, col;

	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
			putchar(grid[row][col]);
		putchar('\n');
	}
}

/**
 * menger - prints a 2d menger sponge
 * @lvl: level of the sponge
 */
void menger(int lvl)
{
	char **grid = NULL, **block = NULL;
	int i = 0;
	size_t x = 0, size, idk, tmp = 0;

	if (lvl < 0)
		return;
	while (i <= lvl || lvl == 0)
	{
		size = pow(3, x);
		block = malloc(sizeof(char *) * size);
		for (idk = 0; idk < size; idk++)
			block[idk] = malloc(sizeof(char) * size);
		fill_perimeter(grid, block, size);
		free_grid(grid, tmp);
		if (i == lvl || lvl == 0)
		{
			print_grid(block, size);
			free_grid(block, size);
			return;
		}
		tmp = size;
		++x, ++i;

		size = pow(3, x);
		grid = malloc(sizeof(char *) * size);
		for (idk = 0; idk < size; idk++)
			grid[idk] = malloc(sizeof(char) * size);
		fill_perimeter(block, grid, size);
		free_grid(block, tmp);
		if (i == lvl)
		{
			print_grid(grid, size);
			free_grid(grid, size);
			return;
		}
		tmp = size;
		++x, ++i;
	}
}
