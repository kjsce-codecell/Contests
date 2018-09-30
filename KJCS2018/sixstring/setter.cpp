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
#define inf LONG_LONG_MAX
#define F first
#define S second
#define MOD 1000000007
#define all(a) a.begin(),a.end()
void solve()
{
	string s;
	cin>>s;
	ll a=s.size(),sm=0;
	ll mod[3]={0};
	ll presum=0;
	for(ll i=0;i<a;i++)
	{
		if(s[i]=='6' || s[i]=='1')
		{
			sm+=10;
			mod[0]=0;
			mod[1]=0;
			mod[2]=0;
			presum=0;
		}
		else
		{
			presum+=int(s[i]-'0');
			mod[(presum%3)]++;

			if(mod[0]==1 || mod[1]==2 || mod[2]==2)
			{
				if(!((s[i]-'0')%2))
				{
					sm+=5;
					mod[0]=0;
					mod[1]=0;
					mod[2]=0;
					presum=0;
				}
				else
				mod[(presum%3)]--;
			}
		}
	}
	cout<<sm<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll t=1;
    cin>>t;
	while(t--)
	solve();
}