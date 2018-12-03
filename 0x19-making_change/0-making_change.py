#!/usr/bin/python3
"""
module containing makeChange
"""


def coinChange(coins, total):
    """ calculates the minimum amount of coins to meet a given amount """
    if total < 1:
        return 0
    amount, i = int(), -1
    coins.sort()
    while total > 0 and i > -len(coins):
        if total % coins[i] == 0:
            amount += (total // coins[i])
            total -= (total // coins[i]) * coins[i]
        elif total > coins[i]:
            amount += (total // coins[i])
            total -= (total // coins[i]) * coins[i]
        i -= 1
    return amount if total == 0 else -1
