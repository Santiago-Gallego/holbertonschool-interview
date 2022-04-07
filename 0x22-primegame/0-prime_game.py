#!/usr/bin/python3
""" Prime Game """


def prime_colander(n, primes):
    """No prime"""
    lastPrime = primes[-1]
    if n > lastPrime:
        for i in range(lastPrime + 1, n + 1):
            if primer_multiple_colander(i):
                primes.append(i)
            else:
                primes.append(0)


def primer_multiple_colander(n):
    """Remove multiples of prime"""
    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            return False
    return True


def isWinner(x, nums):
    """Determine who wins the game"""
    players = {"Maria": 0, "Ben": 0}
    primes = [0, 0, 2]
    prime_colander(max(nums), primes)

    for round in range(x):
        total = sum((i != 0 and i <= nums[round])
                    for i in primes[:nums[round] + 1])
        if (total % 2):
            winner = "Maria"
        else:
            winner = "Ben"
        if winner:
            players[winner] += 1

    if players["Maria"] > players["Ben"]:
        return "Maria"
    if players["Maria"] < players["Ben"]:
        return "Ben"
    else:
        return None
