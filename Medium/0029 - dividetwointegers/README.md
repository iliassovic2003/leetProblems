# 29. Divide Two Integers 🔍

<div align="center">

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)

</div>

## 📖 Problem Overview

Given two integers `dividend` and `divisor`, divide two integers without using multiplication, division, and mod operators. The integer division should truncate toward zero (remove fractional part). Handle 32-bit integer overflow cases by clamping the result to the 32-bit signed integer range.

### Key Constraints:
- ❌ Cannot use: `*`, `/`, `%` operators
- ✅ Must handle: Integer overflow cases
- ✅ Must truncate: Toward zero (not floor division)
- ✅ Range: `[-2³¹, 2³¹ - 1]`

---

## 🎯 Examples

### Example 1
**Input:** `dividend = 10`, `divisor = 3`  
**Output:** `3`  
**Explanation:** `10/3 = 3.333...` truncated to `3`

### Example 2  
**Input:** `dividend = 7`, `divisor = -3`  
**Output:** `-2`  
**Explanation:** `7/-3 = -2.333...` truncated to `-2`

### Example 3
**Input:** `dividend = -2147483648`, `divisor = -1`  
**Output:** `2147483647`  
**Explanation:** Would overflow 32-bit integer, so return `INT_MAX`

---

## 🔒 Constraints

<div align="center">

`-2³¹ <= dividend, divisor <= 2³¹ - 1`  
`divisor != 0`

</div>

---

## 🧩 Approach & Strategy

### ⚡ Key Insights

| Aspect | Handling Strategy |
|--------|------------------|
| **No Division Operator** | Use bit manipulation and subtraction |
| **Overflow Handling** | Special case: `INT_MIN / -1 = INT_MAX` |
| **Sign Handling** | Track result sign separately |
| **Efficiency** | Exponential search with bit shifting |

### 🔄 Algorithm Strategies

| Strategy | Time Complexity | Space Complexity | Pros & Cons |
|----------|----------------|------------------|-------------|
| **Repeated Subtraction** | O(dividend/divisor) | O(1) | Simple but inefficient for large numbers |
| **Bit Manipulation** | O(log dividend) | O(1) | Optimal for large values |
| **Exponential Search** | O(log² dividend) | O(1) | Most practical approach |

---

## 💡 Core Concepts

### Mathematical Insight
- **Division as repeated subtraction**: `a / b` = how many times we can subtract `b` from `a`
- **Bit shifting for efficiency**: `a << 1` = `a * 2`
- **Sign handling**: Result sign = `(dividend < 0) XOR (divisor < 0)`

### Critical Edge Cases
1. **Overflow**: `INT_MIN / -1` exceeds `INT_MAX`
2. **Zero divisor**: Constrained to be non-zero
3. **Negative numbers**: Handle sign carefully
4. **Boundary values**: `INT_MIN` and `INT_MAX`

---

## 📊 Complexity Analysis

### Bit Manipulation Approach
| Metric | Complexity | Explanation |
|--------|------------|-------------|
| **Time** | O(log dividend) | Each iteration reduces problem size significantly |
| **Space** | O(1) | Only constant extra space used |

### Exponential Search Approach
| Metric | Complexity | Explanation |
|--------|------------|-------------|
| **Time** | O(log² dividend) | Nested loops but efficient reduction |
| **Space** | O(1) | Constant space complexity |

---

## 🧪 Test Cases to Consider

| Scenario | Input | Expected Output | Reason |
|----------|-------|----------------|--------|
| Normal Case | `10, 3` | `3` | Basic division |
| Negative Result | `7, -3` | `-2` | Mixed signs |
| Overflow | `-2147483648, -1` | `2147483647` | INT_MIN / -1 > INT_MAX |
| Maximum Values | `2147483647, 1` | `2147483647` | INT_MAX division |
| Minimum Values | `-2147483648, 1` | `-2147483648` | INT_MIN division |
| Large Divisor | `10, 10` | `1` | Equal values |
| Small Divisor | `1, 2` | `0` | Result < 1 |

---

## 🎯 Problem-Solving Techniques

### Step-by-Step Reasoning
1. **Handle overflow case first** - `INT_MIN / -1`
2. **Determine result sign** - XOR of input signs
3. **Work with absolute values** - Convert to positive
4. **Use bit manipulation** - Efficient doubling/halving
5. **Accumulate quotient** - Track multiples

### Common Pitfalls
- ❌ Forgetting overflow case `INT_MIN / -1`
- ❌ Incorrect sign handling with negative numbers
- ❌ Using slow repeated subtraction for large numbers
- ❌ Not considering boundary values

### Optimization Guidelines
- ✅ Use bit shifting instead of multiplication
- ✅ Handle edge cases upfront
- ✅ Use exponential search for efficiency
- ✅ Track sign separately from calculation

---

## 📝 Notes

- The key insight is that division can be implemented using subtraction and bit manipulation
- Bit shifting (`<<`) is equivalent to multiplying by 2, which is allowed
- Always consider the extreme boundary values in integer problems
- The time complexity is logarithmic due to the exponential reduction in problem size

---

## 🎯 Solved In
<div align="center">

![Python](https://img.shields.io/badge/Python-3776AB?style=for-the-badge&logo=python&logoColor=white)
![Java](https://img.shields.io/badge/Java-ED8B00?style=for-the-badge&logo=java&logoColor=white)
![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![JavaScript](https://img.shields.io/badge/JavaScript-F7DF1E?style=for-the-badge&logo=javascript&logoColor=black)

</div>

---

<div align="center">

**Problem Type:** Bit Manipulation • Mathematical

**Last Updated:** 📅 2025-01-21

</div>