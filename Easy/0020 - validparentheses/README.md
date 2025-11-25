# 20. Valid Parentheses 🎯

<div align="center">

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-5CB85C?style=for-the-badge&logo=leetcode&logoColor=white)

</div>

## 📖 Problem Overview

Given a string `s` containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.

**Validation Rules:**
1. Open brackets must be closed by the same type of brackets
2. Open brackets must be closed in the correct order
3. Every close bracket has a corresponding open bracket of the same type

---

## 🎯 Examples

### Example 1
**Input:** `s = "()"`  
**Output:** `true`

### Example 2
**Input:** `s = "()[]{}"`  
**Output:** `true`

### Example 3
**Input:** `s = "(]"`  
**Output:** `false`

### Example 4
**Input:** `s = "([])"`  
**Output:** `true`

### Example 5
**Input:** `s = "([)]"`  
**Output:** `false`

---

## 🔒 Constraints

<div align="center">

`1 <= s.length <= 10⁴`  
`s` consists of parentheses only `'()[]{}'`

</div>

---

## 🧩 Approach & Strategy

### ⚡ Key Insights

| Aspect | Handling Strategy |
|--------|------------------|
| **LIFO Nature** | Use stack data structure for bracket matching |
| **Opening vs Closing** | Push opening brackets, pop when matching closing bracket found |
| **Early Termination** | Return false immediately on mismatch |
| **Final Validation** | Stack must be empty at end (all brackets matched) |

### 🔄 Algorithm Strategies

| Strategy | Time Complexity | Space Complexity | Implementation |
|----------|----------------|------------------|----------------|
| **Stack with Map Lookup** | O(n) | O(n) | ✅ Most Readable |
| **Stack with Direct Comparison** | O(n) | O(n) | ✅ Efficient |
| **Deque (Java Optimization)** | O(n) | O(n) | ✅ Better Performance |

---

## 📊 Complexity Analysis

### Optimal Solution

| Metric | Complexity | Explanation |
|--------|------------|-------------|
| **Time** | O(n) | Each character processed exactly once |
| **Space** | O(n) | Worst-case stack size (all opening brackets) |

---

# Algorithm Analysis & Implementation Guide

## 💡 Core Concepts

### Stack-Based Approach
- **LIFO Principle**: Last opened bracket must be first closed
- **Push Opening Brackets**: Add `(, {, [` to stack
- **Pop on Match**: When closing bracket matches top, remove from stack
- **Validation Check**: Stack empty at end = valid parentheses

### Data Structure Choices
| Language | Recommended Structure | Why |
|----------|---------------------|-----|
| **C++** | `stack<char>` | Native stack implementation |
| **Java** | `Deque<Character>` | Better performance than `Stack` |
| **Python** | `list` | Native list works as stack |
| **JavaScript** | `Array` | Native array with push/pop |

---

## 🧪 Test Cases to Consider

| Scenario | Input | Expected Output | Explanation |
|----------|-------|----------------|-------------|
| Simple Pair | `"()"` | `true` | Basic valid case |
| Mixed Types | `"()[]{}"` | `true` | Different bracket types |
| Mismatch | `"(]"` | `false` | Wrong closing bracket |
| Nested Valid | `"([{}])"` | `true` | Properly nested |
| Interleaved Invalid | `"([)]"` | `false` | Wrong nesting order |
| Single Opening | `"("` | `false` | Unclosed bracket |
| Single Closing | `")"` | `false` | No opening bracket |
| Empty String | `""` | `true` | No brackets to validate |
| Complex Valid | `"{[]}({})"` | `true` | Multiple valid groups |

---

## 🎯 Problem-Solving Techniques

### Step-by-Step Reasoning

#### Approach: Stack-Based Validation
1. **Initialize Stack**: Prepare empty stack for bracket tracking
2. **Iterate Through String**: Process each character sequentially
3. **Handle Opening Brackets**: Push onto stack
4. **Handle Closing Brackets**:
   - If stack empty → invalid (no matching opening)
   - If top doesn't match → invalid (wrong bracket type)
   - If matches → pop from stack
5. **Final Check**: Stack must be empty (all brackets matched)

### Common Pitfalls
- ❌ Not checking if stack is empty before popping
- ❌ Forgetting to handle the case where stack is not empty at end
- ❌ Using wrong data structure (Queue instead of Stack)
- ❌ Not considering empty string as valid case
- ❌ Incorrect bracket matching logic

---

## 📈 Performance Comparison

| Implementation | Time | Space | Readability |
|----------------|------|-------|-------------|
| **C++ Stack** | O(n) | O(n) | ✅ Excellent |
| **Java Deque** | O(n) | O(n) | ✅ Best Performance |
| **Python List** | O(n) | O(n) | ✅ Pythonic |
| **JavaScript Array** | O(n) | O(n) | ✅ Clean |

## 💡 Key Insights

- **Stack is Perfect**: LIFO behavior matches bracket nesting requirements
- **Early Termination**: Return false immediately on any mismatch
- **Empty Stack Check**: Crucial for handling closing brackets without openings
- **Final Validation**: Must ensure stack is empty at end
- **Multiple Languages**: Same algorithm, different stack implementations

> **Pro Tip**: The "push expected closing bracket" pattern (used in Java/JS examples) makes the code cleaner by reducing comparison logic.

## 📝 Related Problems

- **32. Longest Valid Parentheses**: Extension with finding maximum valid length
- **22. Generate Parentheses**: Generating all valid combinations
- **301. Remove Invalid Parentheses**: Removing minimum to make valid
- **678. Valid Parenthesis String**: Handling wildcard characters
- **1249. Minimum Remove to Make Valid Parentheses**: Similar validation with removal

## 🎯 Solved In

<div align="center">

![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Java](https://img.shields.io/badge/Java-ED8B00?style=for-the-badge&logo=java&logoColor=white)
![Python](https://img.shields.io/badge/Python-3776AB?style=for-the-badge&logo=python&logoColor=white)
![JavaScript](https://img.shields.io/badge/JavaScript-F7DF1E?style=for-the-badge&logo=javascript&logoColor=black)

</div>

<div align="center">

**Problem Type:** Stack • String Processing • LIFO Validation

**Last Updated:** 📅 2025-01-25

**Key Technique:** Stack-based bracket matching with early termination

</div>