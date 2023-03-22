//22 march 2023
//Author -- shankar wangwad


#include<bits/stdc++.h>
using namespace std;

   int timer=0;
    
  vector<vector<int>>bridges;

  void dfs(int node,int parent,vector<int>&vis,vector<int>adj[],int low[],int tin[])
  {
       vis[node]=1;
       low[node]=tin[node]=timer++;

       for(auto child:adj[node])
       {
           if(child==parent)continue;

           if(!vis[child])
           {
               
               dfs(child,node,vis,adj,low,tin);
               
               low[node]=min(low[node],low[child]);
               
               if(low[child]>tin[node])
               {
                  vector<int>v={node,child};
                  bridges.push_back(v);
               }

           }else{

               low[node]=min(low[node],low[child]);

           }
       }
  }

int main()
{ 

    int n;
    cin>>n;
    
    
    vector<int>adj[n];
     
     for(int i=0;i<n;i++)
     {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
     }
   
        int low[n];
        int tin[n];
        vector<int>vis=vector<int>(n,0);
       
        dfs(0,-1,vis,adj,low,tin);

        
}