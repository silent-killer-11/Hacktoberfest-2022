#include <bits/stdc++.h>
#include <stdio.h>
#include <time.h>
#include <limits.h>
#include <stdlib.h>



#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             LONG_LONG_MAX
#define ps(x,y)         fixed<<setprecision(y)<<x
#define endl            '\n'
#define mk(arr,n,type)  type *arr=new type[n]
#define w(x)            int x; cin >> x; while(x--)
#define f(i,x,y)        for(int i = x; i < y; i++)
#define g(i,x,y)        for(int i = x;i<=y;i++)



using namespace std;
const int n=3e5+5;


void c_p_p()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

}
/* ******* Your Functions Below ******** */









/* ******* Your Functions Above ******** */

int32_t main()
{
	c_p_p();
	#ifndef ONLINE_JUDGE
	// For getting input from input.txt file 
    // For getting input from input.txt file 
    freopen("input.exe", "r", stdin); 
  
    // Printing the Output to output.txt file 
    freopen("outpute.exe", "w", stdout); 
#endif
    int t;
    cin>>t;
  

    while(t--) 
{
   int n,i;
   cin>>n;
   string s;
   cin>>s;
   
   int flag=0;

   for(i=0;i<n;i++)
   {
    if(s[i]!=s[i+1] && i<=n-2)
    {
       
        flag=1;
        break;
    }
   }
   if(flag==1)
   {
    cout<<i+1<<" "<<i+2<<endl;
    }
    else
    {
        cout<<-1<<" "<<-1<<endl;
    }
  
}

   
 
   return 0;
        
    
 }
 // this is the naive approach

     