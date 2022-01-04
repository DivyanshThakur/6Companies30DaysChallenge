#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
  // TC: O(N*10) or O(N*K) for max k elements
  // SC: O(10) or O(K) for max k elements
  vector<int> getMax10(vector<int> &list)
  {
    priority_queue<int, vector<int>, greater<int>> pq;

    for (auto num : list)
    {
      pq.push(num);
      if (pq.size() > 10)
        pq.pop();
    }

    vector<int> res;

    while (!pq.empty())
    {
      res.push_back(pq.top());
      pq.pop();
    }

    return res;
  }
};