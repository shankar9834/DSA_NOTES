#include<bits/stdc++.h>
using namespace std;

class compare{
  public:
     bool operator()(pair<int,string> const& p1, pair<int,string> const& p2)
    {
      
        if(p1.first==p2.first){
            return p1.second>p2.second;
        }
        return p1.first<p2.first;
    }

};

int main()
{
        priority_queue<pair<int,string>,vector<pair<int,string>>,compare>pq;


        pq.push({3,"shan"});
        pq.push({3,"shnk"});
        pq.push({2,"kar"});
        while(!pq.empty())
        {
          cout<<pq.top().first<<" "<<pq.top().second<<endl;
          pq.pop();
        }



        //method 2
        vector<int> nums1={4,3,2,7,5};
        vector<int> nums2={1,2,7,3,5};
         auto comp = [&nums1, &nums2](pair<int, int> a, pair<int, int> b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];};
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> min_heap(comp);
        min_heap.emplace(0, 0);
}