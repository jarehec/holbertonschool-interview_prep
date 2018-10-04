#!/usr/bin/python3
"""
parses a log file
"""
import fileinput
import signal
from collections import defaultdict

valid_codes = {'200', '301', '400', '401', '403', '404', '405', '500'}
total_size = int()
counter = int()
logs = defaultdict(int)


def handler(signum, frame):
    """ signal handler """
    print('File size:', total_size)
    for i in sorted(logs.keys()):
        print('{}: {}'.format(i, logs[i]))
    counter = 0

signal.signal(signal.SIGINT, handler)

for line in fileinput.input():
    line = line.split(' ')
    if len(line) == 9:
        total_size += int(line[8])
        if len(valid_codes.intersection({line[7]})) == 1:
            logs[line[7]] += 1
    if counter == 9:
        print('File size:', total_size)
        for i in sorted(logs.keys()):
            print('{}: {}'.format(i, logs[i]))
        counter = 0
    else:
        counter += 1
