class Solution {
    public boolean isMatch(String s, String p) {
        int x = s.length(), y = p.length();
        
        boolean[][] arr = new boolean[x + 1][y + 1];

        arr[0][0] = true;                   //  typical empty string

        for (int i = 2; i <= y; i++)        //  empty string with a sequence of *chars
            if (p.charAt(i - 1) == '*')
                arr[0][i] = arr[0][i - 2];

        for (int i = 1; i <= x; i++) {
            for (int j = 1; j <= y; j++) {
                if (p.charAt(j - 1) == '*')  //  zero or more matches
                    arr[i][j] = arr[i][j - 2] || (arr[i - 1][j] && (s.charAt(i - 1) == p.charAt(j - 2) || p.charAt(j - 2) == '.'));
                else                        //  simple since there is no *
                    arr[i][j] = arr[i - 1][j - 1] && (s.charAt(i - 1) == p.charAt(j - 1) || p.charAt(j - 1) == '.');
            }
        }

        return arr[x][y];
    }
}