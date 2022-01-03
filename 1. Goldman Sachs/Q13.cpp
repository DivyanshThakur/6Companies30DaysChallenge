#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // TC: O(N)
    // SC: O(N)
    // Stack Solution
    string decodedString(string s)
    {
        stack<char> st;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != ']')
                st.push(s[i]);
            else
            {
                string text;
                while (st.top() != '[')
                {
                    text += st.top();
                    st.pop();
                }
                st.pop();
                
                string dig;

                while (!st.empty() && isdigit(st.top()))
                {
                    dig += st.top();
                    st.pop();
                }

                reverse(dig.begin(), dig.end());

                int num = stoi(dig);

                while (num--)
                {
                    for (int j = text.size() - 1; j >= 0; j--)
                    {
                        st.push(text[j]);
                    }
                }
            }
        }

        string decoded;

        while (!st.empty())
            decoded += st.top(), st.pop();

        reverse(decoded.begin(), decoded.end());

        return decoded;
    }
};