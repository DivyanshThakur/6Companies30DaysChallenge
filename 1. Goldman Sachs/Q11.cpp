#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // TC: O(N)
    // SC: O(1)
    // Using XOR property
    int *findTwoElement(int *arr, int n)
    {
        int xorr = 0;
        for (int i = 0; i < n; i++)
            xorr ^= arr[i], xorr ^= (i + 1);
        int pos = xorr & ~(xorr - 1);

        int a = 0, b = 0;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] & pos)
            {
                a ^= arr[i];
            }
            else
            {
                b ^= arr[i];
            }
            if ((i + 1) & pos)
            {
                a ^= (i + 1);
            }
            else
            {
                b ^= (i + 1);
            }
        }

        int *res = new int[2];

        for (int i = 0; i < n; i++)
        {
            if (arr[i] == a)
            {
                res[0] = a;
                res[1] = b;
                break;
            }
            else if (arr[i] == b)
            {
                res[0] = b;
                res[1] = a;
                break;
            }
        }

        return res;
    }
};