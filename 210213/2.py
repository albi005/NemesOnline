# 0/100

from typing import Counter

n = input().split()[0]
ns = map(int, input().split())
c = Counter()
for i in ns:
    c[i] = 0
num_of_k = int(input())
for _ in range(num_of_k):
    result = 0
    a, b = map(int, input().split())
    for i in c:
        if a <= i <= b:
            result += 1
    print(result)

# TODO: THIS IS TOO EASY, DO IT AGAIN