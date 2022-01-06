#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
    bool isSafe(int row, int col, vector<vector<int>> &grid)
    {
        return row >= 0 && col >= 0 && row < grid.size() && col < grid[0].size() && grid[row][col] == 1;
    }

public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        queue<pair<int, int>> rottenOranges;
        int dir[5] = {0, 1, 0, -1, 0};
        int minutes = -1, freshOranges = 0;

        for (int row = 0; row < grid.size(); row++)
        {
            for (int col = 0; col < grid[0].size(); col++)
            {
                if (grid[row][col] == 2)
                {
                    rottenOranges.push({row, col});
                }
                if (grid[row][col] == 1)
                {
                    freshOranges++;
                }
            }
        }

        if (freshOranges == 0)
            return 0;

        while (!rottenOranges.empty())
        {
            int len = rottenOranges.size();

            for (int i = 0; i < len; i++)
            {
                int curRow = rottenOranges.front().first;
                int curCol = rottenOranges.front().second;
                rottenOranges.pop();

                for (int i = 0; i < 4; i++)
                {
                    int nxtRow = curRow + dir[i];
                    int nxtCol = curCol + dir[i + 1];

                    if (isSafe(nxtRow, nxtCol, grid))
                    {
                        freshOranges--;
                        grid[nxtRow][nxtCol] = 2;
                        rottenOranges.push({nxtRow, nxtCol});
                    }
                }
            }
            minutes++;
        }

        if (freshOranges > 0)
            return -1;

        return minutes;
    }
};