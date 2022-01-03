#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    // TC: O(N)
    // SC: O(N)
    bool canPair(vector<int> nums, int k)
    {
        if (nums.size() & 1)
            return false;

        unordered_map<int, int> mp;

        for (auto n : nums)
            mp[n % k]++;

        for (auto n : nums)
        {
            int rem = n % k;

            if ((rem == 0) or (2 * rem == k))
            {
                if (mp[rem] & 1)
                    return false;
            }
            else if (mp[rem] != mp[k - rem])
                return false;
        }

        return true;
    }
};