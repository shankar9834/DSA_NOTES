#include<bits/stdc++.h>
using namespace std;


int nodes=100;  // 0 to 99 

int par[101];  // stores parent of the componant
int sz[101];   //stores size of the componant



void make_set()
{
     for(int i=0;i<=nodes-1;i++)
     {
        par[i]=i;
        sz[i]=1;
     }
}



int find_set(int n)
{
     if(par[n]==n)
     {
        return n;
     }

     par[n]=find_set(par[n]);
}


void union_set(int a,int b)
{
    int par1=find_set(a);
    int par2=find_set(b);
    
    if(par1==par2)
    {
         return ;
    }
  
    if(sz[par1]>sz[par2])
    {
        par[par2]=par1;
        sz[par1]+=sz[par2];

    }else{
        
           par[par1]=par2;
           sz[par2]+=sz[par1];
    }
  
    return ;
        
}

int main()
{
    //{u,{v,wt}}  -->  {node1 , {node2, edge_weight}}

    unordered_map<int,vector<pair<int,int>>>graph;

    make_set();


    // {wt, {u,v}}
    vector<pair<int,pair<int,int>>>edges;
   
     for(int i=0;i<nodes;i++)
     {
        for(auto el:graph[i])
        {
            int wt=el.second;
            int v=el.first;

            edges.push_back({wt,{i,v}});
        }
     }


     sort(edges.begin(),edges.end());
     
     int totalWeight=0;

       for(auto el:edges)
       {
          int wt=el.first;
          int u=el.second.first;
          int v=el.second.second;

          if(find_set(u)!=find_set(v))
          {
              union_set(u,v);
              totalWeight+=wt;
          }
       }
    
    cout<<"weight of minimum spanning tree is : "<<totalWeight<<endl;

}