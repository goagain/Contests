#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
  public:
    struct cmp
    {
        bool operator()(ListNode *node1, ListNode *node2) { return node1->val > node2->val; }
    };
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode root = ListNode(0);
        ListNode *current = &root;
        priority_queue<ListNode *, vector<ListNode *>, cmp> queue;
        for (int i = 0; i < lists.size(); i++)
        {
            if (lists[i] != nullptr)
                queue.push(lists[i]);
        }
        while (!queue.empty())
        {
            ListNode *front = queue.top();
            if (front != nullptr)
            {
                current->next = front;
                current = current->next;

                queue.pop();
                if (front->next != nullptr)
                {
                    queue.push(front->next);
                }
            }
        }
        return root.next;
    }
};

int main(int argc, char const *argv[])
{
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);

    ListNode *l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    ListNode *l3 = new ListNode(2);
    l3->next = new ListNode(6);

    vector<ListNode *> arg{l1, l2, l3};
    ListNode *ans = Solution().mergeKLists(arg);
    system("pause");
    /* code */
    return 0;
}
