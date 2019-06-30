T = int(input())

while T > 0:
    T -= 1
    nums = [int(x) for x in input().split()]
    k, n, a, b = nums[0], nums[1], nums[2], nums[3]
    k -= 1
    just_play = k // a
    max_charge_and_play = k // b
    if max_charge_and_play >= n:
        if just_play >= n:
            print(min(just_play, n))
        else:
            l = 0
            r = max_charge_and_play
            while l < r:
                m = (l + r) // 2
                if m * b + (n-m) * a <= k:
                    r = m
                else:
                    l = m + 1
            print(n - l)
    else:
        print(-1)