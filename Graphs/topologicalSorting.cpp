//22 march 2023
//Author -- shankar wangwad


// for directed acyclic graph only

#include<bits/stdc++.h>
using namespace std;


// method 1

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


void topSort(int nodes,int egdes,unordered_map<int,vector<int>>&graph)
{
     vector<int>vis=vector<int>(nodes+1,0);
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


//method 2
//below is kahn's algorithm for topological sorting

void kahnTopSort(int nodes,int edges,unordered_map<int,vector<int>>&graph,unordered_map<int,int>&indegree)
{
    vector<int>topSortNodes;
    
      queue<int>q;

    for(int i=0;i<nodes;i++)
    {
        if(!indegree.count(i))
        {
              
              q.push(i);
        }
    }

    while(!q.empty())
    {
        int tp=q.front();
        q.pop();
        topSortNodes.push_back(tp);

        for(auto child:graph[tp])
        {
            indegree[child]--;
            
            if(indegree[child]==0)
            {
                q.push(child);
               
            }
        }

    }

    if(topSortNodes.size()==nodes)
    {
        cout<<"topological sorting is : ";
        for(auto el:topSortNodes)
        {
            cout<<el<<" ";
        }
        cout<<endl;
    }
    else{
        cout<<"topological sorting doesnt exit for given graph and there is cycle in a graph\n";
    }


}


int main()
{
     int nodes,edges;
    cout<<"enter number of nodes and edges \n";
    cin>>nodes>>edges;
 
   //vector<int>graph[100007]  can be used to store graph/edges

  // nodes are from 0 to nodes-1
  
   unordered_map<int,vector<int>>graph;
    
   unordered_map<int,int>indegree; 


    for(int i=0;i<edges;i++)
    {
        int x,y;
        cin>>x>>y;
        
        // edge from x to y

       //directed graph 
        graph[x].push_back(y);

        indegree[y]++;
      
    
    }

   // topSort(nodes,edges,graph);  // method 1

   kahnTopSort(nodes,edges,graph,indegree); //method 2
     

  

}



