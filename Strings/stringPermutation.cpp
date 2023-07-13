#include <bits/stdc++.h>
using namespace std;

vector<int> chosen(6, 0);
vector<int> permutation;
int n = 5;

//method 1
void method1()
{
    if (permutation.size() == n)
    {
        // process permutation
        for (auto el : permutation)
            cout << el << " ";
        cout << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (chosen[i])
                continue;
            chosen[i] = true;
            permutation.push_back(i);
            method1();
            chosen[i] = false;
            permutation.pop_back();
        }
    }
}


// method 2 , using swaping and recursion



//method 3
void method3()
{
      
    vector<int> permutation2;
    for (int i = 0; i < n; i++)
    {
        permutation2.push_back(i);
    }
    do
    {
        // process permutation
    } while (next_permutation(permutation2.begin(), permutation2.end()));
}


int main()
{
    method1();


   
}