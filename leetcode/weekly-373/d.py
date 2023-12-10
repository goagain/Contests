from collections import defaultdict

vowels = set(['a', 'e', 'i', 'o', 'u'])

class Solution:
    def calculate_min_slide_window(self, k: int):
        for i in range(1, k+1):
            if i * i % k == 0:
                return i
            
    def beautifulSubstrings(self, s: str, k: int) -> int:
        slide_window = self.calculate_min_slide_window(k) * 2
        
        prefix_sum = [0]
        for i, c in enumerate(s):
            prefix_sum.append(prefix_sum[-1] + (1 if c in vowels else -1))
            
        ans = 0
        dp = [defaultdict(int) for _ in range(slide_window)]
        for i in range(len(prefix_sum)):
            bucket = i % slide_window
            if i + 1 >= slide_window:
                ans += dp[bucket][prefix_sum[i]]

            dp[bucket][prefix_sum[i]] += 1

        # print(dp)
        # print(cur)
        return ans
print(Solution().beautifulSubstrings("ab", 1))

print(Solution().beautifulSubstrings("abba", 1))
print(Solution().beautifulSubstrings("ab"*50000, 1))