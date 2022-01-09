#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution
{
public:
    // TC: O(N*N)
    // SC: O(1)
    int isValid(vector<vector<int>> mat)
    {
        vector<set<int>> row(9), col(9), grid(9);

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                int val = mat[i][j];

                if (val == 0)
                    continue;

                if (row[i].count(val) or col[j].count(val) or grid[3 * (i / 3) + j / 3].count(val))
                    return false;
                row[i].insert(val);
                col[j].insert(val);
                grid[3 * (i / 3) + j / 3].insert(val);
            }
        }

        return true;
    }
};