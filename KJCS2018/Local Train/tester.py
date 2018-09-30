import math
def powerset(A):
    if A == []:
        return [[]]
    a = A[0]
    incomplete_pset = powerset(A[1:])
    rest = []
    for set in incomplete_pset:
        rest.append([a] + set)
    return rest + incomplete_pset

def lcm(x,y):
    return x*y//math.gcd(x,y)

t = int(input())
assert(1 <= t <= 10**3)    
for _ in range(t):
    n,m = map(int,input().split())
    assert(1 <= n <= 10**18 and 1<= m <= 10)
    train = list(map(int,input().split()))
    for i in train:
        assert(0 <= i <= 10**18)
    for i in range(len(train)):
        train[i]+=1
    s = 0
    l = powerset(train)
    for i in l:
        if len(i)==0:
            continue
        x = i[0]
        for j in range(len(i)-1):
            x = lcm(x,i[j+1])
        if len(i)%2==0:
            s -= n//x
        else:
            s += n//x
    print(n-s)
