var isMatch = function(s, p) {
    let x = s.length, y = p.length;
    let arr = new Array(x + 1);
    
    for (let i = 0; i <= x; i++)
        arr[i] = new Array(y + 1).fill(false);
    
    arr[0][0] = true;                   //  typical empty string

    for (let i = 2; i <= y; i++)        //  empty string with a sequence of *chars
        if (p[i - 1] == '*')
            arr[0][i] = arr[0][i - 2];

    for (let i = 1; i <= x; i++) {
        for (let j = 1; j <= y; j++) {
            if (p[j - 1] == '*')        //  zero or more matches
                arr[i][j] = arr[i][j - 2] || (arr[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
            else                        //  simple since there is no *
                arr[i][j] = arr[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
        }
    }

    return arr[x][y];
};