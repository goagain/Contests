class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        self.stack = []
        
        for c in s:
            if c == '(' or c == '[' or c == '{':
                self.stack.append(c)
            else:
                if len(self.stack) == 0:
                    return False
                top = self.stack.pop()
                if ord(top) != ord(c) - 1 and ord(top) != ord(c) - 2 :
                    return False
        return len(self.stack) == 0

# print(Solution().isValid("((()))"))
print(Solution().isValid("()[]{}"))