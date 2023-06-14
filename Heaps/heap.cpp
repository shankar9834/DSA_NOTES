// implementation for max heap

#include<bits/stdc++.h>
using namespace std;

void insertInHeap(int index,vector<int>&arr)
{
    int el=arr[index];
    int i=index;
  
     while(index>0&&arr[index/2]<arr[index])
     {
             swap(arr[index/2],arr[index]);
             index=index/2;
     }
      
      cout<<"given vector is heap till index "<<i<<endl;
     return ;
}

void makeHeap(vector<int>&arr)
{
    for(int i=0;i<arr.size();i++)
    {
        insertInHeap(i,arr);
    }

    cout<<"entire vector is heap now\n"<<endl;
}

int deleteNodeFromHeap(vector<int>arr)
{
    
}

void printVector(vector<int>&arr)
{
    for(auto el:arr)
    {
        cout<<el<<" ";
    }
    cout<<endl;
}


int main()
{
    vector<int>arr={2,5,1,9,8,15,4};
     
     printVector(arr);
      makeHeap(arr);
     printVector(arr);

    
}