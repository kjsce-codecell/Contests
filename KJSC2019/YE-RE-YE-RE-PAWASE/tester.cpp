// redundancy at it's best ;
#include "bits/stdc++.h"
using namespace std ;

#define MOD 1e9 + 7
#define debug {cerr<<"\nWorks fine till line : "<<__LINE__<<"\n";}
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ull unsigned long long int 
#define ll long long int 


int main(){
	ll t , i ,j  ;
	scanf(" %lli",&t);
	while(t--){
		ll n, q, tmp;
		scanf(" %lli %lli",&n,&q);

		vector<ll> rainfall(n,0);
		for(i = 0;i < n; i++){
			scanf(" %lli",&tmp);
			if(i){
				rainfall[i] = rainfall[i-1] + tmp;
			}
			else{
				rainfall[i] = tmp;
			}
		}

		vector <ll>::iterator it;
		while(q--){
			// BS
			ll capacity;
			scanf(" %lli",&capacity);
			ll last_day = 0, count = 0, need_arranged = capacity;
			if ((rainfall[n-1] >= capacity)){
				while(need_arranged < rainfall[n-1] ){

					it = upper_bound(rainfall.begin(),rainfall.end(),need_arranged);
					ll current_day = it-rainfall.begin() - 1; 
					need_arranged = capacity + rainfall[current_day];
					count++;
					last_day = current_day+1;
				}
			}

			printf("%lli %lli\n",count,last_day);
		}
	}
	return 0;
}
