#include<bits/stdc++.h>
 
#define ll long long
#define pl pair<l,l>
#define pll pair<ll,ll>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000007;
#define vll vector<ll>
#define vss vector<string>
 
using namespace std;
 
vector<string> findWords(vector<string>& words) {
    vector<string> v;
    for(auto w:words) {
        regex_match(w,regex("[QWERTYUIOPqwertyuiop]*|[ASDFGHJKLasdfghjkl]*|[ZXCVBNMzxcvbnm]*"))?(void)0:v.push_back(w);
    }
    return v;
}
 
int main() {
    ll t;
    scanf("%lld",&t);
    while(t--) {
        ll n;
        scanf("%lld",&n);
        vss v(n);
        for(ll i=0;i<n;i++) {
            string temp;
            cin>>temp;
            v[i]=temp;
        }
        vss ans = findWords(v);
        ll count = (ll)ans.size();
        printf("%lld\n",count);
        if(count==0) continue;
        for(string ans_string : ans) {
            cout<<ans_string<<" ";
        }
        printf("\n");
    }
    return 0;
}
 
 