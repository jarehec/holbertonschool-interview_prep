#!/usr/bin/python3
"""
modulue containing minOperations and helper functions
"""


def gcd(n):
    """ returns the greatest divisor into n """
    for i in range(n // 2, 0, -1):
        if n % i == 0:
            return i


def get_divisors(n):
    """ returns all the divisors into n """
    l = [n]
    while gcd(n) != 1:
        n = gcd(n)
        l.append(n)
    return l


def minOperations(n):
    """ calculates the minimum operations to reach n characters in a file """
    if n <= 1:
        return 0
    divisors = get_divisors(n)
    if len(divisors) == 1:
        return n

    ops = 0
    offset = -1
    size = 1

    while size != n:
        if divisors[offset] % size == 0:
            ops += divisors[offset] // size
            size *= divisors[offset] // size
            offset = offset - 1 if -len(divisors) < offset else offset
        else:
            ops += 1
            size += 1
    return ops
