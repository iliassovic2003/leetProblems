var isValid = function(s) {
    let stack = [];
    
    for (let char of s)
    {
        if (char === '(' || char === '{' || char === '[')
            stack.push(char);
        else
        {
            if (stack.length === 0)
                return false;
            
            let top = stack[stack.length - 1];
            if ((char === ')' && top === '(') ||
                (char === '}' && top === '{') ||
                (char === ']' && top === '['))
                    stack.pop();
            else
                return false;
        }
    }
    
    return stack.length === 0;
};