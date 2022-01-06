#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class Solution
{
    Node *fillParent(Node *root, unordered_map<Node *, Node *> &parentMap, int target)
    {
        queue<Node *> q;
        q.push(root);

        Node *targetNode;

        while (!q.empty())
        {
            auto node = q.front();
            q.pop();

            if (node->data == target)
                targetNode = node;

            if (node->left)
            {
                parentMap[node->left] = node;
                q.push(node->left);
            }

            if (node->right)
            {
                parentMap[node->right] = node;
                q.push(node->right);
            }
        }

        return targetNode;
    }

public:
    int minTime(Node *root, int target)
    {
        // Your code goes here

        if (!root)
            return 0;

        unordered_map<Node *, Node *> parentMap;
        Node *targetNode = fillParent(root, parentMap, target);

        queue<Node *> q;
        q.push(targetNode);
        unordered_map<Node *, bool> visited;
        int timer = 0;

        visited[targetNode] = true;

        while (!q.empty())
        {
            int len = q.size();
            bool isBurnt = false;

            for (int i = 0; i < len; i++)
            {
                auto node = q.front();
                q.pop();

                if (node->left && !visited[node->left])
                {
                    q.push(node->left);
                    visited[node->left] = true;
                    isBurnt = true;
                }

                if (node->right && !visited[node->right])
                {
                    q.push(node->right);
                    visited[node->right] = true;
                    isBurnt = true;
                }

                auto parentNode = parentMap[node];

                if (parentNode && !visited[parentNode])
                {
                    q.push(parentNode);
                    visited[parentNode] = true;
                    isBurnt = true;
                }
            }

            if (isBurnt)
                timer++;
        }

        return timer;
    }
};