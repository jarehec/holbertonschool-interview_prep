#!/usr/bin/python3
"""
pascal_triangle
"""


def pascal_triangle(n):
    """ creates a list of integers that represent pascals triangle """
    if n < 1:
        return []
    triangle = [[1]]

    for i in range(1, n):
        triangle.append([0] * (len(triangle[i - 1]) + 1))
        triangle[i][0] = 1
        triangle[i][-1] = 1
        for j in range(1, len(triangle[i]) - 1):
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j]
    return triangle
