#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution
{
public:
    // TC: O(N)
    // AS: O(K)
    vector<int> max_of_subarrays(vector<int> arr, int n, int k)
    {
        vector<int> res;
        deque<int> dq;

        for (int i = 0; i < k; i++)
        {
            while (!dq.empty() and arr[dq.back()] <= arr[i])
                dq.pop_back();
            dq.push_back(i);
        }

        res.push_back(arr[dq.front()]);

        for (int i = k; i < n; i++)
        {
            while (!dq.empty() and dq.front() <= i - k)
                dq.pop_front();
            while (!dq.empty() and arr[dq.back()] <= arr[i])
                dq.pop_back();
            dq.push_back(i);
            res.push_back(arr[dq.front()]);
        }
        return res;
    }
};