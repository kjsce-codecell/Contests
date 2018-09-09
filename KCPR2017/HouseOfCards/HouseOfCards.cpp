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
#define llu long long
#define N 100000
#define m(a,b) (a>b? b : a)
#define M(a,b) (a>b? a : b)
#define mod 1000000007
using namespace std;
 
int main()
{
    llu i,j,k,l,t,e,m,n;
    scanf("%lld",&t);
    while(t--)
    {
        cin>>n>>k;
        llu a[n];
        for(i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        llu h[n];
        h[0]=a[0]*3;
        for(i=1;i<n;i++)
            h[i]=(a[i]*3)+h[i-1];
        llu max=0,maxh=1;
        vector< pair<llu,llu> >::iterator it;
        vector< pair<llu,llu> >dp(n);
        for(i=0;i<n;i++)
        {
            if((a[i]*2)<=k)
                dp[i]=make_pair(1,a[i]*2);
            else
                dp[i]=make_pair(0,a[i]*2);
            e=a[i]*2;
            for(j=0;j<i;j++)
            {
                if((h[j]+e)<=k && dp[i].second<=k)
                {
                    dp[i].first=M(dp[i].first,(j+2));
                    maxh=M(maxh,dp[i].first);
                    dp[i].second=M(e+h[j],dp[i].second);
                }
            }
        }
        for(i=0;i<n;i++)
        {
            //cout<<dp[i].first<<" "<<dp[i].second<<endl;
            if(dp[i].first==maxh)
                max=M(max,dp[i].second);
        }
        cout<<max<<endl;
    }
    return 0;
} 