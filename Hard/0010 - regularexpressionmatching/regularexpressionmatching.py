class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        x = len(s)
        y = len(p)

        arr = [None] * (x + 1)
        for i in range(x + 1):
            arr[i] = [False] * (y + 1)

        arr[0][0] = True;                    #  typical empty string

        for i in range(2, y + 1):            #  empty string with a sequence of *chars
            if (p[i - 1] == '*'):
                arr[0][i] = arr[0][i - 2]

        for i in range(1, x + 1):
            for j in range(1, y + 1):
                if (p[j - 1] == '*'):        #  zero or more matches
                    arr[i][j] = arr[i][j - 2] or (arr[i - 1][j] and (s[i - 1] == p[j - 2] or p[j - 2] == '.'))
                else:                        #  simple since there is no *
                    arr[i][j] = arr[i - 1][j - 1] and (s[i - 1] == p[j - 1] or p[j - 1] == '.')

        return arr[x][y]