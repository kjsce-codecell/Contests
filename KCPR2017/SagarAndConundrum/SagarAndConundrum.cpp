#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<map>
#include<cstring>
#include<set>
#include<ctime>  
using namespace std;
#define uii long long int
#define M(a,b) (a>b ? a : b)
#define m(a,b) (a>b ? b : a)
#define it(a)  ::iterator a
#define slld(a) uii a;scanf("%lld",&a)
#define ss(a) scanf("%s",a)
#define plld(a) printf("%lld",a)
#define MAX 10000
#define MOD 1000000007
#define powOf2(a) !(a&a-1)
#define mod(a) (a>0 ? a : (-1*a))
#define tc(a) uii a; for(scanf("%lld",&a);a--;)
#define swap(a,b) a = a^b; b = a^b;a = a^b;
 
uii profit[2000][2000],dp[2000][2000];
 
int main(){
    
    tc(T){
 
        slld(N);
        slld(M);
        //uii profit[N][M];
        for(uii i = 0;i<N;i++){
            for(uii j = 0;j<M;j++){
                cin>>profit[i][j];
            }
        }
        uii sum = 0;
        //uii dp[N][M];
        for(uii i =0;i<N;i++){
            for(uii j=0;j<M;j++){
                if(i==0 && j==0)  dp[i][j] = profit[i][j];
                else if(i-1 < 0)  dp[i][j] = dp[i][j-1] + profit[i][j];
                else if(j-1 < 0)  dp[i][j] = dp[i-1][j] + profit[i][j];
                
                else  dp[i][j] = max(dp[i-1][j],dp[i][j-1]) + profit[i][j];
                
            }
        }
        cout<<dp[N-1][M-1]<<endl;
    }
 
	return 0;
}
 
                
 