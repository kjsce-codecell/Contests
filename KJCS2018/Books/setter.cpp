#include<bits/stdc++.h>
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
#define getchar_unlocked getchar
#define F first
#define S second
#define MOD 1000000007
#define all(c) c.begin(),c.end()

ll gcd(ll x,ll y)
{
  if(y==0)
    return x;
  else
    return gcd(y,x%y);
}

void swap(ll *x,ll *y)
{
  ll temp = *x;
  *x = *y;
  *y = temp;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL); 
    ll t;
    cin>>t;
    while(t--)
    {
        ll sum=0,n,m,i,j,k,x,y;
        cin>>n>>m;
        ll pre[m+1] = {0};
        vector<ll> v;
        ll l[n],r[n];
        for(i=0;i<m;i++)
        {
            cin>>k;
            v.pb(k);
        }
        sort(v.begin(),v.end());
        for(i=1;i<=m;i++)
        {
            sum+=v[i-1];
            pre[i] = sum;
        }
        for(i=0;i<n;i++)
        {
            cin>>l[i];
        }
        for(i=0;i<n;i++)
        {
            cin>>r[i];
        }
        for(i=0;i<n;i++)
        {
            auto it = lower_bound(v.begin(),v.end(),l[i]);
            auto it2 = lower_bound(v.begin(),v.end(),r[i]);
            if(*it2 == r[i])
            {
                cout<<it2-it+1<<" "<<pre[it2-v.begin()+1]-pre[it-v.begin()]<<endl;
            }
            else
            {
                cout<<it2-it<<" "<<pre[it2-v.begin()]-pre[it-v.begin()]<<endl;
            }
        }
    }
    return 0;
}