#include<bits/stdc++.h>
using namespace std;


    void insertAtBottom(stack<int>&st,int val)
    {
        if(st.empty())
        {
            st.push(val);
            return;
        }
        
        int num=st.top();
        st.pop();
        insertAtBottom(st,val);
        
        st.push(num);
        
    }

    void reverseStack(stack<int>&st)
    {
        if(st.empty()) return ;
        
        int num=st.top();
        st.pop();
        
        reverseStack(st);
        
        insertAtBottom(st,num);
        
        
    }

   /* vector<int> Reverse(stack<int> st){
        
        
        vector<int>ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }

*/

int main()
{
    stack<int>st;
    st.push(5);
    st.push(7);
    st.push(9);
    reverseStack(st);

    while(!st.empty())
    {
        cout<<st.top()<<endl;
        st.pop();
    }

}