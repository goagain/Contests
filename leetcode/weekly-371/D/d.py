from typing import List

class TrieNode:
    def __init__(self, depth):
        self.zero = None
        self.one = None
        self.depth = depth
        self.largest = None
        self.smallest = None
        self.origional = None

    def insert(self, original: int, num: int):
        if self.largest is None or self.largest < original:
            self.largest = original
        if self.smallest is None or self.smallest > original:
            self.smallest = original

        if self.depth == -1:
            self.origional = original
            return
        
        bit = (1 << self.depth)
        if num & bit > 0:
            if self.one is None:
                self.one = TrieNode(self.depth - 1)
            self.one.insert(original, num ^ bit)
        else:
            if self.zero is None:
                self.zero = TrieNode(self.depth - 1)
            self.zero.insert(original, num)
    
    def acceptable(self, original: int):
        if original * 2 < self.smallest:
            return False
        if original > self.largest * 2:
            return False
        return True

    def query(self, original: int, num: int) -> int:
        if self.depth == -1:
            return self.origional ^ original

        bit = (1 << self.depth)

        if bit & num > 0:
            if self.zero and self.zero.acceptable(original):
                return self.zero.query(original, num & ~bit)
            elif self.one and self.one.acceptable(original):
                return self.one.query(original, num & ~bit)
        else:
            if self.one and self.one.acceptable(original):
                return self.one.query(original, num & ~bit)
            elif self.zero and self.zero.acceptable(original):
                return self.zero.query(original, num & ~bit)

        return 0

    def __str__(self) -> str:
        return f'depth={self.depth}, largest={self.largest}, original={self.origional},one=({self.one}), zero=({self.zero})'
        
class Solution:
    def maximumStrongPairXor(self, nums: List[int]) -> int:
        ans = 0
        trie = TrieNode(20)
        for n in nums:
            trie.insert(n, n)
        
        # print(trie)

        for n in nums:
            # print(n, trie.query(n, n))
            ans = max(ans, trie.query(n, n))
        return ans

# print(Solution().maximumStrongPairXor([5]))

print(Solution().maximumStrongPairXor([1,2,3,4,5]))
print(Solution().maximumStrongPairXor([10,100]))
print(Solution().maximumStrongPairXor([500,520,2500,3000]))