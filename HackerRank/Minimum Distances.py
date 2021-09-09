#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'minimumDistances' function below.
#
# The function is expected to return an INTEGER.
# The function accepts INTEGER_ARRAY a as parameter.
#


def minimumDistances(arr):
    seen = dict()
    min_diff = None
    for i, a in enumerate(arr):
        if a in seen:
            a_index = seen[a]
            diff = i - a_index
            if (min_diff is None) or diff < min_diff:
                min_diff = diff
        else:
            seen[a] = i
    return -1 if min_diff is None else min_diff


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    a = list(map(int, input().rstrip().split()))

    result = minimumDistances(a)

    fptr.write(str(result) + '\n')

    fptr.close()
