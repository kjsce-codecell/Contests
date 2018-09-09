#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    ll t;
    cin>>t;
    assert(t>0 && t<=5);
    while(t--)
    {
        ll a,b,c;
        c=(pow(10,5));
        cin>>a;
        assert(a>=1 && a<=100);
        string s;
        vector< pair<ll,string> > sorter(a);
        for(ll i=0;i<a;i++)
        {
            cin>>s;
            b=s.size();
            //cout<<b<<" "<<c<<"\n";
            assert(b>=1 && b<=c);
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
