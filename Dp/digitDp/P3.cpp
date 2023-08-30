//cses problem -- https://cses.fi/problemset/task/2220

#include <bits/stdc++.h>

using namespace std;

#define ll long long
 

 
ll dp[20][11][2];
//string occ="";
ll rec(int index, int prev, bool tight, string s)
{  // cout<<index<<endl;
    if(index>=s.length()){
       // cout<<"shankar\n";
        //cout<<occ<<endl;
        return 1;
    }
 
    if(dp[index][prev+1][tight]!=-1) return dp[index][prev+1][tight];
     
    int ub = tight ? s[index] - '0' : 9;
    int lb = 0;
     
    ll result=0;
    if (prev==-1)
    {
        ll count=0;
        for(int i=lb;i<=ub;i++)
        {
          //   occ.push_back((i+'0'));
             if(i==0&&prev==-1)
             {
               count+=rec(index+1,prev,false,s);
             }else{
                count+=rec(index+1,i,tight&(ub==i),s);
             }
            
          //  occ.pop_back();
        
        }
        result=count;
    }
    else
    {
        ll count = 0;
        for (int i = lb; i <= ub; i++)
        {
            if(i!=prev)
            {  
              //  occ.push_back((i+'0'));
                count += rec(index + 1, i, tight & (ub == i),s);
               // occ.pop_back();
            }
        }
        result=count;
    }
   
     return dp[index][prev+1][tight]=result;
}
void solve()
{
    string a, b;
    cin >>a>>b;
     //cout<<a<<b<<endl;
    int l=1;
    for(int i=1;i<a.length();i++)
    {
          if(a[i]==a[i-1])
          { 
            l=0;
            break;
 
          }
    }
 
   //cout<<a.length()<<" "<<b.length()<<endl;
    memset(dp,-1,sizeof(dp));
   ll val1=rec(0,-1,true,a);
   //cout<<endl;
   memset(dp,-1,sizeof(dp));
   ll val2=rec(0,-1,true,b);
   //cout<<val2<<" "<<val1<<endl;
   cout<<val2-val1+l<<endl;
}
 
int main()
{
 
        solve();
 
}
 

