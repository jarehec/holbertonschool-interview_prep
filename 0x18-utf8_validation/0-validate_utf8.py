#!/usr/bin/python3
"""
Module containing utf validator
"""


def to_bin(data):
    """ gives the 8 bit binary representation """
    return [bin(i)[2:].zfill(8) for i in data]


def validUTF8(data):
    """ validates utf8 bytes """
    if len(data) < 1:
        return True
    bin_data = to_bin(data)
    if data[0] <= 127 and data[0] >= 0:
        for i in data:
            if i < 0 or i > 127:
                return False
        return True

    n_bytes = 0
    for i in bin_data[0]:
        if i == '0':
            break
        n_bytes += 1
    return n_bytes == len(data) and n_bytes <= 4
