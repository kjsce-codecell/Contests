def outofrange(remaining, n, p, k):
	if remaining > p+k:
		return True
	else:
		return False

t = int(input())
for i in range(t):
    n,p, k = map(int, input().split(" "))
    l = list(map(int, input().split(" ")))
    if n<p or n%p > k:
        print("NO",end="\n")
    else:
        l.sort()
        divideafter = []
        #print(l)
        i = 1
        while outofrange(n-i+1,n,p,k):
        	divideafter.append(i*p-1)
        	i+=p
        #print(divideafter)
        for e in divideafter:
        	if l[e] >= l[e+1]:
        		print("NO")
        		break
        else:
            print("YES",end="\n")	
        '''for i in range(1, n//p):
        #    print()
            if l[i*p-1] >= l[i*p]:
                print("NO",end="\n")
                break'''