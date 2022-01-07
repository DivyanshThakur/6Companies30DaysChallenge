#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int data) : data(data) {}
};

class Solution
{
public:
    // Function to serialize a tree and return a list containing nodes of tree.
    // TC: O(N)
    // AS: O(N)
    vector<int> serialize(Node *root)
    {
        vector<int> res;

        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            Node *node = q.front();
            q.pop();
            int val = node ? node->data : 0;
            res.push_back(val);

            if (node)
            {
                q.push(node->left);
                q.push(node->right);
            }
        }
        return res;
    }

    // Function to deserialize a list and construct the tree.
    // TC: O(N)
    // AS: O(N)
    Node *deSerialize(vector<int> &A)
    {
        if (A.empty())
            return NULL;

        queue<Node *> q;
        Node *root = new Node(A[0]);
        q.push(root);
        int i = 1;

        while (!q.empty())
        {
            Node *node = q.front();
            q.pop();

            int val = A[i++];

            if (val)
            {
                node->left = new Node(val);
                q.push(node->left);
            }

            val = A[i++];

            if (val)
            {
                node->right = new Node(val);
                q.push(node->right);
            }
        }

        return root;
    }
};