//22 march 2023
//Author -- shankar wangwad

// example problem -  https://leetcode.com/problems/rotting-oranges/


#include<bits/stdc++.h>
using namespace std;

  int dx[4]={0,0,-1,1};
  int dy[4]={1,-1,0,0};
  
  bool isValid(int x,int y,vector<vector<int>>&vis,vector<vector<int>>&grid)
  {
      int rw=grid.size();
      int cl=grid[0].size();

      if(x>=0&&x<rw&&y>=0&&y<cl&&(vis[x][y]==0)&&grid[x][y]==1)
      {
          return true;
      }

      return false;
  }


 int orangesRotting(vector<vector<int>>& grid) {
        
        vector<vector<int>>vis=vector<vector<int>>(12,vector<int>(12,0));
       
       queue<pair<pair<int,int>,int>>q;
       
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
              

                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                     vis[i][j]=1;
                }
               
            }
        }

         int ans=0;
         while(!q.empty())
         {
             int sz=q.size();
             while(sz--)
             {
                 pair<pair<int,int>,int>tp=q.front();
                 q.pop();

                 int x=tp.first.first;
                 int y=tp.first.second;

                 for(int i=0;i<4;i++)
                 {
                    int xn=x+dx[i];
                    int yn=y+dy[i];
                    int curr=tp.second;

                    if(isValid(xn,yn,vis,grid))
                    {
                       q.push({{xn,yn},curr+1});
                       grid[xn][yn]=2;
                       vis[xn][yn]=1;
                       ans=max(ans,curr+1);
                    }
                 }


             }
         }
         
         for(int i=0;i<grid.size();i++)
         {
             for(int j=0;j<grid[0].size();j++)
             {
                 if(grid[i][j]==1)
                 {
                     return -1;
                 }
             }
         }
         return ans;
    }



int main()
{
   // for more info read question from above link given 


   /*
   Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
    Output: 4
   */

  vector<vector<int>>grid={{2,1,1},{1,1,0},{0,1,1}};
  
  cout<<orangesRotting(grid)<<endl;

}