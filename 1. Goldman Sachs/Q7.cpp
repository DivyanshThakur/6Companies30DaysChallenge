#include <iostream>

using namespace std;

class Solution {
  public:
    // TC: O(1)
    // SC: O(1)
    int findPosition(int N , int M , int K) {
        if(M <= N-K+1) return K+M-1;
        M -= N-K+1;
        
        return (M%N == 0) ? N : M%N;
    }
};