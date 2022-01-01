#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    // TC: O(N*K*logK), N: Number of words, K: Maximum length of string
    // SC: O(N*K)
    vector<vector<string>> Anagrams(vector<string> &string_list)
    {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> wordHash;

        for (auto &word : string_list)
        {
            string s = word;
            sort(s.begin(), s.end());

            wordHash[s].push_back(word);
        }

        for (auto &p : wordHash)
        {
            res.push_back(p.second);
        }

        return res;
    }
};