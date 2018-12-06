#!/usr/bin/python3
"""
Module containing island-perimeter function
"""


def island_perimeter(grid):
    """ calculates the perimeter of a binary island """
    perim = 0
    for row in range(len(grid)):
        for col in range(len(grid[row])):
            if grid[row][col] == 1:
                if row != 0 and row != len(grid) - 1:
                    if grid[row - 1][col] == 0:
                        perim += 1
                    if grid[row + 1][col] == 0:
                        perim += 1
                if row == 0 and grid[row + 1][col] == 0:
                    perim += 1
                if row == len(grid) - 1 and grid[row - 1][col] == 0:
                    perim += 1
                if col != 0 and col != len(grid[row]) - 1:
                    if grid[row][col - 1] == 0:
                        perim += 1
                    if grid[row][col + 1] == 0:
                        perim += 1
                if col == 0 and grid[row][col + 1] == 0:
                    perim += 1
                if col == len(grid[row]) - 1 and grid[row][col - 1] == 0:
                    perim += 1
    return perim
