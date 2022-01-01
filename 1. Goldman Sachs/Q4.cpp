#include <iostream>

using namespace std;

class Solution
{
public:
    // TC: O(N)
    // AC: O(1) // AC: AUXILARY SPACE
    string encode(string src)
    {
        string res;
        int start = 0;

        for (int i = 0; i < src.size() - 1; i++)
        {
            if (src[i] == src[i + 1])
                continue;
            res += src[i] + to_string(i - start + 1);
            start = i + 1;
        }

        res += src[src.size() - 1] + to_string(src.size() - start);

        return res;
    }
};