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
  ll t;
  cin>>t;
  while(t--)
  {
    ll x,m,n,i,j,k,count=0,rem=0,div=0,remainder=0;
    cin>>x>>m;
    string s,fin="";
    vector<pair<string,ll> > v;
    set<pair<ll,ll> > st;
    ll start = 0;
    for(i=0;i<x;i++)
    {
      cin>>s;
      start+=s.size()+1;
      if(start>m+1)
      {
        start-=(s.size()+1);
        start--;
        rem = m - start;
        //cout<<rem<<endl;
        if(v.size()>1)
        {
          div = rem/(v.size()-1);
          remainder = rem%(v.size()-1);
        }
        else
        {
          div = 0;
          remainder = 0;
        }
        //cout<<div<<remainder<<endl;
        for(j=0;j<div;j++)
        {
          for(k=0;k<v.size()-1;k++)
          {
            v[k].first+=" ";
          }
        } 
        for(j=0;j<v.size()-1;j++)
        {
          st.insert(make_pair(-(v[j].second+v[j+1].second),j));
        }
        if(!st.empty())
        {
            auto it = st.begin();
            for(j=0;j<remainder;j++)
            {
                v[it->second].first+=" ";
                it++; 
            }
        }
        for(j=0;j<v.size();j++)
        {
            if(j == v.size()-1)
                cout<<v[j].first.substr(0,v[j].first.size()-1);
            else
                cout<<v[j].first;
        }
        cout<<endl;
        start = s.size()+1;
        st.clear();
        v.clear();
        v.push_back(make_pair(s+" ",s.size()));
      }
      else
      {
        v.push_back(make_pair(s+" ",s.size()));
      }
    }
    start--;
    rem = m - start;
    if(v.size()>1)
    {
      div = rem/(v.size()-1);
      remainder = rem%(v.size()-1);
    }
    else
    {
      div = 0;
      remainder = 0;
    }
    for(j=0;j<div;j++)
    {
      for(k=0;k<v.size()-1;k++)
      {
        v[k].first+=" ";
      }
    } 
    for(j=0;j<v.size()-1;j++)
    {
        st.insert(make_pair(-(v[j].second+v[j+1].second),j));
    }
    if(!st.empty())
    {
        auto it = st.begin();
        for(j=0;j<remainder;j++)
        {
            v[it->second].first+=" ";
            it++; 
        }
    }
    for(j=0;j<v.size();j++)
    {
        if(j == v.size()-1)
            cout<<v[j].first.substr(0,v[j].first.size()-1);
        else
            cout<<v[j].first;
    }
    cout<<endl;
  }
  return 0;
}