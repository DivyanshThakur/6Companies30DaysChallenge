#include <iostream>

using namespace std;

class Solution
{
public:
    // TC: O(1)
    // SC: O(1)
    long long squaresInChessBoard(long long N)
    {
        return N * (N + 1) * (2 * N + 1) / 6;
    }
};