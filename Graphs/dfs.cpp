// 22 march 2023  
// Author -- shankar wangwad

#include<bits/stdc++.h>
using namespace std;

void dfs(int node,unordered_map<int,vector<int>>&graph,vector<int>&vis)
{
           vis[node]=1;

           for(auto child:graph[node])
           {
            if(!vis[child])
            {
                dfs(child,graph,vis);
            }
           }

           return ;
} 




int main()
{
    int nodes,edges;
    cout<<"enter number of nodes and edges \n";
    cin>>nodes>>edges;
 
   //vector<int>graph[100007]  can be used to store graph/edges

   unordered_map<int,vector<int>>graph;


    for(int i=0;i<edges;i++)
    {
        int x,y;
        cin>>x>>y;

       //undirected graph 
        graph[x].push_back(y);
        graph[y].push_back(x);
    
    // if graph is directed then use below 
    // graph[x].push_back(y)

    }

   vector<int>vis=vector<int>(100007,0);
  
//connected_comp variable will contain number of connected componants of the graph
   int connected_comp=0;

// nodes numbering are from 0 to nodes-1
  for(int i=0;i<nodes;i++)
  {
    if(!vis[i])
    {
        dfs(i,graph,vis);
        connected_comp++;  
    }
  }

}