# 168. Excel Sheet Column Title 📊

<div align="center">

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-5CB85C?style=for-the-badge&logo=leetcode&logoColor=white)

</div>

## 📖 Problem Overview

Given an integer `columnNumber`, return its corresponding column title as it appears in an Excel sheet.

Excel columns use a bijective base-26 numeration system with letters A-Z:

```
A → 1        Z → 26        AZ → 52
B → 2        AA → 27       BA → 53
C → 3        AB → 28       ...
...          ...           ZZ → 702
```

> 💡 **Key Insight:** This is like base-26 conversion, but with a twist - there's no zero! It's a bijective numeration.

---

## 🎯 Examples

### Example 1
**Input:** `columnNumber = 1`  
**Output:** `"A"`  
**Explanation:** First column in Excel

### Example 2  
**Input:** `columnNumber = 28`  
**Output:** `"AB"`  
**Explanation:** 
- 28 ÷ 26 = 1 remainder 2
- Remainder 2 → 'B'
- Quotient 1 → 'A'
- Result: "AB"

### Example 3
**Input:** `columnNumber = 701`  
**Output:** `"ZY"`  
**Explanation:**
- 701 ÷ 26 = 26 remainder 25
- Remainder 25 → 'Y'
- 26 ÷ 26 = 1 remainder 0
- Remainder 0 → 'Z' (special case!)
- Result: "ZY"

---

## 🔒 Constraints

<div align="center">

`1 ≤ columnNumber ≤ 2³¹ - 1`

</div>

---

## 🧩 Approach & Strategy

### ⚡ Key Insights

| Aspect | Strategy |
|--------|----------|
| **Number System** | Bijective base-26 (no zero, 1-indexed) |
| **Special Case** | When `remainder = 0`, it represents 'Z' (the 26th letter) |
| **Borrow Mechanism** | When remainder is 0, subtract 1 from quotient (like borrowing) |
| **Direction** | Build string from right to left (least significant to most) |

### 🔄 Algorithm Steps

1. **Initialize Variables**
   - `result = ""` (empty string)
   - `reps` (quotient from division)
   - `remainder` (remainder from division)

2. **Process Each Digit** (while columnNumber > 0):
   - Calculate: `reps = columnNumber / 26`
   - Calculate: `remainder = columnNumber % 26`
   
   **If remainder == 0 (special case):**
   - Append 'Z' to result (represents 26)
   - Set `columnNumber = reps - 1` (borrow from next digit)
   
   **Else (normal case):**
   - Convert remainder to letter: `char('A' + remainder - 1)`
   - Set `columnNumber = reps`

3. **Return** the complete column title

### 💡 Why the Special Case for Remainder 0?

In standard base-26, remainder 0 would mean "no contribution," but in Excel's system:
- **26, 52, 78...** should give **Z, AZ, CZ...** not **?, A?, C?**
- When `remainder = 0`, it actually represents **'Z' (the 26th letter)**
- We must **"borrow"** by subtracting 1 from the quotient


---

## 📊 Complexity Analysis

| Metric | Complexity | Explanation |
|--------|------------|-------------|
| **Time** | O(log₂₆(n)) | Number of digits in base-26 representation |
| **Space** | O(log₂₆(n)) | Space for the result string |

**Note:** For maximum input (2³¹ - 1 ≈ 2.1 billion), this requires only ~7 iterations.

---

## 🛠️ Solution Features

### ✅ Strengths
- **Clear Logic** - Explicit handling of the remainder=0 special case
- **Intuitive** - Mirrors manual division process with borrowing
- **Efficient** - Logarithmic time complexity
- **Readable** - Separate paths for special case vs normal case


---

## 📝 Notes & Observations

### 🎓 Bijective Base-26 Explained

| Standard Base-26 | Excel's Bijective Base-26 |
|------------------|---------------------------|
| Uses digits 0-25 | Uses digits 1-26 |
| Has a zero | No zero representation |
| A=0, B=1, Z=25 | A=1, B=2, Z=26 |
| Not used in Excel | Used in Excel columns |


### 🔑 Key Concepts

1. **The Remainder 0 Problem**: In normal base conversion, remainder 0 means "nothing," but here it means the maximum digit (Z)
2. **The Borrowing Mechanism**: When remainder is 0, we must "borrow" 1 from the next higher digit
3. **Right-to-Left Construction**: We build the string from least significant to most significant digit
4. **1-Indexed Mapping**: `remainder - 1` adjusts from 1-indexed (1=A) to 0-indexed array position

### 🚀 Alternative Approaches

1. **Decrement-First Method**: Subtract 1 before division/modulo to avoid special case
   ```cpp
   columnNumber--;
   remainder = columnNumber % 26;
   columnNumber /= 26;
   ```

2. **Recursive Approach**: Recursively build the string
   ```cpp
    if (n == 0)
        return "";
    return convertToTitle((n-1)/26) + char('A' + (n-1)%26);
   ```

3. **String Reverse**: Build string backwards and reverse at the end

### 💭 Common Patterns

| Input Type | Pattern | Example |
|------------|---------|---------|
| Multiples of 26 | Always ends with Z | 26→Z, 52→AZ, 702→ZZ |
| Powers of 26 | All same letter | 1→A, 27→AA, 703→AAA |
| One less than power | All Z's | 26→Z, 702→ZZ, 18278→ZZZ |

### ⚠️ Common Pitfalls

- **Forgetting the special case**: Treating remainder 0 like a normal remainder
- **Not borrowing**: When remainder=0, forgetting to subtract 1 from quotient
- **Off-by-one errors**: Confusing 0-indexed vs 1-indexed conversions
- **Integer overflow**: Not considering large inputs (though problem constraints guarantee valid int range)

---

## 🔗 Related Problems

- **171. Excel Sheet Column Number** - The reverse problem (convert "AB" → 28)
- **Base Conversion Problems** - General number system conversions
- **Bijective Numeration** - Mathematical concept behind this problem

---

### 🎯 Solved In

<div align="center">

![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Java](https://img.shields.io/badge/Java-ED8B00?style=for-the-badge&logo=java&logoColor=white)
![Python](https://img.shields.io/badge/Python-3776AB?style=for-the-badge&logo=python&logoColor=white)
![JavaScript](https://img.shields.io/badge/JavaScript-F7DF1E?style=for-the-badge&logo=javascript&logoColor=black)


**Last Solved:** 📅 2024-12-23  

---

</div>