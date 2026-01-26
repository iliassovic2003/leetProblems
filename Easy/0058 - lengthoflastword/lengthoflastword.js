var lengthOfLastWord = function(s)
{
    let     k = 0;
    let    flag = 0;

    for (let i = s.length - 1; i >= 0; i--)
    {
        if (s[i] == ' ' && !flag)
            continue;
        if (s[i] != ' ')
        {
            if (!flag)
                flag = 1;
            k++;
        }
        else
            break;
    }

    return k;    
};