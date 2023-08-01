// 1 aug 2023
//example problem - https://cses.fi/problemset/task/1687

#include<bits/stdc++.h>
using namespace std;


void BinaryLifting(int node,int par,unordered_map<int,vector<int>>&tree,vector<vector<int>>&up)
{
     up[node][0]=par;
     for(int i=1;i<=19;i++)
     {     
           if(up[node][i-1]!=-1)
           {
             up[node][i]=up[up[node][i-1]][i-1];
           } else{
             up[node][i]=-1;
           }
           
     }

     for(auto child:tree[node])
     {
        if(child!=par)
        {
            BinaryLifting(child,node,tree,up);
        }
     }

     return ;
     

}

int answerQuery(int node,int k,unordered_map<int,vector<int>>&tree,vector<vector<int>>&up)
{
    int curr=node;

    for(int i=19;i>=0;i--)
    {
         if(k&(1<<i))
         {
            curr=up[curr][i];
            if(curr==-1)return -1;
         }
    } 
    return curr;

}

int main()
{
    int n,q;
    cin>>n>>q;
    vector<vector<int>>up=vector<vector<int>>(n+1,vector<int>(20));
    unordered_map<int,vector<int>>tree;

    for(int i=2;i<=n;i++)
    {
        int x;
        cin>>x;
        tree[i].push_back(x);
        tree[x].push_back(i);
    }
     
   BinaryLifting(1,-1,tree,up);

    while(q--)
    { // cout<<"query "<<q<<endl;
        int node,k;
        cin>>node>>k;
       cout<<answerQuery(node,k,tree,up)<<endl;

    }
  
}
