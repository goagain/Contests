# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def smallestFromLeaf(self, root: 'TreeNode') -> 'str':
        if root.val == None:
            return ""
        ans = self.smallest(root)
        return ''.join([chr(x + ord('a')) for x in ans])

    def smallest(self, root: 'TreeNode') -> 'list':
        if root.left == None and root.right == None:
            return [root.val]
        if root.left == None:
            return self.smallest(root.right) + [root.val]
        if root.right == None:
            return self.smallest(root.left) + [root.val]
        return min(self.smallest(root.left), self.smallest(root.right)) + [root.val]
