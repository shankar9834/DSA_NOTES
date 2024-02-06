// 6 feb 2024

#include<bits/stdc++.h>
using namespace std;

void merge(int arr[],int temp[],int start,int mid,int end)
{
    int left_end=mid-1;

    int pos=start;
    int len=end-start+1;

    while(start<=left_end&&mid<=end)
    {
        if(arr[start]<=arr[mid])
        {
            temp[pos]=arr[start];
            pos++;
            start++;

        }
        else{
            temp[pos]=arr[mid];
            mid++;
            pos++;
        }
    }


    while(start<=left_end)
    {
        temp[pos]=arr[start];
        pos++;
        start++;
    }

    while(mid<=end)
    {
        temp[pos]=arr[mid];
        pos++;
        mid++;
    }

    for(int i=0;i<len;i++)
    {
        arr[end]=temp[end];
        end--;
    }

}
void mergesort(int arr[],int temp[],int start,int end)
{
       if(start<end)
       {
           int mid=(start+end)/2;
             mergesort(arr,temp,start,mid);
             mergesort(arr,temp,mid+1,end);
             merge(arr,temp,start,mid+1,end);

      }

}
int main()
{
    int arr[]={7,5,9,4,3};
    int temp[6];
      cout<<"before sorting the array is\n";
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    mergesort(arr,temp,0,4);
   
    cout<<"after sorting the array is\n";
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}