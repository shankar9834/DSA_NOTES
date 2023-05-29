// 29 may 2023
// Author -- shankar wangwad

//application 
// 1) finding connected componants 
// 2)used in kruskals algorithm for finding minimum spanning tree

#include<bits/stdc++.h>
using namespace std;

int nodes=100;  // 0 to 99 

int par[101];
int sz[101];



void make_set()
{
     for(int i=0;i<=nodes-1;i++)
     {
        par[i]=i;
        sz[i]=1;
     }
}


//optimisation
//added path compression 

int find_set(int n)
{
     if(par[n]==n)
     {
        return n;
     }

     par[n]=find_set(par[n]);
}

//optimisation
//we attach the tree with the lower size to the one with the bigger size.

void union_set(int a,int b)
{
    int par1=find_set(a);
    int par2=find_set(b);
    
    if(par1==par2)
    {
        cout<<"they are already present in a same componant\n";
           return ;
    }

    if(sz[a]>sz[b])
    {
        par[b]=a;
        sz[b]+=sz[a];

    }else{
           par[a]=b;
           sz[b]+=sz[a];
    }
    return ;
        
}

int main()
{
    make_set();
}