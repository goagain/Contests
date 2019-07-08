T = int(input())

while T > 0:
    T -= 1
    n = int(input())
    nums = [int(x) for x in input().split()]
    map = {}
    for x in nums:
        if x in map:
            map[x] += 1
        else:
            map[x] = 1
    count_map = {}
    for key in map:
        if map[key] in count_map:
            count_map[map[key]] += 1
        else:
            count_map[map[key]] = 1
    count_map[0] = 1

    result = 0
    last = -1
    l = reversed(sorted(list(count_map.keys())))
    for key in l:
        result += key
        count_map[key] -= 1
        if last != -1:
            if count_map[last] > 0:
                upper_bound = last - 1
                count = min(count_map[last], upper_bound - key)
                lower_bound = upper_bound - count + 1
                result += (lower_bound + upper_bound) * count // 2
                count_map[key] += (count_map[last] - count)
        last = key
    print(result)