#include <iostream>

using namespace std;

class Solution
{
public:
    // TC: O(1)
    // SC: O(1)
    long long countWays(int m)
    {
        return m / 2 + 1;
    }
};