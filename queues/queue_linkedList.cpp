#include<bits/stdc++.h>
using namespace std;
//coding ninja
class Node{
    public:
    int data;
    Node* next;
    
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};

class Queue {
public:
    Node *head;
    Node *tail;
    int size;
    
    Queue() {
        // Implement the Constructor
       head=NULL;
        tail=NULL;
        size=0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        
        if(size==0)
        {
            return true;
        }
        
        return false;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if(head==NULL)
        {
            Node *newNode=new Node(data);
            head=newNode;
            tail=newNode;
             size++;
            return ;
        }
       tail->next=new Node(data);
       tail=tail->next;
        size++;
        return ;
        
        
    }

    int dequeue() {
        // Implement the dequeue() function
        if(isEmpty())
        {
            return -1;
        }
       
        if(size==1)
        {
            size=0;
            int ans=head->data;
            head=NULL;
            tail=NULL;
            return ans;
        }
        
        Node *tmp=head;
       int ans=tmp->data;
        head=head->next;
      //  delete tmp;
        size--;
        return ans;
        
        
    }

    int front() {
        // Implement the front() function
        if(isEmpty())
        {
           return -1; 
        }
        
        return head->data;
    }
};



int main()
{

}