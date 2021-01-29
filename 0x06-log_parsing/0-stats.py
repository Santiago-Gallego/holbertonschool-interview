#!/usr/bin/python3
""" Script that reads stdin line by line and computes metrics."""

import sys

dlist = {"size": 0,
         "lines": 1}

errors = {"200": 0, "301": 0, "400": 0, "401": 0,
          "403": 0, "404": 0, "405": 0, "500": 0}


def printf():
    """ Print codes and numbers"""
    print("File size: {}".format(dlist["size"]))
    for key in sorted(errors.keys()):
        if errors[key] != 0:
            print("{}: {}".format(key, errors[key]))


def datasize(data):
    """ Count file codes and size"""
    dlist["size"] += int(data[-1])
    if data[-2] in errors:
        errors[data[-2]] += 1


if __name__ == "__main__":
    try:
        for line in sys.stdin:
            try:
                datasize(line.split(" "))
            except:
                pass
            if dlist["lines"] % 10 == 0:
                printf()
            dlist["lines"] += 1
    except KeyboardInterrupt:
        printf()
        raise
    printf()
