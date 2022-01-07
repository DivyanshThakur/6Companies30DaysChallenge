#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // TC: O(N)
    // AS: O(1)
    string colName(long long int n)
    {
        string s;

        while (n)
        {
            int rem = n % 26;
            if (!rem)
            {
                s += 'Z';
                n = n / 26 - 1;
            }
            else
            {
                s += rem - 1 + 'A';
                n /= 26;
            }
        }

        reverse(s.begin(), s.end());

        return s;
    }
};