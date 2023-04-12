// 12 April 2023
// Author -- shankar wangwad
//source link=https://cp-algorithms.com/data_structures/stack_queue_modification.html


#include<bits/stdc++.h>
using namespace std;

/*
We want to modify the stack data structure in such a way, that it possible to find the smallest element in the stack in  
$O(1)$  time, while maintaining the same asymptotic behavior for adding and removing elements from the stack. Quick reminder, on a stack we only add and remove elements on one end.

To do this, we will not only store the elements in the stack, but we will store them in pairs: the element itself and the minimum in the stack starting from this element and below.
*/


void addNewElement( stack<pair<int, int>>&st,int new_elem)
{
     int new_min = st.empty() ? new_elem : min(new_elem, st.top().second);
    st.push({new_elem, new_min});
}

void remove_element(stack<pair<int, int>>&st)
{
    int removed_element = st.top().first;
    st.pop();
}

int find_min_element(stack<pair<int,int>>&st)
{
    int minimum = st.top().second;
    return minimum;
}

int main()
{
    stack<pair<int, int>> st;

     
     vector<int>v={2,5,6,1,7,9};

     //adding new element
     for(auto el:v)
     {
         addNewElement(st,el);
     }
     


}