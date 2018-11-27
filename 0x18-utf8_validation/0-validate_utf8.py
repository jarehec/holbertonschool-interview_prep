#!/usr/bin/python3
"""
Module containing utf validator
"""


def validUTF8(data):
    """ validates utf8 bytes """
    if len(data) < 1:
        return True
    offset = 0
    size = len(data)
    print(data)
    while offset < size:
        n_bytes = 0
        if offset == (size - 1) and data[offset] > 127:
            return False
        if data[offset] <= 127 and data[offset] >= 0:
            offset += 1
            continue
        for i in bin(data[offset])[2:].zfill(8):
            if i == '0':
                break
            n_bytes += 1
        for i in data[offset + 1: offset + n_bytes]:
            if bin(i)[2:].zfill(8)[:2] != '10':
                return False
        offset += n_bytes
        if n_bytes > 4 or offset > size:
            return False
    return True
