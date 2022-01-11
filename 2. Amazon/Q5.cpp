#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // TC: O(S*N*K)
    // AS: O(N*K), where K is maximum length of string from contact list
    struct Node
    {
        Node *child[26];
        bool terminal;
        int freq;
        Node(char c)
        {
            this->freq = 1;
            this->terminal = false;
            for (int i = 0; i < 26; i++)
            {
                child[i] = NULL;
            }
        }
    };

    struct trie
    {
        vector<vector<string>> ans;
        Node *root;
        trie()
        {
            this->root = new Node('\0');
        }
        void insertNode(string s)
        {
            Node *temp = root;
            int n = s.size();
            for (int i = 0; i < n; i++)
            {
                if (temp->child[s[i] - 'a'] != NULL)
                {
                    temp->child[s[i] - 'a']->freq += 1;
                    temp = temp->child[s[i] - 'a'];
                }
                else
                {
                    Node *newnode = new Node(s[i]);
                    temp->child[s[i] - 'a'] = newnode;
                    temp = temp->child[s[i] - 'a'];
                }
            }
            temp->terminal = true;
        }
        // backtracking func to from all strings starting with s
        void recur(Node *root, vector<string> &v, string &s)
        {
            if (root->terminal)
            {
                v.push_back(s);
            }
            for (int i = 0; i < 26; i++)
            {
                if (root->child[i] != NULL)
                {
                    s.push_back(i + 'a');
                    recur(root->child[i], v, s);
                    s.pop_back();
                }
            }
        }
        // finds all strings starting with s in phonebook
        void findcontact(string s)
        {
            vector<string> v;
            Node *temp = root;
            string str = s;
            for (int i = 0; i < s.size(); i++)
            {
                if (temp->child[s[i] - 'a'] != NULL)
                {
                    temp = temp->child[s[i] - 'a'];
                }
                else
                {
                    ans.push_back({"0"});
                    return;
                }
            }
            recur(temp, v, str);
            ans.push_back(v);
        }
    };

    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        trie t;
        for (int i = 0; i < n; i++)
        {
            t.insertNode(contact[i]);
        }
        for (int i = 1; i <= s.size(); i++)
        {
            t.findcontact(s.substr(0, i));
        }
        return t.ans;
    }
};