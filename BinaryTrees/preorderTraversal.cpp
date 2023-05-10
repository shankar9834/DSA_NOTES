// 10 may 2023
// Author -- shankar wangwad


#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;


//recursive
void preorder(TreeNode* root,vector<int>&ans)
   {
       if(!root)return ;

          ans.push_back(root->val);
          preorder(root->left,ans);
          preorder(root->right,ans);
          return ;
   }

   vector<int> recursivePreorder(TreeNode* root)
   {
       vector<int>ans;

       preorder(root,ans);
       return ans;

   }


// iterative 
   vector<int> iterativePreorder(TreeNode* root)
   {
           vector<int>ans;

           stack<TreeNode*>st;
           TreeNode* curr=root;

           while(curr||!st.empty())
           {
               while(curr)
               {
                  st.push(curr);
                  ans.push_back(curr->val);
                  curr=curr->left;
               }
               curr=st.top();
               st.pop();
               curr=curr->right;
               
           }

           return ans;


   }

    vector<int> preorderTraversal(TreeNode* root) {
        
       // return recursivePreorder(root);

         return iterativePreorder(root);
    }


int main()
{
         TreeNode *root=new TreeNode(10);
         root->left=new TreeNode(15);
         root->right=new TreeNode(17);

         vector<int>res=preorderTraversal(root);
         cout<<"printing preorder traversal\n";
         for(auto el:res)
         {
            cout<<el<<" ";
         }
         cout<<endl;

}