t=int(input())
while(t>0):
    a=map(int,input().split())
    a=list(a)
    d=int(input())
    sum=0
    for i in a:
        sum=sum+i
    ans=int(int(sum-(2*a[0])-(4*d))/int(13))
    print(ans)
    t=t-1
