#include<bits/stdc++.h>
using namespace std;


class Stack
{
    public:
      int last;
      int size;
      int *arr;
 
    Stack(int size)
    {
            this->size=size;

            arr=new int [this->size];

            last=-1;
    }

    void push(int data)
    {
        if(size-last>1)
        {
              last++;
              arr[last]=data;

        }
        else{
            cout<<"Stack overflow\n";
        }
    }

    void pop()
    {
        if(last>=0)
        {
            last--;
        }
        else{
            cout<<"Stack underflow\n";
        }
    }

    int top()
    {
        if(last==-1)
        {
            cout<<"No element in stack";
        }
        else{
            return arr[last];
        }
    }

    bool isEmpty()
    {
        if(last==-1)
        {
            return true;
        }
        return false;
    }

};

int main()
{
     Stack st(5);

     st.push(46);
     st.push(40);
     cout<<"top element : "<<st.top()<<endl;
     st.pop();
      cout<<"top element : "<<st.top()<<endl;
    cout<<"is stack empty : "<<st.isEmpty()<<endl;
      st.pop();
     cout<<"is stack empty : "<<st.isEmpty()<<endl; 


}