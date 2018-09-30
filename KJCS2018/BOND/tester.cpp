#include "bits/stdc++.h"
#define ull unsigned long long int 
#define ll long long int 


int main(){
    ll t;
    scanf(" %lli",&t);
    assert(t>=1 && t <= 1e5) ;
    while(t--){ 
        ll n;
        scanf(" %lli",&n);
        assert(n >= 1 && n <= 1e17) ;
        int arr[7] = {'A','C','F','D','G','B','E'};
        printf("%c\n",arr[n%7]);
    }
    
    return 0 ;

}