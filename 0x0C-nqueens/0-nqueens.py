#!/usr/bin/python3
"""
<<<<<<< HEAD
N-queens
"""


class QueenChessBoard:
    def __init__(self, size):
        self.size = size
        self.columns = []

    def place_in_next_row(self, column):
        self.columns.append(column)

    def remove_in_current_row(self):
        return self.columns.pop()

    def is_this_column_safe_in_next_row(self, column):
        row = len(self.columns)
        for queen_column in self.columns:
            if column == queen_column:
                return False

        for queen_row, queen_column in enumerate(self.columns):
            if queen_column - queen_row == column - row:
                return False
=======
N queens
"""

import sys
>>>>>>> d8d069e4e82052e6617d3bfc437ea8f23f581f70

        for queen_row, queen_column in enumerate(self.columns):
            if ((self.size - queen_column) - queen_row ==
                    (self.size - column) - row):
                return False

<<<<<<< HEAD
        return True

    def display(self):
        lista = []
        for row in range(self.size):
            for column in range(self.size):
                if column == self.columns[row]:
                    lista.append([row, column])
        print(lista, end='')


def solve_queen(size):
    board = QueenChessBoard(size)
    number_of_solutions = 0
    row = 0
    column = 0

    while True:
        while column < size:
            if board.is_this_column_safe_in_next_row(column):
                board.place_in_next_row(column)
                row += 1
                column = 0
                break
            else:
                column += 1

        if (column == size or row == size):
            if row == size:
                board.display()
                print()
                number_of_solutions += 1
                board.remove_in_current_row()
                row -= 1

            try:
                prev_column = board.remove_in_current_row()
            except IndexError:
                break

            row -= 1
            column = 1 + prev_column


if __name__ == "__main__":
    import sys

    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)
    if sys.argv[1].isdigit() is False:
        print("N must be a number")
        sys.exit(1)
    if int(sys.argv[1]) < 4:
        print("N must be at least 4")
        sys.exit(1)

    solve_queen(int(sys.argv[1]))
=======
def is_not_safe_position(board, i, j, r):
    """
    Method that determines if position (i, j) on the chessboard is safe
    to allocate a queen.
    Args:
        - board (list):     list
        - i     (int):      x coordinate to be evaluated
        - j     (int):      y coordinate to be evaluated
        - r     (int):      current row
    Returns:
        True    (bool):     in case it is safe
        False   (bool):     in case it is not safe
    """

    # Is board[i] in line of attack ?
    if (board[i] == j) or (board[i] == j - i + r) or (board[i] == i - r + j):
        return True
    return False


def find_positions(board, row, n):
    """
    Recursive method that finds all safe position (i, j) where n queens
    can be allocated.
    Args:
        - board (list):     list
        - row   (int):      current row
        - n     (int):      number of queens to be allocated
    Returns:
        -       (lists):    lists of all possible solutions
    """

    if row == n:
        print_chess_board(board, n)

    else:
        for j in range(n):
            legal = True
            for i in range(row):
                if is_not_safe_position(board, i, j, row):
                    legal = False
            if legal:
                board[row] = j
                find_positions(board, row + 1, n)


def print_chess_board(board, n):
    """
    Method that generates the list of positions (i, j) where n queens
    were allocated.
    Args:
        - board (list):     list
        - n     (int):      number of queens to be allocated
    Returns:
        - nothing
    """

    b = []

    for i in range(n):
        for j in range(n):
            if j == board[i]:
                b.append([i, j])
    print(b)


def create_chess_board(size):
    """
    Method that generates a list of zeros
    Args:
        - size  (int):      number of queens to be allocated
    Returns:
        - board (list)
    """

    return [0 * size for i in range(size)]


# 1. Read and validate size of the board
if len(sys.argv) != 2:
    print("Usage: nqueens N")
    exit(1)

try:
    n = int(sys.argv[1])
except BaseException:
    print("N must be a number")
    exit(1)

if (n < 4):
    print("N must be at least 4")
    exit(1)

# 2. Generate the board
board = create_chess_board(int(n))

# 3. Find the solutions
row = 0
find_positions(board, row, int(n))
>>>>>>> d8d069e4e82052e6617d3bfc437ea8f23f581f70
