// 6 feb 2024  

#include<bits/stdc++.h>
using namespace std;

int pivot(int arr[],int low,int high)
{
  
     int pivot_item=arr[low];
     int left=low;
     int right=high;

     while(left<right)
     {
           while(arr[left]<=pivot_item)
           {
             left++;
           }
           while(arr[right]>pivot_item)
           {
                 right--;
           }
           if(left<right)
           {
             swap(arr[left],arr[right]);
           }
     }
     int temp=arr[low];
     arr[low]=arr[right];
     arr[right]=temp;
     return right;
}
void quicksort(int arr[],int low,int high)
{
    if(low<high)
    {
      int pivots=pivot( arr, low, high);
      if(!pivots) return ;
      quicksort(arr,low,pivots-1);
      quicksort(arr,pivots+1,high);

    }
}


int main()
{
  int arr[]={7,5,9,4,3,8};
    
    
    cout<<"\nbefore invoking quicksort\n";
    for(int i=0;i<=5;i++)
    {
      cout<<arr[i]<<" ";
    }

    quicksort(arr,0,5);
    
    cout<<"\nafter invoking quicksort\n";
    for(int i=0;i<=5;i++)
    {
      cout<<arr[i]<<" ";
    }
    cout<<endl;
   
}