// 23 march 2023
// Author -- shankar wangwad

#include<bits/stdc++.h>
using namespace std;

// for storing segment tree
vector<int>sT=vector<int>(10005);

// building segment tree to get min element in range

void build(int segIndex,int start,int end,vector<int>&arr)
{

            if(start==end)
            {
               sT[segIndex]=arr[start];
               return ;
            }

            int mid=(start+end)/2;

            build(2*segIndex+1,start,mid,arr);
            build(2*segIndex+2,mid+1,end,arr);

            sT[segIndex]=min(sT[2*segIndex+1],sT[2*segIndex+2]); 

}

int query(int segIndex,int start,int end,int queryStart,int queryEnd,vector<int>&arr)
{
             
             // if query start and query end both lie outside the array range of original array (arr) 
             if(start>queryEnd||queryStart>end) return INT_MAX;

            // current range is inside the query range
             if(start>=queryStart&&end<=queryEnd) return sT[segIndex];
             
             int mid=(start+end)/2;
             
             int left=query(2*segIndex+1,start,mid,queryStart,queryEnd,arr);
             int right=query(2*segIndex+2,mid+1,end,queryStart,queryEnd,arr);

             return min(left,right);

             
}

void updatePoint(int segIndex,int start,int end,int updateIndex,vector<int>&arr)
{
     
     if(start==end)
     {
        sT[segIndex]=arr[start];
        return ;
     }
       
       int mid=(start+end)/2;
       if(updateIndex<=mid)
       {
          updatePoint(2*segIndex+1,start,mid,updateIndex,arr);
       }
       else{
        updatePoint(2*segIndex+2,mid+1,end,updateIndex,arr);
       }

       sT[segIndex]=min(sT[2*segIndex+1],sT[2*segIndex+2]);
}


int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);

    for(int i=0;i<n;i++)cin>>arr[i];

    build(0,0,n-1,arr);
    

        

        cout<<"update index : ";
        int index;
        cin>>index;
        cout<<"enter value: ";
        int value;
        cin>>value;

         int x,y;
        cin>>x>>y;
       cout<<"before updating minimum value in range "<<x<<" and "<<y<<" is "<<query(0,0,n-1,x,y,arr)<<endl;
        arr[index]=value;
        updatePoint(0,0,n-1,index,arr);

        cout<<"after updating minimum value in range "<<x<<" and "<<y<<" is "<<query(0,0,n-1,x,y,arr)<<endl;

    
    

}