from bisect import bisect
t = int(input())
assert 1<=t<=100
for _ in range(t):
    n,q = map(int,input().split())
    assert 1<=n<=365
    assert 1<=q<=1000
    a = list(map(int,input().split()))
    for i in range(n):
        assert 1<=a[i]<=1500
    pre = [a[0]]
    for i in range(1, n):
        pre.append(pre[-1]+a[i])
    for i in range(q):
        v = int(input())
        assert 10000<=v<=20000
        count = 0
        x = 0
        prex = 0
        V = v
        while True:
            x = bisect(pre, V)
            V = pre[x-1] + v
            if x>=n:
                break
            count += 1
            prex = x
        print(count, prex)
