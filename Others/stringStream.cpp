// 9 june 2023
// Author -- shankar wangwad


#include <iostream>
#include<bits/stdc++.h>

using namespace std;


int main() 
{
   string s;
   cin>>s;

   stringstream ss(s);
   string word;
   stack<string>st;
   
   while(ss>>word)
   {
        st.push(word);

   }

   while(!st.empty())
   {
       cout<<st.top()<<" ";
       st.pop();
   }


}