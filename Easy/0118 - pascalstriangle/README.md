# 118. Pascal's Triangle 🔺

<div align="center">

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-5CB85C?style=for-the-badge&logo=leetcode&logoColor=white)

</div>

## 📖 Problem Overview

Given an integer `numRows`, return the first `numRows` of **Pascal's triangle**.

In Pascal's triangle, each number is the sum of the two numbers directly above it.

```
        1
       1 1
      1 2 1
     1 3 3 1
    1 4 6 4 1
```

> 💡 **Pattern Recognition:** Each row starts and ends with 1, and interior values are the sum of the two values above.

---

## 🎯 Examples

### Example 1
**Input:** `numRows = 5`  
**Output:** `[[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]`  
**Explanation:** 
```
Row 0:           1
Row 1:         1   1
Row 2:       1   2   1
Row 3:     1   3   3   1
Row 4:   1   4   6   4   1
```

### Example 2  
**Input:** `numRows = 1`  
**Output:** `[[1]]`  
**Explanation:** Only the first row of Pascal's triangle

---

## 🔒 Constraints

<div align="center">

`1 ≤ numRows ≤ 30`

</div>

---

## 🧩 Approach & Strategy

### ⚡ Key Insights

| Aspect | Strategy |
|--------|----------|
| **Row Structure** | Row `i` has `i+1` elements (row 0 has 1 element, row 1 has 2, etc.) |
| **Edge Elements** | First and last elements are always 1 |
| **Interior Elements** | `triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j]` |
| **Building Pattern** | Each row depends only on the previous row |

### 🔄 Algorithm Steps

1. **Initialize Triangle** - Create a 2D vector with `numRows` rows

2. **Process Each Row** (i from 0 to numRows-1):
   - Resize current row to have `i+1` elements
   - Set first element `triangle[i][0] = 1`
   - Set last element `triangle[i][i] = 1`
   - Calculate interior elements using the formula

3. **Calculate Interior Values** (j from 1 to i-1):
   - `triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j]`

---

## 📊 Complexity Analysis

| Metric | Complexity | Explanation |
|--------|------------|-------------|
| **Time** | O(numRows²) | Generate 1+2+3+...+numRows = numRows*(numRows+1)/2 elements |
| **Space** | O(numRows²) | Store the entire triangle (output space) |

**Note:** Space complexity is O(1) if we don't count the output, as we only use a constant amount of extra variables.

---

## 🛠️ Solution Features

### ✅ Strengths
- **Dynamic Programming** - Builds solution using previously computed rows
- **Optimal** - Cannot be faster than O(n²) since we must generate n² elements
- **Clean Logic** - Separates edge cases (first/last) from general case
- **Space Efficient** - No extra data structures beyond the result

---

## 📝 Notes & Observations

### 🎓 Mathematical Properties

Pascal's Triangle has many fascinating properties:

1. **Binomial Coefficients**: Element at position (n, k) = C(n, k) = n! / (k! * (n-k)!)
2. **Row Sums**: Sum of row n = 2ⁿ (e.g., row 3: 1+3+3+1 = 8 = 2³)
3. **Symmetry**: Triangle is symmetric (triangle[i][j] = triangle[i][i-j])
4. **Fibonacci**: Sum of diagonal elements gives Fibonacci numbers
5. **Powers of 11**: Reading rows as numbers gives powers of 11 (1, 11, 121, 1331...)

### 🔢 Step-by-Step Example (numRows = 4)

```
i=0, j=none  →  [1]
i=1, j=none  →  [1, 1]
i=2, j=1     →  [1, 1+1=2, 1]
i=3, j=1,2   →  [1, 1+2=3, 2+1=3, 1]
```

### 🚀 Alternative Approaches

1. **Recursion** - Compute each value recursively using C(n,k) = C(n-1,k-1) + C(n-1,k)
2. **Formula-Based** - Calculate binomial coefficients directly using factorial formula
3. **Space-Optimized** - Generate only current row using previous row (if we don't need full triangle)

### 💭 Key Observations

- **No Edge Cases**: Works correctly for numRows = 1 (returns [[1]])
- **In-Place Building**: Each row is built independently once previous rows exist
- **Zero Indexing**: Row i has index from 0 to i, containing i+1 elements
- **Efficient Initialization**: Using `resize()` and simultaneous assignment for edges

### ⚠️ Common Pitfalls

- Forgetting that row `i` needs `i+1` elements (not `i`)
- Off-by-one errors in loop boundaries
- Not handling the edge elements (first and last) separately
- Trying to access `triangle[i-1][j]` when `j >= i` (out of bounds)

---

## 🎨 Visual Pattern Recognition

```
Symmetry:           Binomial Coefficients:
    1                   C(0,0)
   1 1                C(1,0) C(1,1)
  1 2 1             C(2,0) C(2,1) C(2,2)
 1 3 3 1          C(3,0) C(3,1) C(3,2) C(3,3)
1 4 6 4 1       C(4,0) C(4,1) C(4,2) C(4,3) C(4,4)
```

---

## 🔗 Related Problems

- **119. Pascal's Triangle II** - Return only the kth row
- **Binomial Coefficients** - Mathematical foundation
- **Combinations** - Related to combinatorics

---

### 🎯 Solved In

<div align="center">

![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Java](https://img.shields.io/badge/Java-ED8B00?style=for-the-badge&logo=java&logoColor=white)
![Python](https://img.shields.io/badge/Python-3776AB?style=for-the-badge&logo=python&logoColor=white)
![JavaScript](https://img.shields.io/badge/JavaScript-F7DF1E?style=for-the-badge&logo=javascript&logoColor=black)

</div>

---

<div align="center">

⭐ **"Mathematics is the music of reason"** - James Joseph Sylvester


---

**Last Solved:** 📅 2024-12-23  

</div>