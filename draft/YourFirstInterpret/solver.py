from collections import defaultdict
import re

def is_numeric(v):
    try: int(v)
    except: return False
    return True

T = int(input())

lines = [input() for _ in [0] * T]

cnt = 0
vals = defaultdict(int)

while 0 <= cnt < T:
    line = lines[cnt]
    tokens = re.split('[ :]', line)
    # print(cnt, line, tokens)
    # print(vals)
    if tokens[0] == '#':
        if is_numeric(tokens[-1]):
            vals[tokens[1]] = int(tokens[-1])
        else:
            vals[tokens[1]] = vals[tokens[-1]]
    if tokens[0] == '$':
        if '+=' in tokens:
            vals[tokens[1]] += vals[tokens[-1]]
        if '*=' in tokens:
            vals[tokens[1]] *= vals[tokens[-1]]
        if '/=' in tokens:
            vals[tokens[1]] /= vals[tokens[-1]]
        if '%=' in tokens:
            vals[tokens[1]] %= vals[tokens[-1]]
    if tokens[0] == '@':
        cnt = int(tokens[-1])
        continue
    if tokens[0] == '%':
        if vals[tokens[1]] == vals[tokens[-3]]:
            cnt = int(tokens[-1])
            continue
    if tokens[0] == '&':
        print(vals[tokens[-1]])
    cnt += 1
