#!/usr/bin/python3
"""
modulue containing minOperations and helper functions
"""


def gcd(n: int):
    """ returns the greatwst divisor into n """
    d = 1
    for i in range(d, n // 2 + 1):
        if n % i == 0:
            d = i
    return d


def get_divisors(n: int):
    """ returns all the divisors into n """
    l = [n]
    while gcd(n) != 1:
        n = gcd(n)
        l.append(n)
    return l


def minOperations(n):
    """ calculates the minimum operations to reach n characters in a file """
    divisors = get_divisors(n)
    if len(divisors) == 1:
        return n
    ops = 0
    offset = -1
    size = 1
    while size != n:
        if divisors[offset] // 2 == size:
            ops += 2
            size *= 2
            offset = offset - 1 if -len(divisors) < offset else offset
        elif size*size == divisors[offset]:
            ops += size
            size *= size
            offset = offset - 1 if -len(divisors) < offset else offset
        else:
            ops += 1
            size += 1
    return ops
