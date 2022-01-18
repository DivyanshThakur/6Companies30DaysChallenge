#include <iostream>

using namespace std;

class Solution
{
public:
    // TC: O(N*K)
    // AS: O(N)
    int maxProfit(int K, int N, int A[])
    {
        int dp[N];

        for (int i = 0; i < N; i++)
            dp[i] = 0;

        for (int i = 1; i <= K; i++)
        {
            int maxDiff = dp[0] - A[0];
            for (int j = 1; j < N; j++)
            {
                int preValue = dp[j];

                dp[j] = dp[j - 1];

                dp[j] = max(dp[j], A[j] + maxDiff);

                maxDiff = max(maxDiff, preValue - A[j]);
            }
        }

        return dp[N - 1];
    }
};