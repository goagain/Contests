# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def constructFromPrePost(self, pre, post):
        """
        :type pre: List[int]
        :type post: List[int]
        :rtype: TreeNode
        """
        if not pre:
            return None
        root = TreeNode(pre[0])

        def dfs(node, pre, post):
            if not node:
                return None
            if len(pre) == 0:
                return None
            node.left = TreeNode(pre[0])

            sp = 0
            for i in range(len(post)):
                if post[i] == pre[0]:
                    sp = i
                    break
            dfs(node.left, pre[1: sp+1], post[0: sp])
            if sp != len(post) - 1:
                node.right = TreeNode(post[-1])
                dfs(node.right, pre[sp+2:], post[sp+1:-1])

        dfs(root, pre[1:], post[:-1])
        return root

pre = [1,2,4,5,3,6,7]
post = [4,5,2,6,7,3,1]
ret = Solution().constructFromPrePost(pre, post)
print (ret)