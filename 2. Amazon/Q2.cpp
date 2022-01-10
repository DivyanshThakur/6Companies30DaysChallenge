#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // TC: O(N)
    // SC: O(1)
    int longestMountain(vector<int> &arr)
    {
        int up = 0, down = 0, res = 0;
        for (int i = 1; i < arr.size(); i++)
        {
            if (down and arr[i - 1] < arr[i] or arr[i - 1] == arr[i])
                up = down = 0;
            up += arr[i - 1] < arr[i];
            down += arr[i - 1] > arr[i];
            if (up and down)
                res = max(res, up + down + 1);
        }

        return res;
    }
};