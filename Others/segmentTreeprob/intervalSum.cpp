#include <bits/stdc++.h>
using namespace std;

int st[1000];
int arr[7]={1,2,3,4,5,6,7};

void buildTree(int si,int s,int e)
{
   if(s==e)
   {
      st[si]=arr[s];
      return ;
   }

   int mid=(s+e)/2;

   buildTree(2*si+1,s,mid);
   buildTree(2*si+2,mid+1,e);
   
   st[si]=st[2*si+1]+st[2*si+2];
   return ;

}


void updateTree(int si,int s,int e,int ui,int val)
{
        if(s==e)
        {
            st[si]=val;
            return ;
        }

        int mid=(s+e)/2;

        if(mid<=ui)
        {
            updateTree(2*si+1,s,mid,ui,val);
        }
        else{
         updateTree(2*si+2,mid+1,e,ui,val);
        }

         st[si]=st[2*si+1]+st[2*si+2];
}


int queryTree(int si,int s,int e,int qs,int qe)
{
        if(qe<s||qs>e) return 0;
        
        if(qs<=s&&qe>=e) return st[si];
        
        int mid=(s+e)/2;
        
       int val1= queryTree(2*si+1,s,mid,qs,qe);
       int val2= queryTree(2*si+2,mid+1,e,qs,qe);

       return val1+val2;

}

int main()
{
      buildTree(0,0,6);

      cout<<queryTree(0,0,6,0,6)<<endl;
      cout<<queryTree(0,0,6,2,5)<<endl;

}