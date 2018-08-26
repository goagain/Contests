# Definition for a binary tree node.
import copy
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    collection = {}
    totalremain = 0
    def dfs(self, n):
        if n in self.collection:
            return self.collection[n]
        if n == 0 or n % 2 == 0:
            return None
        if n == 1:
            self.collection[1] = [TreeNode(0)]
            return self.collection[1]
        else:
            collection = []
            root = TreeNode(0)
            for i in range(1, n, 2):
                collectionLeft = self.dfs(i)
                collectionRight = self.dfs(n-i-1)
                for l in collectionLeft:
                    for r in collectionRight:
                        root.left = l
                        root.right = r
                        collection.append(copy.copy(root))
            self.collection[n] = collection
            return collection

    def allPossibleFBT(self, N):
        """
        :type N: int
        :rtype: List[TreeNode]
        """
        if N % 2 == 0:
            return []
        else:
            ans = self.dfs(N)
            return ans
print(Solution().allPossibleFBT(19))