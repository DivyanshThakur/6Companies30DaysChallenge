#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // TC: O(N)
    // SC: O(1)
    int countSubArrayProductLessThanK(const vector<int> &a, int n, long long k)
    {
        int count = 0;
        long long prod = 1;

        for (int start = 0, end = 0; end < n; end++)
        {
            prod *= a[end];

            while (prod >= k && start <= end)
            {
                prod /= a[start++];
            }

            count += (end - start + 1);
        }

        return count;
    }
};