#include<bits/stdc++.h>
using namespace std;


void sortInsert(stack<int>&stack,int num)
{
    if(stack.empty()||stack.top()<num)
    {
        stack.push(num);
        return ;
    }
    
    
    int n=stack.top();
    stack.pop();
    sortInsert(stack,num);
    stack.push(n);
    return;
}


void sortStack(stack<int> &stack)
{
        if(stack.empty())
        {
            return ;
        }
    
    int num=stack.top();
    stack.pop();
    
    sortStack(stack);
    
    sortInsert(stack,num);
    
}

int main()
{
    stack<int>st;
    st.push(5);
    st.push(3);
    st.push(7);
    sortStack(st);
}