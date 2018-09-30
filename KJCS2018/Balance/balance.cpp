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
        ll i,j,k,x,y,n,m;
        cin>>x>>y>>n>>m;
        k = (x*y)/gcd(x,y);
        if(k/x>n || k/y>m)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    return 0;
}