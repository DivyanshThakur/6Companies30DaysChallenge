#include <iostream>
#include <vector>

#define ull unsigned long long

using namespace std;

class Solution
{
public:
    // TC: O(N)
    // SC: O(N)
    // #define ull unsigned long long
    /* Function to get the nth ugly number*/
    ull getNthUglyNo(int n)
    {
        ull dp[n + 1];
        dp[1] = 1;
        int p2 = 1, p3 = 1, p5 = 1;

        for (int i = 2; i <= n; i++)
        {
            ull num2 = dp[p2] * 2;
            ull num3 = dp[p3] * 3;
            ull num5 = dp[p5] * 5;

            ull nextUglyNumber = min(num2, min(num3, num5));
            dp[i] = nextUglyNumber;

            if (nextUglyNumber == num2)
                p2++;
            if (nextUglyNumber == num3)
                p3++;
            if (nextUglyNumber == num5)
                p5++;
        }

        return dp[n];
    }
};