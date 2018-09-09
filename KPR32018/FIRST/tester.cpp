#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<utility>
#include<queue>
#include<numeric>
#include<ctime>
#include<climits>
#include<cassert>
using namespace std;
#define inp(a) scanf("%lld",&a)
#define fi(i,a,b) for(i=a;i<b;i++)
#define fin(i,a,b) for(i=a;i>=b;i--)
#define ll long long
#define N 100000
#define m(a,b) (a>b? b : a)
#define M(a,b) (a>b? a : b)

int main(){
    ll t,n;
    inp(t);
    while(t--)
    {
        inp(n);
        if(n%2==0)
        {
            printf("%lld\n",n/2);
        }else{
            ll sum=-((n+1)/2);
            printf("%lld\n",sum);
        }


    }
    
}