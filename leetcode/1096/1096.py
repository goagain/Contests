from typing import *
import itertools
class Solution:
    def braceExpansionII(self, expression: str) -> List[str]:
        return self.expand(expression)

    def expand(self, expression):
        if not expression:
            return []
        pos = 0
        word = []
        word_set = set()
        while pos <= len(expression):
            if pos == len(expression):
                c = ','
            else:
                c = expression[pos]
            if c == '{':
                end_pos = self.findMatchedBracket(expression, pos)
                word.append(self.expand(expression[pos + 1:end_pos]))
                pos = end_pos
            elif c == ',':
                word_set |= set(map(''.join, itertools.product(*word)))
                word = []
            else:
                word.append([c])
            pos += 1
        print("expand" , expression, list(word_set))
        return sorted(word_set)

    def findMatchedBracket(self, expression, start_pos):
        bracketCount = 0
        pos = start_pos + 1
        while pos < len(expression):
            if expression[pos] == '{':
                bracketCount += 1
            elif expression[pos] == '}':
                if bracketCount == 0:
                    return pos
                bracketCount -= 1
            pos += 1
        return None

print(Solution().expand("{a,b}{c{d,e}}"))
print(Solution().expand("{{a,z},a{b,c},{ab,z}}"))