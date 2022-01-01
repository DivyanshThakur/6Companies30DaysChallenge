#include <iostream>

using namespace std;

class Solution
{
public:
    // TC: O(1)
    // SC: O(1)
    int doOverlap(int L1[], int R1[], int L2[], int R2[])
    {
        // Checking for case where two rectanges don't overlap
        return !(L1[1] < R2[1] or L2[1] < R1[1] or R1[0] < L2[0] or R2[0] < L1[0]);
    }
};