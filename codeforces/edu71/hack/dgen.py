import sys
from collections import Counter
def input():
	return sys.stdin.readline()[:-1]
MOD = 998244353
n = int(input())
fact = [1]
for i in range(1, n+1):
	fact.append((fact[-1]*i)%MOD)
seq = []
ca, cb = Counter(), Counter()
for _ in range(n):
	a, b = map(int, input().split())
	ca[a] += 1
	cb[b] += 1
	seq.append((a, b))
ans = fact[n]
ans %= MOD
#print(ans)
res = 1
for v in ca.values():
	res *= fact[v]
	res %= MOD
ans -= res
ans %= MOD
#print(ans)
res = 1
for v in cb.values():
	res *= fact[v]
	res %= MOD
ans -= res
#print(ans)
seq.sort(key=lambda x: (x[0], x[1]))
cur = seq[0][0]
res = 1
M = 1
ctmp = Counter()
for i in range(n):
	if seq[i][0] == cur:
		ctmp[seq[i][1]] += 1
		M = max(M, seq[i][1])
	else:
		if seq[i][1] < M:
			res = 0
			break
		tmp = 1
		for v in ctmp.values():
			tmp *= fact[v]
			tmp %= MOD
		res *= tmp
		res %= MOD
		ctmp = Counter()
		ctmp[seq[i][1]] += 1
		cur = seq[i][0]
		M = max(M, seq[i][1])
tmp = 1
for v in ctmp.values():
	tmp *= fact[v]
	tmp %= MOD
res *= tmp
res %= MOD
ans += res
ans %= MOD
print(ans)
