// 15 may 2023
// Author -- shankar wangwad
//problem link = https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/


#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;



//tc O(n), sc O(1)  , both methods
   
//method1
TreeNode* prevN;
   
void flattenMethod1(TreeNode* root)
{
     

        if(!root)return ;
        flattenMethod1(root->right);
        flattenMethod1(root->left);

        root->right=prevN;
        root->left=NULL;
        prevN=root;
        return ;   

}




//method 2 (without using global variable and iterative method)
 void flattenMethod2(TreeNode* root) {
       
       TreeNode* curr=root;
     if(!root)return ;
       while(curr!=NULL)
       {
           if(curr->left!=NULL)
           {
               TreeNode* pre=curr->left;
               while(pre->right)
               {
                  pre=pre->right;
               }
               
               pre->right=curr->right;
               curr->right=curr->left;
               curr->left=NULL;
              
           }
           curr=curr->right;
       }


    }

int main()
{
  prevN=NULL;

}