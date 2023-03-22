//22 march 2023
//Author -- shankar wangwad


// kosarajus algorithm
// first create topological order using stack
// then transpose graph (reverse edges)
// then do dfs by picking top element from stack till stack is not empty to get strongly connected componants

//for  directed graph

#include <bits/stdc++.h>


using namespace std;
vector<int>vis(10007);
vector<int>adj[10007];
vector<int>adjT[10007];
stack<int>st;

int nodes,edges;

void tops(int n)
{
      vis[n]=1;

      for(auto child:adj[n])
      {
        if(!vis[child])
        {
            tops(child);
        }
      }

      st.push(n);
   
}

void transposeGraph()
{
      for(int i=0;i<nodes;i++)
      {
           for(auto el:adj[i])
           {
              adjT[el].push_back(i);
           }
      }
}

void dfs(int node)
{
     vis[node]=1;

     for(auto child:adjT[node])
     {
        if(!vis[child])
        {
            dfs(child);
        }
     }
}





int main()
{
   
    cin>>nodes>>edges;
    
    for(int i=0;i<edges;i++)
     {
       int x,y;
       cin>>x>>y;
       adj[x].push_back(y);

     }

    for(int i=0;i<nodes;i++)
    {
        if(!vis[i])
        {
          tops(i);
        }
    }
        
        transposeGraph();   
      
      for(int i=0;i<=nodes;i++)vis[i]=0;


       int scss=0;
        while(!st.empty())
        {
              int node=st.top();
              st.pop();
              if(!vis[node])
              {
                dfs(node);
                scss++;
              }
        }       

        cout<<scss<<endl;
    return 0;
}


