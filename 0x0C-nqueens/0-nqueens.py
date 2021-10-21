#!/usr/bin/python3
"""
N queens puzzle is the challenge of placing N non-attacking queens
"""
import sys


def printB(brd):
    """
    print board
    """
    r = []
    for x in brd:
        for c in x:
            if c == 1:
                r.append([brd.index(x), x.index(c)])
    print(r)


def is_safe(brd, row, col, n):
    """
    is_safe
    """
    for i in range(col):

        if brd[row][i] + brd[row][i + 1] != 0:
            return False

    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if brd[i][j] == 1:
            return False

    for i, j in zip(range(row, n, 1), range(col, -1, -1)):
        if brd[i][j] == 1:
            return False

    return True


def nqueen(brd, col, n):
    """
    nqueen
    """

    if (col >= n):
        printB(brd)

    for x in range(n):
        if is_safe(brd, x, col, n):
            brd[x][col] = 1
            if nqueen(brd, col+1, n):
                return True
            brd[x][col] = 0

    return False


# initial run starting from the col 0!
def main():
    """
    Main
    """
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        exit(1)
    if sys.argv[1].isnumeric():
        n = int(sys.argv[1])
    else:
        print("N must be a number")
        exit(1)
    if n < 4:
        print("N must be at least 4")
        exit(1)
    brd = [[0 for x in range(n)] for y in range(n)]
    nqueen(brd, 0, n)


if __name__ == '__main__':
    main()