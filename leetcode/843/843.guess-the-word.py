#
# @lc app=leetcode id=843 lang=python3
#
# [843] Guess the Word
#
# """
# This is Master's API interface.
# You should not implement it, or speculate about its implementation
# """
#class Master:
#    def guess(self, word):
#        """
#        :type word: str
#        :rtype int
#        """

class Solution:
    def matchedOfWord(self, word1, word2):
        matched = 0
        for i in range(len(word1)):
            if word1[i] == word2[i]:
                matched += 1
        return matched

    def getBestWord(self, wordlist):
        """
        :type wordlist: List[Str]
        :rtype: None
        """
        if len(wordlist) == 0:
            return None
        if len(wordlist) == 1:
            return wordlist[0]
        bestBucketSize = len(wordlist)
        bestWord = wordlist[0]
        for selectedWord in wordlist:
            buckets = [0] * (len(wordlist[0]) + 1)
            for word in wordlist:
                distance = self.matchedOfWord(selectedWord, word)
                buckets[distance] += 1
                if buckets[distance] > bestBucketSize:
                    break
            else:                
                bucketSize = max(buckets)
                if bucketSize < bestBucketSize:
                    bestBucketSize = bucketSize
                    bestWord = selectedWord
        # print("bucket size = ", bestBucketSize)
        return bestWord

    def findSecretWord(self, wordlist, master):
        """
        :type wordlist: List[Str]
        :type master: Master
        :rtype: None
        """
        length = len(wordlist[0])
        while wordlist:
            bestWord = self.getBestWord(wordlist)
            matched = master.guess(bestWord)
            print(bestWord, matched)
            if length == matched:
                return
            wordlist = [word for word in wordlist if self.matchedOfWord(word, bestWord) == matched]
            # print(wordlist)

