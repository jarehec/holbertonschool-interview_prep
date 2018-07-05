#include "sandpiles.h"

/**
 * add_sandpiles - adds two sandpiles, saves result in grid1
 * @grid1: sandpile #1
 * @grid2: sandpile #2
 */
void add_sandpiles(int grid1[3][3], int grid2[3][3])
{
	size_t i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];
}

/**
 * is_stable - checks if the pile has any values > 3
 * @grid: 3x3 grid
 * Return: boolean
 */
char is_stable(int grid[3][3])
{
	size_t i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (0);
		}
	return (1);
}

/**
 * mr_topple - tries his best to remove piles higher than 4
 * @grid: a 3x3 grid
 */
void mr_topple(int grid[3][3])
{
	int chart[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
	size_t i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid[i][j] > 3)
				chart[i][j] = 1;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3 && chart[i][j] == 1)
			{
				grid[i][j] -= 4;
				if (i > 0)
					grid[i - 1][j] += 1;
				if (i < 2)
					grid[i + 1][j] += 1;
				if (j > 0)
					grid[i][j - 1] += 1;
				if (j < 2)
					grid[i][j + 1] += 1;
			}
		}
}

/**
 * print_grid - prints a 3x3 grid
 * @grid: 3x3 grid
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * sandpiles_sum - calculates the sum of two sandpiles
 * and stores result in grid1
 * @grid1: sandpile #1
 * @grid2: sandpile #2
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	add_sandpiles(grid1, grid2);
	for (; !is_stable(grid1); mr_topple(grid1))
	{
		puts("=");
		print_grid(grid1);
	}
}
