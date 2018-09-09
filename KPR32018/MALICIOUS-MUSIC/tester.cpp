#include "bits/stdc++.h"
using namespace std;

int main()
{
  long long t;
  cin>>t;
  while(t--)
  {
    //cout<<endl<<t<<endl;
    long long n,m,i,j,count=0;
    cin>>n>>m;
    long long a[n],b[m],temp,x,f=0;
    string s ="",s2="";
    string str;
    char ch;
    for(i=0;i<n;i++)
    {
      cin>>a[i];
      cin>>ch;
      s+=ch;
    }
    for(i=0;i<m;i++)
    {
      cin>>b[i];
      cin>>ch;
      s2 += ch;
    }
    //cout<<endl<<s<<endl<<s2<<endl;
    for(i=0;i<=n-m;i++)
    {
      f=0;
      for(j=i;j<i+m;j++)
      {
        if(s[j]==s2[j-i] && a[j]%b[j-i] == 0 && f==0)
        {
          f=1;
          temp = a[j]/b[j-i];
          //cout<<temp<<endl;
          continue;
        }
        else if(s[j]==s2[j-i] && a[j]%b[j-i]==0 && a[j]/b[j-i]==temp)
        {
          continue;
        }
        else       
          break;
      }
      if(j==i+m)
      {
        count++;
      }
    }
    cout<<count<<endl;
  }
  return 0;
}
