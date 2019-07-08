# @lc app=leetcode id=843 lang=python3
from typing import *

class Solution:
    answer = []
    def delNodes(self, root: TreeNode, to_delete: List[int]) -> List[TreeNode]:
        self.answer = []
        if root.val not in to_delete:
            self.answer.append(root)
        self.recurision(root, to_delete)
        return self.answer
    def recurision(self, root, to_delete):
        if root == None:
            return
        self.recurision(root.left, to_delete)
        self.recurision(root.right, to_delete)
        if root.val in to_delete:
            if root.left and root.left.val not in to_delete:
                self.answer.append(root.left)
            if root.right and root.right.val not in to_delete:
                self.answer.append(root.right)
        if root.left and root.left.val in to_delete:
            root.left = None
        if root.right and root.right.val in to_delete:
            root.right = None
