#ifndef _NODE_H
#include<iostream>
class Node{
  //  private:
   public:
    int val;
    Node *left;
    Node *right;

//    public:

    Node()
    {
        
    }
    Node(int v)
    {
        this->val=v;
        left=NULL;
        right=NULL;

    }

    Node* createDummyTree();
};

#endif