// using gap method   
//yt pepcoding - https://www.youtube.com/watch?v=WpYHNHofwjc 
//11 Oct 2023

// tc O(n*n)  there is other algorithm called manachers algortihm for longest palindromic substring works in O(n) 
// sc O(n*n)
#include<bits/stdc++.h>
using namespace std;

 string longestPalindrome(string s) {
        
        string s1=s;
      // reverse(s.begin(),s.end());
        string s2=s;
        int len=s.length();
       
       bool dp[s.length()+1][s.length()+1];

       memset(dp,0,sizeof(dp));
      int ans=INT_MIN;
      int st=0;
      int ed=0;
       for(int g=0;g<s.length();g++)
       {
           for(int i=0,j=g;j<s.length();i++,j++)
           {
               if(g==0)
               {
                   dp[i][j]=true;
               }
               else if(g==1)
               {
                   dp[i][j]=(s1[i]==s2[j]);
               }
               else{
                   dp[i][j]=(s1[i]==s2[j])&(dp[i+1][j-1]);
               }


               if(dp[i][j])
               {
                   if(ans<(j-i+1))
                   {
                        st=i;
                        ed=j;
                        ans=j-i+1;
                   }
               }
           }
       } 
    

       string res="";
       for(int i=st;i<=ed;i++)
       {
           res+=s[i];
       }
       return res;


    }


  int main(){

    }