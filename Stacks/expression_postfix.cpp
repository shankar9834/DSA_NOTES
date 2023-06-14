#include<bits/stdc++.h>
using namespace std;



int prec(char a)
{
    if(a=='(') return 0;
    if(a=='-'||a=='+') return 1;
    else return 2;
}



void printPostfix(string s)
{
    stack<char>st;
    int len=s.length();
    for(int i=0;i<len;i++)
    {
        if(s[i]=='(')
        {
            st.push(s[i]);
        }
        else if(s[i]=='*'||s[i]=='/'||s[i]=='-'||s[i]=='+')
        {
            while(!st.empty()&&prec(st.top())>=prec(s[i]))
            {
               cout<<st.top();
               st.pop();
            }
            st.push(s[i]);
        }else if(s[i]==')')
        {
            while(!st.empty()&&st.top()!='(')
            {
                cout<<st.top();
                st.pop();
                
            }
            if(!st.empty()&&st.top()=='(') st.pop();

        }
        else{
            cout<<s[i];
        }


    }
  
    //cout<<st.size()<<endl;
    while(!st.empty())
    {
        cout<<st.top();
        st.pop();
    }
}


int main()
{
    string s="a*b-(c+d)+e";
    printPostfix(s);

}