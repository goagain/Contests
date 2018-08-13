# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

    def __str__(self):
        if self.next == None:
            return str(self.val)
        else:
            return str(self.val) + " " + self.next.__str__()


def CreateListNode(array):
    if not array:
        return None
    root = ListNode(0)
    cur = root
    for x in array:
        cur.next = ListNode(x)
        cur = cur.next
    return root.next

def CheckListLength(node):
    """
    :type node: ListNode
    """
    if node:
        return 1 + CheckListLength(node.next)
    return 0

class Solution(object):
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if k == 1:
            return head
        root = ListNode(0)
        root.next = head
        cur = root.next
        groupFirst = None
        prevGroupFirst = root
        prev = root
        count = 1
        while cur:
            next = cur.next
            if count == 1:  # firstNode in each group
                if CheckListLength(cur) < k:
                    prevGroupFirst.next = cur
                    return root.next

                groupFirst = cur
                cur.next = None
            else:
                cur.next = prev
            if count == k:
                prevGroupFirst.next = cur
                prevGroupFirst = groupFirst
                count = 0
            cur, prev = next, cur
            count = count + 1
        return root.next


print(Solution().reverseKGroup(CreateListNode([1, 2, 3, 4, 5, 6, 7, 8, 9]), 5))
