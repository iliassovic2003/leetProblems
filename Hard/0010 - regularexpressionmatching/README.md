# 10. Regular Expression Matching 🔥

<div align="center">

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-FF375F?style=for-the-badge&logo=leetcode&logoColor=white)

</div>

## 📖 Problem Overview

Implement regular expression matching with support for `.` (any single character) and `*` (zero or more of preceding element). The matching must cover the **entire input string**.

---

## 🎯 Examples

### Example 1
**Input:** `s = "aa", p = "a"`  
**Output:** `false`  
**Explanation:** Pattern "a" doesn't match entire string "aa"

### Example 2  
**Input:** `s = "aa", p = "a*"`  
**Output:** `true`  
**Explanation:** '*' means zero or more 'a', so repeating 'a' once gives "aa"

### Example 3
**Input:** `s = "ab", p = ".*"`  
**Output:** `true`  
**Explanation:** ".*" means zero or more of any character

---

## 🔒 Constraints

<div align="center">

`1 <= s.length <= 20`  
`1 <= p.length <= 20`  
`s contains only lowercase English letters`  
`p contains only lowercase English letters, '.', and '*'`  
`Each '*' has a previous valid character`

</div>

---

## 🧩 Approach & Strategy

### 🎯 Key Insight
We use **Dynamic Programming** where `dp[i][j]` represents whether `s[0..i-1]` matches `p[0..j-1]`. We start indexing from 1 to handle empty string cases naturally.

### ⚡ Pattern Cases

| Case | DP Transition | Explanation |
|------|---------------|-------------|
| **Normal Char** | `dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1])` | Characters must match exactly |
| **Dot '.'** | `dp[i][j] = dp[i-1][j-1]` | Dot matches any single character |
| **Star '*'** | `dp[i][j] = dp[i][j-2] OR (dp[i-1][j] && char_match)` | Zero OR one+ occurrences |

### 🔄 Algorithm Steps

1. **Initialize DP Table** - Create `(m+1) x (n+1)` table, all `false`
2. **Base Case** - `dp[0][0] = true` (empty matches empty)
3. **Handle Empty String** - Patterns like `a*`, `a*b*` can match empty string
4. **Fill Table** - Process each character combination:
   - If `*`: consider zero occurrences OR extend previous match
   - Else: require exact match or dot match
5. **Return Result** - `dp[m][n]` contains final answer

---

## 📊 Complexity Analysis

| Metric | Complexity | Explanation |
|--------|------------|-------------|
| **Time** | O(m × n) | Process each cell in DP table once |
| **Space** | O(m × n) | Storage for DP table |

---

## 💡 Critical Observations

- **Indexing starts at 1** in DP table to handle empty strings naturally
- **Star handling has two cases**: zero occurrences (skip pattern) OR one+ occurrences (extend match)
- **Overlapping subproblems** make DP ideal - same patterns recur
- **Bottom-up approach** builds solution from smallest to largest subproblems

---

## 📝 Key Takeaways

- DP is natural fit for regex matching due to overlapping subproblems
- Start indexing from 1 simplifies empty string handling
- Star operator has dual nature - can be skipped or used repeatedly
- Bottom-up DP efficiently builds solution from base cases
- Constraint bounds allow DP solution to be efficient

<div align="center">

Last Solved: 📅 2024-01-15
Pattern: Dynamic Programming

</div> ```
