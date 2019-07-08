import math
T = int(input())
while T > 0:
    T -= 1
    nums = input().split()
    n, k = int(nums[0]), int(nums[1])
    a = [int(x) for x in input().split()]

    lower_bound = a[0] - k
    upper_bound = a[0] + k
    for x in a:
        if x - k > lower_bound:
            lower_bound = x - k
        if x + k < upper_bound:
            upper_bound = x + k
    if lower_bound <= upper_bound:
        print(upper_bound)
    else:
        print (-1)