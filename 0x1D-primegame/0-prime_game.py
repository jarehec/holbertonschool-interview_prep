#!/usr/bin/python3
"""
isWinner function
"""


def isPrime(n: int) -> bool:
    """ determines if n is prime """
    if n <= 1:
        return False
    for i in range(2, (n // 2) + 1):
        if n % i == 0:
            return False
    return True


def isWinner(x, nums):
    """ determines the winner of the game """
    p1 = int()
    p2 = int()

    for turn in range(x):
        for n in range(len(nums)):
            if isPrime(nums[n]):
                temp = nums[n]
                nums.pop(n)
                for i in nums:
                    if i % temp == 0:
                        nums.remove(i)
                if turn % 2 == 0:
                    p1 += 1
                else:
                    p2 += 1
                break

            if n + 1 == len(nums) and p1 == 0 and p2 == 0:
                return None
    if p1 == p2:
        return None
    if p1 > p2:
        return "Maria"
    return "Ben"
