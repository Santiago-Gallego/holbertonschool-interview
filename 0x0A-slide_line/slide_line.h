#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H

#define SLIDE_LEFT 0
#define SLIDE_RIGHT 1

#include <stdlib.h>

int slide_line(int *line, size_t size, int direction);
void swap(int *min_n, int *n);
void sort(int *line, size_t size);
void left(int *line, size_t size);

#endif /* SLIDE_LINE_H */
