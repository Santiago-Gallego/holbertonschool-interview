#!/usr/bin/python3
"""
reads stdin line by line and computes metrics
"""

import sys

STATUS = {'200': 0,
          '301': 0,
          '400': 0,
          '401': 0,
          '403': 0,
          '404': 0,
          '405': 0,
          '500': 0}

total_size = 0
n = 0
try:
    for argument in sys.stdin:
        arguments = argument.split(" ")
        if len(arguments) > 2:
            status = arguments[-2]
            file_size = int(arguments[-1])
            if status in STATUS:
                STATUS[status] += 1
            total_size += file_size
            n += 1
            if n == 10:
                print("File size: {:d}".format(total_size))
                for key, value in sorted(STATUS.items()):
                    if value != 0:
                        print("{}: {:d}".format(key, value))
                n = 0
except KeyboardInterrupt:
    pass
finally:
    print("File size: {:d}".format(total_size))
    for key, value in sorted(STATUS.items()):
        if value != 0:
            print("{}: {:d}".format(key, value))
