#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for singly-linked list.
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
  public:
    int deep = 0;

    void Recursion(ListNode *cur, int n, ListNode **ans)
    {
        if (cur == nullptr)
        {
            deep = 0;
            return;
        }
        Recursion(cur->next, n, ans);
        deep++;
        if (n == deep)
        {
            return;
        }
        ListNode *now = *ans;
        *ans = new ListNode(cur->val);
        (*ans)->next = now;
    }

    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *root = nullptr;
        Recursion(head, n, &root);
        return root;
    }
};

int main(int argc, char const *argv[])
{
    ListNode *node = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    Solution().removeNthFromEnd(node, 3);
    return 0;
}
