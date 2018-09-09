#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<string>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

#define mp make_pair
#define pb push_back
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define inf LONG_LONG_MAX 
#define F first
#define S second
#define MOD 1000000007
#define all(a) a.begin(),a.end()

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,p,k,r,f=1,w;
        cin>>n>>p>>k;
        ll m[201]={0};
        if(n<p)
        	f=0;
        w=n/p;
        for(ll i=0;i<n;i++)
        {
            cin>>r;
            m[r]++;
        }
        r=0;
		if(f==1)
        {
            ll v=0;
			if(n%p==0 && p==k)
				w--;
            for(ll it=100;it<200;it++)
            {
                if(v==w-1)
                {
                    if((p+k-r)<m[it])
                    {
                        f=0;
                        break;
                    }
                    else
                    r+=m[it];
                }
                else
                {
                    if((p-r)<m[it])
                    {
                        f=0;
                        break;
                    }
                    else
                    {
                        r+=m[it];
                        if(r==p)
                        {
                            r=0;
                            v++;
                        }
                    }
                }
            }
        }
        if(f==0)
        cout<<"NO\n";
        else
        cout<<"YES\n";
    }
}