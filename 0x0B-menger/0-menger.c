#include "menger.h"
/**
 * menger - draws a 2D Menger Sponge
 * @level: the level of the Menger Sponge to draw.
 */
void menger(int level)
{
	int size, row, col;
	char character;

	size = pow(3, level);

	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
		{
			character = get_c(row, col);
			printf("%c", character);
		}
		printf("\n");
	}
}
/**
 * get_c - get the character for each coordinate
 * @row: current row.
 * @col: current col.
 * Return: # or ' '
 */
char get_c(int row, int col)
{
	while (row || col)
	{
		if (row % 3 == 1 && col % 3 == 1)
			return (' ');
		row /= 3;
		col /= 3;
	}
	return ('#');
}
