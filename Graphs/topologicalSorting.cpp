//22 march 2023
//Author -- shankar wangwad


// for directed acyclic graph only

#include<bits/stdc++.h>
using namespace std;


void dfs(int node,unordered_map<int,vector<int>>&graph,vector<int>&vis,stack<int>&st)
{
           vis[node]=1;

           for(auto child:graph[node])
           {
            if(!vis[child])
            {
                dfs(child,graph,vis,st);
            }
           }
          
          st.push(node);
           return ;
} 

int main()
{
     int nodes,edges;
    cout<<"enter number of nodes and edges \n";
    cin>>nodes>>edges;
 
   //vector<int>graph[100007]  can be used to store graph/edges

   unordered_map<int,vector<int>>graph;
   vector<int>vis=vector<int>(100007,0);

    for(int i=0;i<edges;i++)
    {
        int x,y;
        cin>>x>>y;

       //directed graph 
        graph[x].push_back(y);
      
    
    }

    stack<int>st;

    for(int i=0;i<nodes;i++)
    {
        if(!vis[i])
        {
            dfs(i,graph,vis,st);
        }
    }


    vector<int>ans;

    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    cout<<"topological order is : ";

    for(auto el:ans)
    {
        cout<<el<<" ";
    }
    cout<<endl;

}