//31 july 2023
// example problem - https://cses.fi/problemset/task/1674/


#include<bits/stdc++.h>
using namespace std;



void dfs(int node,unordered_map<int,vector<int>>&graph,vector<int>&vis,vector<int>&childs,vector<int>&depth)
{
     vis[node]=1;
     childs[node]+=1;

     for(auto child:graph[node])
     {
        if(!vis[child])
        {
            depth[child]=depth[node]+1;
           dfs(child,graph,vis,childs,depth);
           childs[node]+=childs[child];
        }
     }

     return ;
}

int main()
{
   int nodes;
   cin>>nodes;
  unordered_map<int,vector<int>>graph;
   for(int i=2;i<=nodes;i++)
   {
       int x;
       cin>>x;
       graph[x].push_back(i);
       graph[i].push_back(x);
     
   }

   
   vector<int>vis(nodes+1,0);
   vector<int>childs(nodes+1,0);
   vector<int>depth(nodes+1,0);

   dfs(1,graph,vis,childs,depth);
   for(int i=1;i<=nodes;i++)cout<<childs[i]-1<<" ";
   cout<<endl;

}