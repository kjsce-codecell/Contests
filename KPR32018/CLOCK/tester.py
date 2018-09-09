t=int(input())
for _ in range(t):
    h, m, s, x = map(int, input().split())
    x = x%360
    m += (x%30)*2

    h += x//30 + (m//60)
    m%=60
    h%=12
    print(h if h != 0 else 12, m, s)