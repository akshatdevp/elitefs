def m1(arr):
        s1 = set()
        cur = {0}
        for x in arr:
            cur = {x | y for y in cur} | {x}
            s1 |= cur
        return len(s1)