#!/usr/bin/python3
'''Module N Queens
   b: The b state.
'''
import sys


def cposition(b, row, col):
    '''Checks position'''
    for c in range(col):
        if b[c] is row or abs(b[c] - row) is abs(c - col):
            return False
    return True


def check(b, col):
    '''backtracking '''
    n = len(b)
    if col is n:
        print(str([[c, b[c]] for c in range(n)]))
        return

    for row in range(n):
        if cposition(b, row, col):
            b[col] = row
            check(b, col + 1)

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)
    if sys.argv[1].isdigit() is False:
        print("N must be a number")
        sys.exit(1)
    if int(sys.argv[1]) < 4:
        print("N must be at least 4")
        sys.exit(1)

    b = [0 for col in range(int(sys.argv[1]))]
    check(b, 0)