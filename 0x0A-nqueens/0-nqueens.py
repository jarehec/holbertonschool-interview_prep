#!/usr/bin/python3

from sys import argv, exit

if len(argv) != 2:
    print('Usage: nqueens N')
    exit(1)

try:
    N = int(argv[1])
except:
    print('N must be a number')
    exit(1)

if N < 4:
    print('N must be at least 4')
    exit(1)


def print_queens(board):
    """ prints queen indexes """
    indexes = list()
    for row in range(N):
        for col in range(N):
            if board[col][row] == 1:
                indexes.append([row, col])
    print(indexes)


def is_safe(board, row, col):
    """ is the queen safe at this position? """
    if 1 in board[row]:
        return False
    i = row
    j = col
    while i >= 0 and j >= 0:
        if board[i][j] == 1:
            return False
        i -= 1
        j -= 1
    i = row
    j = col
    while i < N and j >= 0:
        if board[i][j] == 1:
            return False
        i += 1
        j -= 1
    return True


def nqueens(board, col):
    """ beginning of n queens algo"""
    if col == N:
        print_queens(board)
        return True
    res = False
    for i in range(N):
        if is_safe(board, i, col):
            board[i][col] = 1
            res = nqueens(board, col + 1) or res
            board[i][col] = 0
    return res

chessboard = []
for i in range(N):
    chessboard.append([0]*N)
nqueens(chessboard, 0)
