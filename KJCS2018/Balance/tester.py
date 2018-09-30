def gcd(x, y):
    if x == 0:
        return y
    else:
        return gcd(y%x, x)
def lcm(x, y):
    return x*y//(gcd(max(x, y), min(x, y)))

t = int(input())
assert(t<=10**5)
for i in range(t):
    x, y, n, m = map(int, input().split())
    assert(x<=10**7 and y<=10**7 and n <= 10**7 and m <=10**7)
    l = lcm(x, y)
    p = l//x
    q = l//y
    print('YES') if p<=n and q<=m else print('NO')

    