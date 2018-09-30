import bisect as bi
t = int(input())
assert(1<=t<=10)
for _ in range(t):
    n,m = map(int,input().split())
    assert(1<=m<=10**5)
    assert(1<=n<=10**4)
    books = list(map(int,input().split()))
    for i in range(m):
        assert(1<=books[i]<=10**5)
    l = list(map(int,input().split()))
    r = list(map(int,input().split()))
    for i in range(n):
        assert(1<=l[i]<=10**5)
        assert(1<=r[i]<=10**5)
    books.sort()
    books_presum = [0]
    for i in range(m):
        books_presum.append(books_presum[i]+books[i])
    for i in range(n):
        left = bi.bisect_left(books,l[i])
        right = bi.bisect_right(books,r[i])-1
        if right<left:
            print(0,0)
        elif left==right:
            print(1,books[left])
        else:
            print(right-left+1,books_presum[right+1]-books_presum[left])
