#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    void generate(int i, int j, vector<vector<int>> &bracket, char &name, string &res)
    {
        if (i == j)
        {
            res += name++;
            return;
        }

        res += '(';

        generate(i, bracket[i][j], bracket, name, res);
        generate(bracket[i][j] + 1, j, bracket, name, res);

        res += ')';
    }

public:
    // TC: O(N^3)
    // AS: O(N^2)
    string matrixChainOrder(int p[], int n)
    {
        vector<vector<int>> dp(n, vector<int>(n)), bracket(n, vector<int>(n));

        for (int l = 2; l < n; l++)
        {
            for (int i = 1; i < n - l + 1; i++)
            {
                int j = i + l - 1;

                dp[i][j] = INT_MAX;

                for (int k = i; k < j; k++)
                {
                    int ans = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                    if (ans < dp[i][j])
                    {
                        dp[i][j] = ans;
                        bracket[i][j] = k;
                    }
                }
            }
        }

        char name = 'A';
        string res;
        generate(1, n - 1, bracket, name, res);
        return res;
    }
};