# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):

    def __swap__(self, root):
        if not root or not root.next or not root.next.next:
            return root
        next = root.next
        next2 = root.next.next
        next3 = root.next.next.next
        
        root.next = next2
        next2.next = next
        next.next = next3
        self.__swap__(root.next.next)
        return root

    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        root = ListNode(0)
        root.next = head
        return self.__swap__(root).next

print(Solution().swapPairs(None))