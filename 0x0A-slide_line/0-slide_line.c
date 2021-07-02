#include "slide_line.h"
/**
 * slide_line - slide or colapse the line
 * @line: pointer to array.
 * @size: size of the array
 */
int slide_line(int *line, size_t size, int direction)
{
	size_t pos_find = 0, pos_rep = 0, inc = 1, stop = size;
	int d_flag = -1;

	if (!line || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
		return (0);

	if (direction == SLIDE_RIGHT)
	{
		pos_find = size - 1;
		pos_rep = size - 1;
		inc = -1;
		stop = -1;
	}

	while (pos_find != stop)
	{
		if (*(line + pos_find) != 0)
		{
			if (d_flag == *(line + pos_find))
			{
				*(line + pos_find) += d_flag;
				d_flag = -1;
			}
			else
			{
				d_flag = *(line + pos_find);
				if ((direction == SLIDE_LEFT && pos_find != 0)
					||
					((direction == SLIDE_RIGHT && pos_find != (size - 1))))
					if (*(line + pos_rep) != 0)
						pos_rep += inc;
			}
			*(line + pos_rep) = *(line + pos_find);
			if (pos_rep != pos_find)
				*(line + pos_find) = 0;
		}
		pos_find += inc;
	}

	return (1);
}
