#include <stdio.h>
#include "sandpiles.h"

/**
 * matrix_output - sand_pile output
 *
 * @sand_pile: sandpile
 *
 * Return: void
 */

static void matrix_output(int sand_pile[3][3])
{
    int index, index_nest;

    for (index = 0; index < 3; index++)
    {
        for (index_nest = 0; index_nest < 3; index_nest++)
        {
            if (index_nest)
                printf(" ");
            printf("%d", sand_pile[index][index_nest]);
        }
        printf("\n");
    }
}

/**
 * point_sand - full sand
 *
 * @sand_pile: sandpile pointer
 *
 * Return: bool stable
 */

void point_sand(int *sand_pile)
{
    int new[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};
    int index = 0;

    for (; index < 9; index++)
    {
        if (*(sand_pile + index) > 3)
        {
            *(sand_pile + index) -= 4;
            if (index / 3 != 0)
                new[(index / 3) - 1][index % 3] += 1;
            if (index / 3 != 2)
                new[(index / 3) + 1][index % 3] += 1;
            if (index % 3 != 0)
                new[index / 3][(index % 3) - 1] += 1;
            if (index % 3 != 2)
                new[index / 3][(index % 3) + 1] += 1;
        }
        new[index / 3][index % 3] += *(sand_pile + index);
    }
    for (index = 0; index < 9; index++)
    {
        *(sand_pile + index) = new[index / 3][index % 3];
    }
}

/**
 * checker - is sandpile stable
 *
 * @sand_pile: sandpile
 *
 * Return: bool stable
 */
int checker(int *sand_pile)
{
    int index, res_check = 0;

    for (index = 0; index < 9; index++)
    {
        if (*(sand_pile + index) > 3)
            res_check = 1;
    }
    return (res_check);
}

/**
 * sandpiles_sum - Sum sandpiles
 *
 * @grid1: sandpile
 * @grid2: sandpile
 *
 * Return: void
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int *grid3 = &grid1[0][0];
    int index, index_nest, res_check = 0;

    for (index = 0; index < 3; index++)
    {
        for (index_nest = 0; index_nest < 3; index_nest++)
        {
            grid1[index][index_nest] += grid2[index][index_nest];
            if (grid1[index][index_nest] > 3)
                res_check = 1;
        }
    }
    while (res_check)
    {
        printf("=\n");
        matrix_output(grid1);
        point_sand(grid3);
        res_check = checker(grid3);
    }
}