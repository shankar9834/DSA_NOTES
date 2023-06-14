#include<bits/stdc++.h>
using namespace std;

class MinStack {
public:
    
    stack<int>st;
    stack<int>mini;
 int mx=INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        
        mx=min(mx,val);
        mini.push(mx);
        st.push(val);
        return ;
    }
    
    void pop() {
        
        if(!st.empty())
        {
            st.pop();
            mini.pop();
            if(!mini.empty())
            mx=mini.top();
            if(mini.empty())
            {
                mx=INT_MAX;
            }
        }
        
    }
    
    int top() {
        
        if(st.empty()) return -1;
        return st.top();
    }
    
    int getMin() {
        
        if(st.empty()) return -1;
        
        if(mini.empty()) return -1;
        return mini.top();
    }
};




int main()
{
    
}