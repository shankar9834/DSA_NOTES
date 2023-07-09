#include<bits/stdc++.h>
using namespace std;

class heap{
    public:
    int arr[100];
    int size;

    heap()
    {
       arr[0]=-1;
       size=0;
    }

    void insert(int val)
    {
         size++;
         int index=size;
         arr[index]=val;
        
         while(index>1)
         {
             int parent=index/2; 
            if(arr[parent]<arr[index])
            {
               swap(arr[parent],arr[index]);
               index=parent;
            }
            else{
                return ;
            }
         }
    }

    void deleteFromHeap()
    {
        if(size==0)
        {
            cout<<"heap is empty, nothing to delete\n";
            return ;
        }

         arr[1]=arr[size];
         size--;
         int i=1;
         while(i<size)
         {
            int leftIndex=2*i;
            int rightIndex=2*i+1;

            if(leftIndex<=size&&arr[i]<arr[leftIndex])
            {
                if(rightIndex<=size&&arr[rightIndex]>arr[leftIndex])
                {
                    swap(arr[rightIndex],arr[i]);
                    i=rightIndex;
                }
                else{
                    swap(arr[leftIndex],arr[i]);
                    i=leftIndex;
                }
            } 
            else if(rightIndex<=size&&arr[rightIndex]>arr[i])
            {
                  swap(arr[i],arr[rightIndex]);
                  i=rightIndex;
            }
            else {
                return ;
                }
            
           

            
         }

    }

    void printHeap()
    {
         for(int i=1;i<=size;i++)
         {
            cout<<arr[i]<<" ";
         }
         cout<<endl;
    }

    

    
};

void heapify(int arr[],int n,int i)
{
    int largest=i;
    int left=2*i;
    int right=2*i+1;

    if(left<=n&&arr[left]>arr[largest])
    {
        largest=left;
    } 
    if(right<=n&&arr[right]>arr[largest])
    {
        largest=right;
    }

    if(largest!=i)
    {
        swap(arr[largest],arr[i]);

        heapify(arr,n,largest);
    }
    else return ;

}


void heapsort(int arr[],int n)
{
    int size=n;

    while(size>1)
    {
        //swaping last element with root element
        swap(arr[size],arr[1]);
        size--;
       
       // maintaining heap property
        heapify(arr,size,1);
    
    }

}

int main()
{
     heap h;
     h.insert(50);
     h.insert(55);
     h.insert(53);
     h.insert(52);
     h.insert(54);
    h.deleteFromHeap();
       h.printHeap();





   int arr[6]={-1,54,53,55,52,50};
    int n=5;
                        
                        /*  heap creation */

// starting loop from n/2 bcoz from (n/2+1,n) nodes are leaf nodes ,and they dont have left,right child 
//  so they are already in heap 
      for(int i=n/2;i>0;i--)
      {
        //heapify fun makes sure that element at index i should be placed at correct position in heap
       // from index i to n ,heapify function makes heap
        
        heapify(arr,n,i);
      }
    for(int i=1;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;


    /*heapsort*/

    heapsort(arr,n);
     for(int i=1;i<=n;i++)
    {
        cout<<arr[i]<<" ";          
    }
    cout<<endl;

  
  
}