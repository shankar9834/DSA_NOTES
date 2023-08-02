
//method 1
/*  
   O(n) time complexity
   
  start bfs from any node(u) and find depth of all the other nodes ,after that choose the node with maximum depth(node v)
  and then start the bfs from node v and find depth of all the other nodes . the maximum depth from v is the diameter of the tree 

*/

// method 2 
/*
 using dynamic programming
*/




#include<bits/stdc++.h>
using namespace std;

int lev[200005];
int vis[200005];


void bfs(int node,unordered_map<int,vector<int>>&tree)
{
    queue<int>q;
    q.push(node);
    vis[node]=1;
    lev[node]=0;

    while(!q.empty())
    {
        int sz=q.size();
        while(sz--)
        {
            int tp=q.front();
            q.pop();

            for(auto child:tree[tp])
            {
                if(!vis[child])
                {
                    q.push(child);
                    lev[child]=lev[tp]+1;
                    vis[child]=1;
                }
            }
        }
    }
}

void method1()
{
       int n;
   cin>>n;
   int edges=n-1;
   unordered_map<int,vector<int>>tree;
   while(edges--)
   {
       int x, y;
       cin>>x>>y;
       tree[x].push_back(y);
       tree[y].push_back(x);
   }
   
   bfs(1,tree);
   int mx=INT_MIN;
   int mx_node=-1;

   for(int i=1;i<=n;i++)
   {
    if(mx<lev[i])
    {
        mx=lev[i];
        mx_node=i;
    }
   
   } 
   


   memset(vis,0,sizeof(vis));
   memset(lev,0,sizeof(lev));

   bfs(mx_node,tree);
   mx=INT_MIN;

   for(int i=1;i<=n;i++)
   {
    if(mx<lev[i])
    {
        mx=lev[i];
        mx_node=i;
    }
   }

   cout<<mx<<endl;
}

int main()
{
   method1();  

}