#!/usr/bin/python3
"""
In a text file, there is a single character H.
Your text editor can execute only two operations in
this file: Copy All and Paste. Given a number n,
write a method that calculates the fewest number
of operations needed to result in exactly n H
characters in the file.
version 1.0
"""


def minOperations(n):
    """
    fn minOperations(n), Returns an integer,
    If n is impossible to achieve, return 0
    """
    try:
        operations = 0
        if n < 2:
            return operations

        for i in range(2, int(n ** 0.5 + 1)):
            # if MOD for n is 0
            while n % i == 0:
                operations += i
                # floor div
                n //= i

        if n >= 2:
            operations += n
        # result
        return operations
    except Exception as e:
        return 0
