class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        k = 0
        flag = 0

        for i in range(len(s) - 1, -1, -1) :
            if (s[i] == ' ' and flag == 0) :
                continue
            if (s[i] != ' ') :
                if (flag == 0) :
                    flag = 1
                k += 1
            else :
                break

        return k