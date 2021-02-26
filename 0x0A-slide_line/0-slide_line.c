#include "slide_line.h"
/**
 * slide_left - slide or colapse the line to the left
 * @line: pointer to array.
 * @size: size of the array
 */
void slide_left(int *line, size_t size)
{
	size_t i, j, k;

	for (i = 0, j = 0; i < size; i++, j++)
	{
		if (line[i] == 0)
			while (line[i] == 0)
				i++;

		j = i + 1;

		if (line[j] == 0)
			while (line[j] == 0)
				j++;

		if (line[i] == line[j])
		{
			line[i] = line[i] * 2;
			line[j] = 0;
			i = j + 1;
		}
		else
			i++;

		j = 0;
	}

	for (i = 0, k = 0; i < size; i++)
		if (line[i] != 0)
			line[k++] = line[i];

	while (k < size)
		line[k++] = 0;
}


/**
 * slide_right - slide or colapse the line to the left.
 * @line: pointer to array
 * @size: size of the array
 */
void slide_right(int *line, size_t size)
{
	size_t i, j;

	for (i = size; i > 0; i--)
	{
		for (j = i - 1; j > 0; j--)
		{
			if (line[i - 1] != 0)
			{
				if (line[i - 1] == line[j - 1])
				{
					line[i - 1] = line[i - 1] * 2;
					line[j - 1] = 0;
					break;
				}

				if (line[i - 1] != line[j - 1] &&
				    line[j - 1] != 0)
					break;
			}
			if (line[i - 1] == 0)
			{
				if (line[j - 1] != 0)
				{
					line[i - 1] = line[j - 1];
					line[j - 1] = 0;
					i++;
					break;
				}
			}
		}
	}
}

/**
 * slide_line - slides and merges an array of integers.
 * @line: pointer to the line to slide.
 * @size: size of line.
 * @direction: SLIDE_LEFT slide to the left the line.
 * SLIDE_RIGHT slide to the right the line
 * Return: 1 upon success, or 0 upon failure.
 */
int slide_line(int *line, size_t size, int direction)
{
	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);
	if (direction == 0)
		slide_left(line, size);
	if (direction == 1)
		slide_right(line, size);
	return (1);
}
