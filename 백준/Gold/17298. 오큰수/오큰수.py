import sys
input = sys.stdin.readline 
n = int(input())
li = list(map(int, input().split())) 
chk = [-1] * n; sli = [0]
for i in range(1, n):
    while sli and li[sli[-1]] < li[i]:
        chk[sli.pop()] = li[i]
    sli += [i]
print(*chk)