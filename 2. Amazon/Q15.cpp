#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    // TC: O(N)
    // AS: O(1)
    void linkdelete(struct Node *head, int M, int N)
    {
        Node *dummy = new Node(0);
        dummy->next = head;
        Node *cur = head, *prev = dummy;
        int mCnt = M, nCnt = 0;

        while (cur)
        {
            if (mCnt > 0)
            {
                prev = cur;
                cur = cur->next;
                if (--mCnt == 0)
                {             // M nodes skipped
                    nCnt = N; // now start deleting N nodes
                }
            }
            else if (nCnt > 0)
            {
                prev->next = cur->next;
                delete cur;
                cur = prev->next;

                if (--nCnt == 0)
                {             // N nodes deleted
                    mCnt = M; // now skip M nodes
                }
            }
            else
                break; // break when both are zero
        }
    }
};