#include <iostream>
#include <queue>

using namespace std;

class Solution
{
public:
    // TC: O(26*N)
    // SC: O(26)
    string FirstNonRepeating(string A)
    {
        string res;
        int hash[26]{0};
        queue<char> q;
        
        for (char c : A)
        {
            hash[c - 'a']++;
            q.push(c);

            while (!q.empty() and hash[q.front() - 'a'] > 1)
                q.pop();

            res += q.empty() ? '#' : q.front();
        }

        return res;
    }
};