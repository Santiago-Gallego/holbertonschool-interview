#ifndef _SANDPILES_
#define _SANDPILES_
#include <stdlib.h>

void print_grid_sum(int grid1[3][3], int grid2[3][3]);
void print_grid(int grid[3][3]);
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
int check_non_stable(int gridx[3][3]);
void toppling(int gridx[3][3]);

#endif /* _SANDPILES_ */
