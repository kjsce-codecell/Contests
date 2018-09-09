#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll a,b,c;
        c=(pow(10,5));
        cin>>a;
        string s;
        vector< pair<ll,string> > sorter(a);
        for(ll i=0;i<a;i++)
        {
            cin>>s;
            b=s.size();
            sorter[i]=make_pair(b,s);
        }
        sort(sorter.begin(),sorter.end());
        for(ll i=a-1;i>=0;i--)
        {
            cout<<sorter[i].second<<" ";
        }
        cout<<"\n";
    }
}
