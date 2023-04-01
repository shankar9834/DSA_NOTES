// 25 march 2023
// Author -- shankar wangwad

// dijkstra algorithm is used to find shortest path from starting node to all nodes in a weighted graph 

#include<bits/stdc++.h>
using namespace std;


int main()
{
    cout<<"enter number of nodes \n";
    int nodes;
    cin>>nodes;
  
    unordered_map<int,vector<pair<int,int>>>graph;
    
   cout<<"enter u(node1), v(node2), distance between both nodes\n";
     for(int i=0;i<nodes;i++)
     {
        int x,y,dist;
        cin>>x>>y>>dist;
        graph[x].push_back({y,dist});
        graph[y].push_back({x,dist});

     }
    cout<<"enter starting and ending node\n";
    int startingNode,endingNode;
    cin>>startingNode>>endingNode;

    vector<int>vis=vector<int>(10005,0);

    // storing distance of node from starting node 
    vector<int>distance=vector<int>(10005,INT_MAX);

   // to store parent of node , we can find starting to ending node path using this parent vector
    vector<int>parent=vector<int>(100005,-1);

     // {dist,node}
     set<pair<int,int>>st;   // we can also use priority queue instead of set

     st.insert({0,startingNode});
    
     distance[startingNode]=0;

     while(st.size()>0)
     {
          auto tp=*st.begin();
          st.erase(st.begin());
         
         int u=tp.second;

          if(vis[u])continue;

          vis[u]=1;

          for(auto childPair:graph[u])
          {
              int v=childPair.first;
              int uvDist=childPair.second;

               if(distance[u]+uvDist<distance[v])
               {
                distance[v]=distance[u]+uvDist;
                parent[v]=u;
                st.insert({distance[v],v});
               }

          }
     }
      

     // storing path from starting node to ending node

      int node=endingNode;
      vector<int>path;
    while(parent[node]!=-1)
    {
        path.push_back(parent[node]);
        node=parent[node];
    }

    reverse(path.begin(),path.end());


      cout<<"distance from starting node to ending node is : "<<distance[endingNode]<<endl;
      cout<<"path from starting node to ending node is : ";
      for(auto el:path)cout<<el<<" ";
      cout<<endl;
      


     
    
}
