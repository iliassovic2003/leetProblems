# 69. Sqrt(x) 🔢

<div align="center">

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-5CB85C?style=for-the-badge&logo=leetcode&logoColor=white)

</div>

## 📖 Problem Overview

Given a non-negative integer `x`, return the square root of `x` rounded down to the nearest integer. The returned integer should be non-negative as well.

**Important:** You must not use any built-in exponent function or operator.
- ❌ Do not use `pow(x, 0.5)` in C++
- ❌ Do not use `x ** 0.5` in Python

The task is to find the largest integer `k` such that `k² ≤ x`.

---

## 🎯 Examples

### Example 1
**Input:** `x = 4`  
**Output:** `2`  
**Explanation:** The square root of 4 is 2, so we return 2.

### Example 2
**Input:** `x = 8`  
**Output:** `2`  
**Explanation:** The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.

### Example 3
**Input:** `x = 0`  
**Output:** `0`  
**Explanation:** The square root of 0 is 0.

---

## 🔒 Constraints

<div align="center">

`0 <= x <= 2³¹ - 1`

</div>

---

## 🧩 Approach & Strategy

### ⚡ Key Insights

| Aspect | Handling Strategy |
|--------|------------------|
| **Monotonic Property** | If k² ≤ x, then all values < k also satisfy this |
| **Search Space** | Answer lies in range [0, x], optimizable to [0, x/2+1] |
| **Overflow Risk** | Use division (median ≤ x/median) instead of multiplication |
| **Integer Result** | Natural floor operation from integer division |

### 🔄 Algorithm Strategies

| Strategy | Time Complexity | Space Complexity | Best For |
|----------|----------------|------------------|----------|
| **Binary Search** | O(log x) | O(1) | Most intuitive and efficient |
| **Newton's Method** | O(log log x) | O(1) | Advanced optimization |
| **Linear Search** | O(√x) | O(1) | Not recommended |

---

## 📊 Complexity Analysis

### Binary Search Approach (Recommended)

| Metric | Complexity | Explanation |
|--------|------------|-------------|
| **Time** | O(log x) | Halving search space each iteration |
| **Space** | O(1) | Only using constant extra space |

### Newton's Method Approach (Advanced)

| Metric | Complexity | Explanation |
|--------|------------|-------------|
| **Time** | O(log log x) | Quadratic convergence rate |
| **Space** | O(1) | Only using constant extra space |

---

# Algorithm Analysis & Implementation Guide

## 💡 Core Concepts

### Mathematical Insight
- **Integer Square Root**: Find largest integer `k` where `k² ≤ x`
- **Search Bounds**: For x ≥ 2, answer is always in range [1, x/2]
- **Exponential Relationship**: Square function grows exponentially
- **Overflow Prevention**: `median * median` can overflow; use `median ≤ x / median` instead

### Algorithmic Patterns
- **Binary Search**: Efficiently narrow down search space
- **Invariant Maintenance**: Track last valid answer throughout search
- **Boundary Handling**: Special treatment for edge cases (0, 1)
- **Comparison Strategy**: Use division to avoid integer overflow

### Optimization Opportunities
- **Reduced Search Space**: Start from [0, x/2] for x ≥ 2
- **Early Exit**: Handle 0 and 1 immediately
- **Newton's Method**: Faster convergence for very large numbers
- **Long Data Type**: Use for intermediate calculations if needed

---

## 🧪 Test Cases to Consider

| Scenario | Input | Expected Output | Explanation |
|----------|-------|----------------|-------------|
| Perfect Square | `x = 4` | `2` | √4 = 2 exactly |
| Round Down | `x = 8` | `2` | √8 = 2.828..., floor = 2 |
| Edge: Zero | `x = 0` | `0` | √0 = 0 |
| Edge: One | `x = 1` | `1` | √1 = 1 |
| Large Perfect Square | `x = 144` | `12` | √144 = 12 exactly |
| Large Value | `x = 2147395600` | `46340` | Near max constraint |
| Small Non-Square | `x = 2` | `1` | √2 = 1.414..., floor = 1 |
| Medium Value | `x = 100` | `10` | √100 = 10 exactly |

---

## 🎯 Problem-Solving Techniques

### Step-by-Step Reasoning

#### Binary Search Strategy
1. **Initialize Bounds**: Set `start = 0` (or 1) and `end = x` (or x/2 for optimization)
2. **Binary Search Loop**: Continue while `start ≤ end`
3. **Calculate median point**: Use `median = start + (end - start) / 2` to avoid overflow
4. **Compare Safely**: Check if `median ≤ x / median` instead of `median * median ≤ x`
5. **Update Search Space**: Adjust bounds based on comparison result
6. **Track Valid Answer**: Keep the last `median` where condition was satisfied

#### Newton's Method Strategy
1. **Start with Guess**: Initialize with `x` or `x/2`
2. **Iterative Refinement**: Apply formula `next = (current + x/current) / 2`
3. **Check Convergence**: Continue until `guess² ≤ x`
4. **Return Integer**: Cast result to integer type

### Common Pitfalls
- ❌ Integer overflow when computing `median * median` (use division instead)
- ❌ Off-by-one errors in binary search bounds
- ❌ Forgetting to handle edge cases (0, 1)
- ❌ Using floating-point operations (violates constraints)
- ❌ Not tracking the answer during binary search
- ❌ Incorrect termination condition

### Optimization Guidelines
- ✅ Use `median ≤ x/median` to prevent overflow
- ✅ Optimize search space: `end = x/2` for x ≥ 2
- ✅ Handle 0 and 1 as special cases upfront
- ✅ Use `long` or `long long` for safety in some languages
- ✅ Consider Newton's method for advanced optimization

---

## 🔍 Visual Example

```
Finding sqrt(8) using Binary Search:

Initial: start=1, end=4
┌────────────────┐
│ 1   2   3   4  │
└────────────────┘

Step 1: median=2
  2 ≤ 8/2 → 2 ≤ 4 ✓
  result = 2, search end [3,4]

Step 2: median=3
  3 ≤ 8/3 → 3 ≤ 2 ✗
  search start [3,2]

start > end → STOP
Final Answer: 2
```

---

## 💡 Key Insights

1. **Binary Search Fits Perfectly**: Monotonic property of squares makes binary search ideal
2. **Overflow is Real**: Always use division comparison, never multiplication
3. **Answer Tracking**: Must save last valid answer before overshooting
4. **Edge Cases Critical**: 0 and 1 deserve special handling
5. **Search Space Reduction**: Can halve initial search space safely
6. **Integer Properties**: Floor division naturally gives rounded-down behavior

---

## 🎯 Solved In

<div align="center">

![Java](https://img.shields.io/badge/Java-ED8B00?style=for-the-badge&logo=java&logoColor=white)
![Python](https://img.shields.io/badge/Python-3776AB?style=for-the-badge&logo=python&logoColor=white)
![JavaScript](https://img.shields.io/badge/JavaScript-F7DF1E?style=for-the-badge&logo=javascript&logoColor=black)
![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)

</div>

---

<div align="center">

**Problem Type:** Binary Search • Mathematical

**Last Updated:** 📅 2025-01-22

</div>