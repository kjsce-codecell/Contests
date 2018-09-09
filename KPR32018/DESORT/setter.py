import sys
t=int(input())
for _ in range(t):
    n = int(input())
    l = sys.stdin.readline().split()
    l = list(map(int,l))
    l.sort(reverse=True)
    for i in l:
        print(i, end=" ")
    print()