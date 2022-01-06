#include <iostream>

using namespace std;

class Solution {
  public:
    // TC: O(N*K)
    // AS: O(N*K)
    int maxProfit(int K, int N, int A[]) {
        int dp[K+1][N+1];

        for(int i=0; i<=N; i++) {
            dp[0][i] = 0;
        }
        
        for(int i=1; i<=K; i++) {
            dp[i][0] = 0;
        }
        
        for(int i=1; i<=K; i++) {
            int prevDiff = INT_MIN;
            for(int j=1; j<=N; j++) {
                prevDiff = max(prevDiff, dp[i-1][j-1] - A[j-1]);
                
                dp[i][j] = max(dp[i][j-1], prevDiff + A[j]);
            }
        }
        
        return dp[K][N-1];
    }
};