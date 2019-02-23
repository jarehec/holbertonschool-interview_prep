#!/usr/bin/python3
"""
trapping rain water solution
"""


def rain(walls):
    """ finds the volume of water held by walls """
    h, hh = int(), int()
    left = [0] * len(walls)
    for i in range(len(walls)):
        left[i] = h
        if h < walls[i]:
            h = walls[i]

    right = [0] * len(walls)
    for i in range(len(walls)-1, -1, -1):
        right[i] = hh
        if hh < walls[i]:
            hh = walls[i]

    total_sum = 0
    for i in range(len(left)):
        lowest_wall = min(left[i], right[i])
        if lowest_wall - walls[i] > 0:
            lowest_wall -= walls[i]
        else:
            lowest_wall = 0
        total_sum += lowest_wall
    return total_sum
