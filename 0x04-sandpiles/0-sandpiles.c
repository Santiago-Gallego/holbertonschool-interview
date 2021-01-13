#include <stdlib.h>
#include <stdio.h>

#include "sandpiles.h"

/**
 * sandpiles_sum - fn sum 2 sandpiles list
 * @grid1: sandpile 1
 * @grid2: sandpile 2
 * Return: None
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, x = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
		}
	}
	printf("=\n");
	print_grid(grid1);
	x = check_non_stable(grid1);
	if (x != 0)
	{
		while (x != 0)
		{
			toppling(grid1);
			x = check_non_stable(grid1);
			if (x != 0)
			{
				printf("=\n");
				print_grid(grid1);
			}
		}
	}
}

/**
 * check_non_stable - fn check  is stable
 * @grid1: sandpile 1
 * Return: 1 if not stable otherwise 0
 */
int check_non_stable(int grid1[3][3])
{
	int i, j, x = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			x = 1;
		}
	}
	return (x);
}

/**
 * toppling - fn toppling for sandpiles
 * @grid1: sandpile 1
 * Return: None
 */
void toppling(int grid1[3][3])
{
	int i, j, possibly[3][3];

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
				possibly[i][j] = 1;
			else
				possibly[i][j] = 0;
		}
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (possibly[i][j] == 1)
			{
				grid1[i][j] = grid1[i][j] - 4;
				if (i - 1 >= 0)
					grid1[i - 1][j] = grid1[i - 1][j] + 1;
				if (i + 1 <= 2)
					grid1[i + 1][j] = grid1[i + 1][j] + 1;
				if (j - 1 >= 0)
					grid1[i][j - 1] = grid1[i][j - 1] + 1;
        if (j + 1 <= 2)
					grid1[i][j + 1] = grid1[i][j + 1] + 1;
			}
		}
	}
}
