from itertools import accumulate

# Thanks to: https://ikatakos.com/pot/programming_algorithm/data_structure/binary_indexed_tree
class BIT:
    def __init__(self, n):
        self.size = n
        self.data = [0] * (n + 1)

    def sum(self, l, r):
        return self._sum(r) - self._sum(l)

    def _sum(self, p):
        s = 0
        while p > 0:
            s += self.data[p]
            p -= p & -p
        return s

    def add(self, p, x):
        p += 1
        while p <= self.size:
            self.data[p] += x
            p += p & -p

K, T = map(int, input().split())

D = [*map(int, input().split())]
V = [0]; V.extend(accumulate(map(int, input().split())))
print(V)

S = [*map(lambda p: p[0] - T*p[1], zip(D, V))]
print(S)

ranks = { x : i for i, x in enumerate(sorted(list(set(S)))) }
comp_S = []
for s in S:
  comp_S.append(ranks[s])
print(comp_S)

bit = BIT(K+1)

ans = 0
for i, s in enumerate(comp_S):
    ans += i - bit.sum(0, s+1)
    bit.add(s, 1)

print(ans)
