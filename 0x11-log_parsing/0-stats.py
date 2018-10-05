#!/usr/bin/python3
"""
parses a log file
"""
import sys
from collections import defaultdict

valid_codes = {'200', '301', '400', '401', '403', '404', '405', '500'}
total_size = int()
counter = int()
logs = defaultdict(int)


def handler():
    """ print logs """
    print('File size:', total_size)
    for i in sorted(logs.keys()):
        print('{}: {}'.format(i, logs[i]))


try:
    for line in sys.stdin:
        line = line.split(' ')
        if len(line) == 9:
            total_size += int(line[8])
            if line[7] in valid_codes:
                logs[line[7]] += 1
        if counter == 9:
            handler()
            counter = 0
        else:
            counter += 1
except KeyboardInterrupt:
    handler()
