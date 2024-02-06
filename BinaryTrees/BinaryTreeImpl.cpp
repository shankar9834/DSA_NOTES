// source - love babbar dsa lec-62 

#include <bits/stdc++.h>
#include "Node.h"
using namespace std;

Node *buildTree(Node *root)
{
    int data;
    cout << "Enter data\n";
    cin >> data;
    if (data == -1)
        return NULL;
    root = new Node(data);

    cout << "Enter data for inserting in left of " << data << endl;
    // cin>>data;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    // cin>>data;
    root->right = buildTree(root->right);

    return root;
}

void inOrder(Node *root)
{
    if (!root)
        return;

    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

void levelOrderLevelwise(Node *root)
{
    queue<Node *> q;

    if (!root)
        return;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        if (curr == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << curr->val << " ";
            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
        }
    }
}

void buildTreeInorder(Node *&root)
{
    cout << "enter data\n";
    int data;
    cin >> data;
    if (data == -1)
        return;
    root = new Node(data);

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        cout << "enter left child for " << curr->val << endl;
        int lchild;
        cin >> lchild;
        if (lchild != -1)
        {
            curr->left = new Node(lchild);
            q.push(curr->left);
        }

        cout << "enter right child for " << curr->val << endl;
        int rchild;
        cin >> rchild;
        if (rchild != -1)
        {
            curr->right = new Node(rchild);
            q.push(curr->right);
        }
    }
}

// using preorder
void printLeafNodes(Node *root)
{
    if (!root)
        return;
    if (root->left == NULL && root->right == NULL)
    {
        cout << root->val << " ";
    }

    printLeafNodes(root->left);
    printLeafNodes(root->right);
}

int main()
{
    Node *root = NULL;
    // cout<<"hello";

    /*   root=buildTree(root);
      inOrder(root);
      cout<<endl;
      cout<<"Pinting levels\n";
      levelOrderLevelwise(root); */
    buildTreeInorder(root);
    levelOrderLevelwise(root);
    cout << "\nPrinting leaf Nodes : ";
    printLeafNodes(root);
    cout << endl;
}