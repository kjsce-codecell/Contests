import sys
t=int(input())
for _ in range(t):
    n = int(input())
    l = sys.stdin.readline().split()
    finlist = []
    for i in range(n):
        finlist.append([len(l[i]),l[i]])
    finlist.sort(reverse=True)
    for i in finlist:
        print(i[1], end=" ")
    print() 