class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        length = 0
        start = 0

        mySet = {}
        for i, char in enumerate(s) :
            if char in mySet :
                start = max(start, mySet[char] + 1)
            
            mySet[char] = i
            length = max(length, i - start + 1)
        return length