import sys
t=int(input())
#print(t)
for _ in range(t):
    n = int(input())
    #print(n)
    l = sys.stdin.readline().split()
    l = list(map(int,l))
    l.sort(reverse=True)
    for i in l:
        print(i, end=" ")
    print()