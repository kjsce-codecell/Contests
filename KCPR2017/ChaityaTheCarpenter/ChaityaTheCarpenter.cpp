#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<utility>
#include<numeric>
#define llu long long
#define N 100000
#define m(a,b) (a>b? b : a)
#define M(a,b) (a>b? a : b)
#define mod 1000000007
using namespace std;
vector< pair<llu,llu> > v(1000);
vector< pair<llu,llu> >::iterator it;
llu k;
void factors(llu d)
{
    k=0;
    for(llu i=1;i<=sqrt(d);i++)
    {
        if(d%i==0)
        {
            v[k]=(make_pair(i,d/i));
            k++;
        }
    }
}
void dickson(llu n)
{
    llu m=2,i,j,d,f,a,b,c,cn=0,max=0;
    while(m<n)
    {
        d=((m*m)/2);
        factors(d);
        llu f=0;
        for(i=0;i<k;i++)
        {
            c=(m+(v[i].first)+(v[i].second));
            //cout<<m<<" "<<c<<endl;
            if(c<=n)
            {
                a=m+(v[i].first);
                b=m+(v[i].second);
                max=M(max,(a+b+c));
                //cout<<a<<" "<<b<<" "<<c<<endl;
                //cn++;
            }
        }
        m+=2;
    }
    cout<<max<<endl;
}
 
int main()
{
    llu t,i,j,k,l,m,n;
    scanf("%lld",&t);
    while(t--)
    {
        cin>>n;
        dickson(n);
    }
    return 0;
}
 