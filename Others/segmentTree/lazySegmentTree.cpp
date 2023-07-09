#include<bits/stdc++.h>
using namespace std;

int mxN=5;
vector<int>sT=vector<int>(4*mxN,0);
vector<int>lazy=vector<int>(4*mxN,0);


void build(int si,int ss,int se,vector<int>&arr)
{
     if(ss==se)
     {
        sT[si]=arr[ss];
        return ;
     }

     int mid=(ss+se)/2;
     build(2*si+1,ss,mid,arr);
     build(2*si+2,mid+1,se,arr);

     sT[si]=sT[2*si+1]+sT[2*si+2];
}

int queryLazy(int si,int ss,int se,int qs,int qe)
{
       if(lazy[si]!=0)
       {
            int dx=lazy[si];
            lazy[si]=0;
            sT[si]+=dx*(se-ss+1);
            
            // ss != se  implies nodes are not leaf nodes
            if(ss!=se)
            {
                // update child lazies 
                lazy[2*si+1]+=dx;
                lazy[2*si+2]+=dx;

            }
       }
 
       if(ss>qe||qs>se) return 0;

       if(ss>=qs&&se<=qe) return sT[si];  

       int mid=(ss+se)/2;
       int left=queryLazy(2*si+1,ss,mid,qs,qe);
       int right=queryLazy(2*si+2,mid+1,se,qs,qe);

       return left+right;

}


void updateLazy(int si,int ss,int se,int qs,int qe,int val)
{
    if(lazy[si]!=0)
    {
        int dx=lazy[si];
        lazy[si]=0;

        sT[si]+=dx*(se-ss+1);
        
        if(ss!=se)
        {
            lazy[2*si+1]+=dx;
            lazy[2*si+2]+=dx;
        }
    }

    if(ss>qe||qs>se) return ;

    if(ss>=qs&&se<=qe)
    {
        int dx=(se-ss+1)*val;
        sT[si]+=dx;

        if(ss!=se)
        {
            lazy[2*si+1]+=val;
            lazy[2*si+2]+=val;
        }
        return ;
    }

    int mid=(ss+se)/2;
    updateLazy(2*si+1,ss,mid,qs,qe,val);
    updateLazy(2*si+2,mid+1,se,qs,qe,val);

    sT[si]=sT[2*si+1]+sT[2*si+2];
}

int main()
{
    // arr of size mxN
    vector<int>arr={2,3,7,6,1};
    build(0,0,arr.size()-1,arr);

  /*  while(true)
   {
    int l,r;
     cin>>l>>r;
     cout<<queryLazy(0,0,arr.size()-1,l,r)<<endl;
     if(l==-1)break;
   } */

   updateLazy(0,0,arr.size()-1,1,2,3);
   cout<<queryLazy(0,0,arr.size()-1,1,2)<<endl;

  
    
    
}