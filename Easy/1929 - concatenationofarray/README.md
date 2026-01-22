# 1929. Concatenation of Array 🎯

<div align="center">

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-5CB85C?style=for-the-badge&logo=leetcode&logoColor=white)

</div>

## 📖 Problem Overview

Given an integer array `nums` of length `n`, create an array `ans` of length `2n` where `ans[i] == nums[i]` and `ans[i + n] == nums[i]` for `0 <= i < n` (0-indexed).

Specifically, `ans` is the **concatenation of two `nums` arrays**.

Return the array `ans`.

---

## 🎯 Examples

### Example 1
**Input:** `nums = [1,2,1]`  
**Output:** `[1,2,1,1,2,1]`  
**Explanation:** The array ans is formed as follows:
- ans = [nums[0],nums[1],nums[2],nums[0],nums[1],nums[2]]
- ans = [1,2,1,1,2,1]

### Example 2
**Input:** `nums = [1,3,2,1]`  
**Output:** `[1,3,2,1,1,3,2,1]`  
**Explanation:** The array ans is formed as follows:
- ans = [nums[0],nums[1],nums[2],nums[3],nums[0],nums[1],nums[2],nums[3]]
- ans = [1,3,2,1,1,3,2,1]

### Example 3
**Input:** `nums = [5]`  
**Output:** `[5,5]`  
**Explanation:** Single element duplicated.

---

## 🔒 Constraints

<div align="center">

`n == nums.length`  
`1 <= n <= 1000`  
`1 <= nums[i] <= 1000`

</div>

---

## 🧩 Approach & Strategy

### ⚡ Key Insights

| Aspect | Handling Strategy |
|--------|------------------|
| **Array Duplication** | Simply append array to itself |
| **Result Size** | Always exactly 2n elements |
| **Element Order** | Preserve original order twice |
| **No Modifications** | Original array remains unchanged |

### 🔄 Algorithm Strategies

| Strategy | Time Complexity | Space Complexity | Best For |
|----------|----------------|------------------|----------|
| **Built-in Concatenation** | O(n) | O(n) | ✅ Simplest & Most Readable |
| **Pre-allocated Array Loop** | O(n) | O(n) | ✅ Explicit Control |
| **Two Separate Loops** | O(n) | O(n) | ✅ Clear Logic |
| **Single Loop with Modulo** | O(n) | O(n) | 🎓 Educational |

---

## 📊 Complexity Analysis

### All Approaches (Optimal)

| Metric | Complexity | Explanation |
|--------|------------|-------------|
| **Time** | O(n) | Must copy each element at least once |
| **Space** | O(n) | Result array requires 2n space |

> **Note:** Since we must create a new array of size 2n, O(n) space is unavoidable. All valid solutions have the same time and space complexity.

---

# Algorithm Analysis & Implementation Guide

## 💡 Core Concepts

### Mathematical Insight
- **Array Concatenation**: Joining arrays end-to-end
- **Index Mapping**: `ans[i] = nums[i % n]` for all i from 0 to 2n-1
- **Two Halves**: First half is nums, second half is also nums
- **No Data Transformation**: Elements copied as-is

### Algorithmic Patterns
- **Array Manipulation**: Basic array operations
- **Iteration**: Single or double pass through array
- **Index Arithmetic**: Using modulo for wrapping
- **Memory Allocation**: Pre-allocating result array

### Optimization Opportunities
- **Language Built-ins**: Use native concatenation methods when available
- **Minimize Allocations**: Pre-allocate result array to exact size
- **Single Pass**: Can fill both halves in one loop
- **Avoid Copying**: Direct assignment rather than intermediate arrays

---

## 🎯 Problem-Solving Techniques

### Step-by-Step Reasoning

#### Approach 1: Built-in Concatenation (Recommended ✅)
1. **Use Language Features**: Most languages have array/list concatenation
2. **Simple Syntax**: `nums + nums` or `nums.concat(nums)`
3. **Return Result**: One-line solution in many languages

**Why This Works:**
- ✅ Simplest and most readable
- ✅ Leverages optimized built-in methods
- ✅ Less prone to bugs
- ✅ Idiomatic code

#### Approach 2: Pre-allocated Array with Single Loop
1. **Create Result Array**: Allocate array of size 2n
2. **Iterate Once**: Loop from 0 to 2n-1
3. **Use Modulo**: `ans[i] = nums[i % n]`
4. **Return Result**: Already filled array

**Why This Works:**
- ✅ Single pass through data
- ✅ Clear index mapping logic
- ✅ Efficient memory usage

#### Approach 3: Two Separate Loops (Most Explicit)
1. **Create Result Array**: Allocate array of size 2n
2. **First Loop**: Copy nums[0..n-1] to ans[0..n-1]
3. **Second Loop**: Copy nums[0..n-1] to ans[n..2n-1]
4. **Return Result**: Fully populated array

**Why This Works:**
- ✅ Very clear and explicit
- ✅ Easy to understand for beginners
- ✅ No mathematical tricks needed

### Common Pitfalls
- ❌ Forgetting result array is size 2n, not n
- ❌ Off-by-one errors in loop boundaries
- ❌ Modifying original array instead of creating new one
- ❌ Incorrect index calculations
- ❌ Not handling single-element arrays

### Optimization Guidelines
- ✅ Use built-in concatenation when available
- ✅ Pre-allocate result array to avoid dynamic resizing
- ✅ Choose approach that matches your language's idioms
- ✅ Prioritize readability over micro-optimizations
- ✅ All approaches have same O(n) complexity

---

## 🔍 Visual Example

```
Input: nums = [1, 2, 1]

Step-by-step concatenation:
Original:  [1, 2, 1]
                    ↓ (copy)
Result:    [1, 2, 1, 1, 2, 1]
            └─────┘  └─────┘
            First    Second
            copy     copy

Index Mapping (using i % n):
i = 0: ans[0] = nums[0 % 3] = nums[0] = 1
i = 1: ans[1] = nums[1 % 3] = nums[1] = 2
i = 2: ans[2] = nums[2 % 3] = nums[2] = 1
i = 3: ans[3] = nums[3 % 3] = nums[0] = 1
i = 4: ans[4] = nums[4 % 3] = nums[1] = 2
i = 5: ans[5] = nums[5 % 3] = nums[2] = 1

Final: [1, 2, 1, 1, 2, 1] ✓
```

---


## 📈 Approach Comparison

| Approach | Code Lines | Readability | Interview Score |
|----------|-----------|-------------|-----------------|
| **Built-in Concat** | 1-2 | ⭐⭐⭐⭐⭐ | **Excellent** |
| Pre-allocated Loop | 4-6 | ⭐⭐⭐⭐ | Very Good |
| Two Loops | 6-8 | ⭐⭐⭐⭐ | Very Good |
| Modulo Loop | 4-5 | ⭐⭐⭐ | Good |

> **Reality Check**: The built-in concatenation approach is what experienced developers use. It's clean, correct, and shows good judgment about when to use language features versus reinventing the wheel.

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

**Problem Type:** Array • Simulation • Implementation

**Last Updated:** 📅 2025-01-22

</div>