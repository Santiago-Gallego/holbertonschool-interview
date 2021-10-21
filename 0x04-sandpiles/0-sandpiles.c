#include "sandpiles.h"

/**
 * print_grid - Function that prints the grid
 * @grid: grid with shape of 3
 * Return: Nothing (void)
 */

void print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");
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
 * sum_grids - Function that sum two grids
 * @grid1: sandpiles stable
 * @grid2: sandpiles stable
 * Return: Nothing (void)
 */

void sum_grids(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] = grid1[i][j] + grid2[i][j];
}

/**
 * is_sandpile - Function for check if the grid is a sandpile
 * @grid1: sandpiles stable
 * Return: 1 for false, 0 for true
 */

int is_sandpile(int grid1[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid1[i][j] > 3)
				return (0);
	return (1);
}

/**
 * convert_sandpile - Function that convert the grid into a sandpile
 * @grid1: sandpiles stable
 * Return: Nothing (void)
 */

void convert_sandpile(int grid1[3][3])
{
	int i, j;
	int grid_aux[3][3];

	/** starting the auxiliar in 0 */
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid_aux[i][j] = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			/** verify if the number in the cell is > 3 */
			if (grid1[i][j] > 3)
			{
				grid1[i][j] -= 4;
				if ((i - 1 >= 0) && (i - 1 < 3))
					grid_aux[i - 1][j] += 1;
				if ((j - 1 >= 0) && (j - 1 < 3))
					grid_aux[i][j - 1] += 1;
				if ((i + 1 >= 0) && (i + 1 < 3))
					grid_aux[i + 1][j] += 1;
				if ((j + 1 >= 0) && (j + 1 < 3))
					grid_aux[i][j + 1] += 1;
			}
		}
	}

	sum_grids(grid1, grid_aux);
}

/**
 * sandpiles_sum - Function that computes the sum of two sandpiles
 * @grid1: sandpiles stable
 * @grid2: sandpiles stable
 * Return: Nothing (void)
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	sum_grids(grid1, grid2);

	while (!is_sandpile(grid1))
	{
		print_grid(grid1);
		convert_sandpile(grid1);
	}
}
