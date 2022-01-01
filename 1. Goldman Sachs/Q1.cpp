#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
    vector<vector<string>> Anagrams(vector<string> &string_list)
    {
        map<map<char, int>, vector<string>> wordHash;

        for (auto &str : string_list)
        {
            map<char, int> mp;

            for (char c : str)
            {
                mp[c]++;
            }

            auto it = wordHash.find(mp);

            if (it != wordHash.end())
            {
                it->second.push_back(str);
            }
            else
            {
                wordHash.insert({mp, vector<string>{str}});
            }
        }

        vector<vector<string>> res;

        for (auto &p : wordHash)
        {
            res.push_back(p.second);
        }

        return res;
    }
};