var convertToTitle = function(columnNumber)
{
    let result = "";
    let reps;
    let remainder;
    
    while (columnNumber > 0)
    {
        reps = Math.floor(columnNumber / 26);
        remainder = columnNumber % 26;
        
        if (remainder == 0) {
            result = 'Z' + result;
            columnNumber = reps - 1;
        }
        else {
            result = String.fromCharCode('A'.charCodeAt(0) + remainder - 1) + result;
            columnNumber = reps;
        }
    }
    
    return result;
};