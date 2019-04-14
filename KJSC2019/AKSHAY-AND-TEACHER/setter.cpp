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
    int t;
    cin>>t;
    while(t--)
    {
      ll n,i,j,flag = 0,maximum = -1000000000001;
      cin>>n;
      ll a[n];
      for(i=0;i<n;i++)
      {
        cin>>a[i];
        maximum = max(maximum,a[i]);
        if(a[i]>=0)
          flag = 1;
      }
      unordered_map<ll,pair<ll,ll> > maps;   //track of all subarrays with key as start index and value as end index and maximum sum 
      ll max_so_far = 0, max_ending_here = 0, minimum = 100000000001;
      ll start=0,s=0,end=0;
      if(flag == 0)
      {
        cout<<maximum<<endl;
        continue;
      }
      for(i=0;i<n;i++)
      {
        max_ending_here += a[i];
        if(max_ending_here < 0)
        {
          s = i+1;
          max_ending_here = 0;
        }
        else if(max_ending_here >= max_so_far)
        {
          start = s;
          end = i;
          max_so_far = max_ending_here;
          maps[s] = make_pair(end,max_so_far);
        }
      }
      for(auto it=maps.begin();it!=maps.end();it++)
      {
        //cout<<it->first<<" "<<(it->second).first<<" "<<(it->second).second<<endl;
        if( (it->second).second == max_so_far)
        {
          for(i=it->first;i<=(it->second).first;i++)
          {
            minimum = min(minimum,a[i]);
          }
        } 
      }
      if(minimum < 0)
        cout<<max_so_far - minimum<<endl;
      else  
        cout<<max_so_far<<endl;
    }
    return 0;
}
