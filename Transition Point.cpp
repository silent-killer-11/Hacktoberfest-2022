#include <bits/stdc++.h>
using namespace std;
int main()
{int t;
cin>>t;
while(t>0)
{ int n,a[100000000],i;
  cin>>n;
  for(i=0;i<n;i++)
  {
    cin>>a[i];
  }
  if(a[n-1]==0)
  {
    cout<<"-1\n";
  }
  else
  {
    for(i=0;i<n;i++)
    {
      if(a[i]==1)
      {cout<<i<<"\n";
        break;
      }
    }
   //cout<<rbinsearch(a,0,n-1,1)<<"\n";
  }
  t--;
}
  return 0;
}
