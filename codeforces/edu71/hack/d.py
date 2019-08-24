from collections import defaultdict
 
 
def per(arr, F):
    s = defaultdict(int)
    for a in arr:
        s[a] += 1
    res = 1
    for v in s.itervalues():
        if v > 0:
            res *= F[v]
            res %= 998244353
    return res
 
 
def getB(arr, F):
    a = map(lambda x: x[1], arr)
    for i in xrange(len(a) - 1):
        if a[i] > a[i + 1]:
            return 0
 
    return per(arr, F)
 
def solve(arr):
    F = [1]
    for i in xrange(1, len(arr) + 1):
        F.append((F[-1] * i) % 998244353)
    per1 = per(map(lambda x: x[0], arr), F)
    per2 = per(map(lambda x: x[1], arr), F)
    all = F[len(arr)]
    arr = sorted(arr)
    both = getB(arr, F)
 
    return (all - per1 - per2 + both) % 998244353
 
 
import sys
 
n = input()
arr = []
for i in xrange(n):
    arr.append(tuple(map(int, sys.stdin.readline().split())))
print solve(arr)
