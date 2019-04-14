from math import gcd
t = int(input())
assert(t<=10),"t"

def gcdblock(blocknum, blocksize, a):
    g = 0
    #print(a, blocknum)
    for i in range(blocknum*blocksize, (blocknum+1)*blocksize):
        #print(i)
        g=gcd(g, a[i])
        #print(g)
    #print(g)
    return g

for __ in range(t):
    n, q = map(int, input().split())
    assert(n<=10000),"n"
    assert(q<=10000),"q"
    a = list(map(int, input().split()))
    for i in a:
        assert(i<=1000000),"a[i]" 
    blocksize = int(n**0.5)
    a = a+[0]*(blocksize-n%blocksize)
    
    blockgcd = []
    prevgcd=a[0]
    j = 0
    #print(a, blocksize)
    for i in range( 1, len(a)):
        
        if i%blocksize==0:
            blockgcd.append(prevgcd)
            prevgcd=0
        prevgcd=gcd(prevgcd, a[i])
    blockgcd.append(prevgcd)
    #print(blockgcd)
    
    for query in range(q):
        #print('quer', blockgcd)
        qi = input().split()
        if len(qi)==4:
            # update
            
            l = int(qi[1])
            assert(0<=l and l<n),"l"
            r = int(qi[2])
            assert(0<=r and r<n),"r"
            assert(l<=r),"l<=r"
            mf = int(qi[3])
            fb = l//blocksize
            lb = r//blocksize
            
            gfb = gcdblock(fb, blocksize, a)
            glb = gcdblock(lb, blocksize, a)
            #print(l, r, blockgcd[fb], blockgcd[lb], gfb, glb, fb, lb, a)
            if lb!=fb:
                
                if gfb < blockgcd[fb]:
                    #print('g')
                    mft = blockgcd[fb]//gfb
                    for i in range(fb*blocksize, (fb+1)*blocksize):
                        a[i]*=mft
                        assert(a[i]<1000000000000000000),"a[i]*m"
                if glb < blockgcd[lb]:
                    #print('h')
                    mft = blockgcd[lb]//glb
                    for i in range( (lb)*blocksize, (lb+1)*blocksize):
                        a[i]*=mft
                        assert(a[i]<1000000000000000000),"a[i]*m"
                for i in range(fb+1, lb):
                    blockgcd[i]*=mf
                for i in range(l, (fb+1)*blocksize):
                    a[i]*=mf
                    assert(a[i]<1000000000000000000),"a[i]*m"
                g = 0
                for i in range(fb*blocksize, (fb+1)*blocksize):
                    g = gcd(g, a[i])
                blockgcd[fb]=g
                
                for i in range(lb*blocksize, r+1):
                    a[i]*=mf
                    assert(a[i]<1000000000000000000),"a[i]*m"
                g = 0
                for i in range(lb*blocksize, (lb+1)*blocksize):
                    g = gcd(g, a[i])
                blockgcd[lb]=g
            else:
                if gfb < blockgcd[fb]:
                    #print('g')
                    mft = blockgcd[fb]//gfb
                    for i in range(l, (fb+1)*blocksize):
                        a[i]*=mft
                for i in range(l, r+1):
                    a[i]*=mf
                    assert(a[i]<1000000000000000000),"a[i]*m"
                g = 0
                for i in range(fb*blocksize, (fb+1)*blocksize):
                    g = gcd(g, a[i])
                blockgcd[fb]=g
                
                    
        else:
            
            l = int(qi[1])
            r = int(qi[2])
            
            fb = l//blocksize
            lb = r//blocksize
            #print('a:', a[l:r+1], fb, lb)
            gfb = gcdblock(fb, blocksize, a)
            glb = gcdblock(lb, blocksize, a)
            #print(l, r, blockgcd[fb], blockgcd[lb], gfb, glb, fb, lb)
            if lb!=fb:
                if gfb < blockgcd[fb]:
                    #print('g')
                    mft = blockgcd[fb]//gfb
                    for i in range(fb*blocksize, (fb+1)*blocksize):
                        a[i]*=mft
                        assert(a[i]<1000000000000000000),"a[i]*m"
                if glb < blockgcd[lb]:
                    #print('hh')
                    mft = blockgcd[lb]//glb
                    for i in range( (lb)*blocksize, (lb+1)*blocksize):
                        a[i]*=mft
                        assert(a[i]<1000000000000000000),"a[i]*m"
                #print('a:', a[l:r+1], fb, lb)
                g = 0
                for i in range(l, (fb+1)*blocksize):
                    g=gcd(g, a[i])
                for i in range(fb+1, lb):
                    g=gcd(g, blockgcd[i])
                for i in range((lb)*blocksize, r+1):
                    g=gcd(g, a[i])
            else:
                if gfb < blockgcd[fb]:
                    #print('g')
                    mft = blockgcd[fb]//gfb
                    for i in range(fb*blocksize, (fb+1)*blocksize):
                        a[i]*=mft
                        assert(a[i]<1000000000000000000),"a[i]*m"
                g = 0
                for i in range(l, r+1):
                    g=gcd(g, a[i])

            print(g)
