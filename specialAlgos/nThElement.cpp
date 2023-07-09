// find the median of the elements given
//Time Complexity of std::nth_element(): O(n), with n being the distance between first and the last.

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    vector<int> v = { 3, 2, 10, 45, 33, 56, 23, 47, 60 }, i;
  
    // Using std::nth_element with n as v.size()/2 + 1
    std::nth_element(v.begin(), v.begin() + v.size() / 2, v.end());
  
    cout << "The median of the array is " << v[v.size() / 2];
  
    return 0;
}