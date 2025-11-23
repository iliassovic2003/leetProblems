var lengthOfLongestSubstring = function(s)
{
    let length = 0;
    let start = 0;

    const mySet = new Map();
    for (let i = 0; i < s.length; i++)
    {
        if (mySet.has(s[i]))
            start = Math.max(start, mySet.get(s[i]) + 1);
        
        mySet.set(s[i], i);
        length = Math.max(length, i - start + 1);
    }
    return length;
};