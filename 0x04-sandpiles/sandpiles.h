#ifndef SANDPILES_H
#define SANDPILES_H

#include <stdlib.h>
#include <stdio.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);

/** Auxiliar functions */
void sum_grids(int grid1[3][3], int grid2[3][3]);
int is_sandpile(int grid1[3][3]);
void convert_sandpile(int grid1[3][3]);

#endif /** SANDPILES_H */
