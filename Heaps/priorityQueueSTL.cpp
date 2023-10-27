#include<bits/stdc++.h>
using namespace std;


int main()
{

     priority_queue<int>maxHeap;  //max heap  --> root element will be maximum

     priority_queue<int,vector<int>,greater<int>>minHeap;  //min heap  --> root element will be minimum



     maxHeap.push(17);
     maxHeap.push(10);

     minHeap.push(17);
     minHeap.push(10);



     cout<<"top element in maxHeap is "<<maxHeap.top()<<endl;

     cout<<"top element in minHeap is "<<minHeap.top()<<endl;

}