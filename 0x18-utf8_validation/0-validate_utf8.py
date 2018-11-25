#!/usr/bin/python3
"""
Module containing utf validator
"""


def validUTF8(data):
    """ validates utf8 bytes """
    try:
        bytes([i for i in data])
        return True
    except:
        return False
