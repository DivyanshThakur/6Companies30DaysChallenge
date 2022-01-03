#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // TC: O(N)
    // SC: O(1)
    // Sliding Window
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int start = 0, sum = 0, res = INT_MAX;

        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];

            while (sum >= target)
            {
                res = min(res, i - start + 1);
                sum -= nums[start++];
            }
        }

        return res == INT_MAX ? 0 : res;
    }
};