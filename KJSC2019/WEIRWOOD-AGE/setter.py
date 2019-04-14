import math
t=int(input())
for _ in range(t):
    a,b,x=map(int,input().split())
    assert  1 <= a <= 10**6
    assert  a <= b <= 10**6
    assert  1 <= x <= (b-a)
    n=((b-a)/x)+1
    print(math.floor(n))
