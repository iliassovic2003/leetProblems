# 58. Length of Last Word 📏

<div align="center">

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-5CB85C?style=for-the-badge&logo=leetcode&logoColor=white)

</div>

## 📖 Problem Overview

Given a string consisting of words and spaces, return the length of the **last word** in the string. A word is defined as a maximal substring consisting of non-space characters only.

---

## 🎯 Examples

### Example 1
**Input:** `s = "Hello World"`  
**Output:** `5`  
**Explanation:** The last word is "World" with length 5

### Example 2  
**Input:** `s = "   fly me   to   the moon  "`  
**Output:** `4`  
**Explanation:** The last word is "moon" with length 4 (trailing spaces ignored)

### Example 3
**Input:** `s = "luffy is still joyboy"`  
**Output:** `6`  
**Explanation:** The last word is "joyboy" with length 6

---

## 🔒 Constraints

<div align="center">

`1 <= s.length <= 10⁴`  
`s consists of only English letters and spaces ' '`  
`There will be at least one word in s`

</div>

---

## 🧩 Approach & Strategy

### 🎯 Key Insight

We can solve this efficiently by **traversing from the end** of the string, skipping trailing spaces, then counting characters until we hit another space or the beginning.

### ⚡ Solution Approaches

| Approach | Method | Time | Space |
|----------|--------|------|-------|
| **Built-in** | Split and take last word | O(n) | O(n) |
| **Reverse Traverse** | Scan from end | O(n) | O(1) |
| **Two Pointers** | Find word boundaries | O(n) | O(1) |

### 🔄 Algorithm Steps (Optimal - Reverse Traverse)

1. **Start from end** - Initialize pointer at last index
2. **Skip trailing spaces** - Move left while encountering spaces
3. **Count word length** - Count non-space characters
4. **Return count** - Once space/start reached, return length

---

## 📊 Complexity Analysis

| Metric | Complexity | Explanation |
|--------|------------|-------------|
| **Time** | O(n) | Single pass from end (worst case full string) |
| **Space** | O(1) | Only using counter variables |

*Note: Built-in split approach uses O(n) space for array*

---

## 💡 Critical Observations

- **Trailing spaces** must be handled - they don't affect the last word
- **Single pass from end** is more efficient than splitting entire string
- **Early termination** possible once word is found
- **No edge cases** with empty strings due to constraint guarantees
- **Reverse iteration** avoids processing entire string in many cases

### 🎯 Solved In

<div align="center">

![Java](https://img.shields.io/badge/Java-ED8B00?style=for-the-badge&logo=java&logoColor=white)
![Python](https://img.shields.io/badge/Python-3776AB?style=for-the-badge&logo=python&logoColor=white)
![JavaScript](https://img.shields.io/badge/JavaScript-F7DF1E?style=for-the-badge&logo=javascript&logoColor=black)
![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)

</div>

---

<div align="center">

Last Solved: 📅 2024-01-26  
Pattern: String Manipulation

</div>