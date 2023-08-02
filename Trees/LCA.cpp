#include<bits/stdc++.h>
using namespace std;

int lev[200007];
int vis[200007];
int up[200007][20];

void BinaryLifting(int node,int par,unordered_map<int,vector<int>>&tree)
{
       up[node][0]=par;
       for(int i=1;i<20;i++)
       {
        if(up[node][i-1]!=-1)
        {
             up[node][i]=up[up[node][i-1]][i-1];
        }else{
            up[node][i]=-1;
        }
        
       }
       vis[node]=1;


       for(auto child:tree[node])
       {
         if(!vis[child])
         {
            BinaryLifting(child,node,tree);
         }
       }
       return ;
}


int lifting(int node,int k)
{
    int curr=node;
      for(int i=19;i>=0;i--)
      {
        if(k&(1<<i))
        {
            curr=up[curr][i];
            if(curr==-1)return curr;
        }
      }
      return curr;
}


int LCA(int node1,int node2)
{
    if(lev[node1]<lev[node2]) return LCA(node2,node1);

    int diff=lev[node1]-lev[node2];
   
    int lf=lifting(node1,diff);
    
    if(lf==node2)return node2;

    for(int i=19;i>=0;i--)
    {
        if(up[lf][i]!=up[node2][i])
        {
            lf=up[lf][i];
            node2=up[node2][i];
        }
    }   
    
    return lifting(lf,1);
  
}



void calculateDepth(int node,unordered_map<int,vector<int>>&tree)
{
    queue<int>q;
    q.push(node);
    lev[node]=1;
    vis[node]=1;
    while(!q.empty())
    {
        int sz=q.size();
        while(sz--)
        {
            auto tp=q.front();
            q.pop();
            for(auto child:tree[tp])
            {
                if(!vis[child])
                {
                    lev[child]=lev[tp]+1;
                    q.push(child);
                    vis[child]=1;
                }
            } 
        }
    }
    return ;

}

int main()
{
   unordered_map<int,vector<int>>tree;
   int n,q;
   cin>>n>>q;

   for(int i=2;i<=n;i++)
   {
      int x;
      cin>>x;
      tree[x].push_back(i);
      tree[i].push_back(x);
   }
  calculateDepth(1,tree);
  memset(vis,0,sizeof(vis)); 
  /* for(int i=1;i<=n;i++)cout<<lev[i]<<" ";
  cout<<endl; */

  BinaryLifting(1,-1,tree);

   

   while(q--)
   {
    int l,r;
    cin>>l>>r;
    cout<<LCA(l,r)<<endl;
   }

}