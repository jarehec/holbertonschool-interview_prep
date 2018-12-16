#!/usr/bin/python3
"""
module containing canUnlockAll function
"""


def canUnlockAll(boxes):
    """ determines if all the boxes can be opened """
    keys = {0}
    done = False

    while not done:
        updated = False
        for i in range(len(boxes)):
            if i in keys:
                for key in boxes[i]:
                    if key not in keys:
                        updated = True
                    keys.add(key)
        done = True if not updated else False
    return len(keys) == len(boxes)
