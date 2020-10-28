//Author : Nishit Patel
#include <bits/stdc++.h>
#include <chrono> 
using namespace std;
typedef long double ld;
typedef double db;
typedef long long ll;
using namespace std::chrono; 
#define pb push_back
#define FAST cin.sync_with_stdio(0); cin.tie(0);
#define rep(i, n)      for(int i = 0; i < (n); ++i)
#define arep(i, a, n)  for(int i = a; i <= (n); ++i)
#define drep(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x)     for(auto& a : x)
#define all(x) x.begin(), x.end()
typedef pair<int, int> pii;
typedef vector<ll> vl;
typedef map<ll, ll> ml;
typedef unordered_map<ll, ll> hash;
#define deb_1(A)                     {cerr << "[" << #A << "] : " << A << endl;}
#define deb_2(A,B)                   {cerr << "[" << #A << "] : " << A << endl<< "[" << #B << "] : " << B << endl;}
#define deb_3(A,B,C)                 {cerr << "[" << #A << "] : " << A << endl<< "[" << #B << "] : " << B << endl\
									   << "[" << #C << "] : " << C << endl;}
#define deb_4(A,B,C,D)               {cerr << "[" << #A << "] : " << A << endl<< "[" << #B << "] : " << B << endl\
									   << "[" << #C << "] : " << C << endl<< "[" << #D << "] : " << D << endl;}
#define deb_X(x,A,B,C,D,FUNC, ...)  FUNC  
#define deb(...)                    deb_X(,##__VA_ARGS__,\
                                          deb_4(__VA_ARGS__),\
                                          deb_3(__VA_ARGS__),\
                                          deb_2(__VA_ARGS__),\
                                          deb_1(__VA_ARGS__),\
                                         )
              
ll min3(ll i, ll j, ll k)
{
  return std::min(i, std::min(j, k));
}          

ll dp[100005][3];                 

long long solve(ll v[], ll n,ll start,ll size)
{
	long long ans = 0;
	if(start == 0)
	{
		if(n+2 >= size-1)
		{
			return v[n];
		}
		if(dp[n][start]!=-1)return dp[n][start];
		ans = min3(solve(v,n+1,start,size),solve(v,n+2,start,size),solve(v,n+3,start,size));
		ans += v[n];
		dp[n][start] = ans;
		return ans;
	}
	else if(start == 1)
	{
		if(n == size)
		{
			return 0;
		}
		if(n+2 >= size)
		{
			return v[n];
		}
		if(n+3==size){ 
			ans = min(solve(v,n+1,start,size),solve(v,n+2,start,size));
			ans += v[n];
			dp[n][start] = ans;
			return ans;
		}
		if(dp[n][start]!=-1)return dp[n][start];
		ans = min3(solve(v,n+1,start,size),solve(v,n+2,start,size),solve(v,n+3,start,size));
		ans += v[n];
		dp[n][start] = ans;
		return ans;
	}
	else if(start == 2)
	{
		if(n==size+1)return 0;
		if(dp[n][start]!=-1)return dp[n][start];
		if(n+2>=size+1)return v[n];
		if(n+3==size+1){ 
			ans = min(solve(v,n+1,start,size),solve(v,n+2,start,size));
			ans += v[n];
			dp[n][start] = ans;
			return ans;
		}
		ans = min3(solve(v,n+1,start,size),solve(v,n+2,start,size),solve(v,n+3,start,size));
		ans += v[n];
		dp[n][start] = ans;
		return ans;
	}
	return 0;
}

int main(){
	FAST;
	auto start = high_resolution_clock::now(); 
	ll t;
	cin>>t;
	while(t--)
	{
		memset(dp,-1,sizeof(dp));
		ll n;
		cin>>n;
		ll v[n+1];
		v[n] = INT_MAX;
		for(int i=0;i<n;i++)
		{
			cin>>v[i];
		}
		if(n==0) cout << 0 <<endl;
		else if(n==1) cout << v[0] <<endl;
		else if(n == 2) cout<<min(v[0],v[1])<<endl;
		else cout<<min3(solve(v,0,0,n),solve(v,1,1,n),solve(v,2,2,n))<<endl;
	}
	auto stop = high_resolution_clock::now(); 
	auto duration = duration_cast<microseconds>(stop - start); 
    //cout << "Time taken by program: "
         //<< duration.count() << " microseconds" << endl; 
}
