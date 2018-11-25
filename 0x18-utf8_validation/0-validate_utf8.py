#!/usr/bin/python3
"""
Module containing utf validator
"""


def validUTF8(bytes_list=[]):
    for i in bytes_list:
        if not chr(i).isprintable():
            return False
        elif i >= 0x0000 and i <= 0x007F:
            pass
        elif i >= 0x0080 and i <= 0x07FF:
            pass
        elif i >= 0x0800 and i <= 0x10FFFF:
            pass
        else:
            return False
    return True
