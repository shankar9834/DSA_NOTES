// 10 may 2023
// Author -- shankar wangwad


#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;



//recursive
  void inorder(TreeNode* root,vector<int>&ans)
   {
       if(!root)return ;

       inorder(root->left,ans);
       ans.push_back(root->val);
       inorder(root->right,ans);
       return ;
   }

   vector<int> recursiveInorder(TreeNode *root)
   {
            vector<int>ans;
            inorder(root,ans);
            return ans;
   }

//iterative
   vector<int> iterativeInorder(TreeNode* root)
   {
           vector<int>ans;

           TreeNode* curr=root;
          stack<TreeNode*>st;
           while(curr||!st.empty())
           {
               
              while(curr)
              {
                  st.push(curr);
                  curr=curr->left;
              }
              TreeNode* tp=st.top();
              st.pop();
              ans.push_back(tp->val);
              curr=tp;
              curr=curr->right; 
   
           }
           return ans;

   }

    vector<int> inorderTraversal(TreeNode* root) {
     
     // return recursiveInorder(root);
        return iterativeInorder(root);
    }


int main()
{
     TreeNode *root=new TreeNode(10);
         root->left=new TreeNode(15);
         root->right=new TreeNode(17);

           vector<int>res=inorderTraversal(root);

     cout<<"printing preorder traversal\n";
         for(auto el:res)
         {
            cout<<el<<" ";
         }
         cout<<endl;
}