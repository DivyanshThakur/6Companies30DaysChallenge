#include <iostream>

using namespace std;

class Solution
{
    int mod = 1e9 + 7;

public:
    int CountWays(string str)
    {
        if (str[0] == '0')
            return 0;

        int n = str.size();

        if (n <= 1)
            return 1;

        int a = 1, b = 1, c;

        for (int i = 1; i < n; i++)
        {
            if (str[i] == '0' and str[i - 1] > '2')
                return 0;
        }

        for (int i = 2; i <= n; i++)
        {
            c = 0;
            if (str[i - 1] > '0')
                c = b;
            if (str[i - 2] == '1' or (str[i - 2] == '2' and str[i - 1] < '7'))
            {
                c = (c + a) % mod;
            }
            a = b;
            b = c;
        }

        return c;
    }
};