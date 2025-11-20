# 2154. Keep Multiplying Found Values by Two 🔍

<div align="center">

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-5CB85C?style=for-the-badge&logo=leetcode&logoColor=white)

</div>

## 📖 Problem Overview

Given an array of integers `nums` and an integer `original`, repeatedly search for the current value of `original` in the array. Each time it's found, double its value. Continue this process until the current value is no longer found in the array, then return the final value.

The process follows these steps:
1. Search for `original` in `nums`
2. If found, multiply it by 2
3. Repeat with the new value until it's not found
4. Return the final value

---

## 🎯 Examples

### Example 1
**Input:** `nums = [5,3,6,1,12]`, `original = 3`  
**Output:** `24`  
**Explanation:** 
- 3 is found → becomes 6
- 6 is found → becomes 12  
- 12 is found → becomes 24
- 24 is not found → return 24

### Example 2  
**Input:** `nums = [2,7,9]`, `original = 4`  
**Output:** `4`  
**Explanation:** 4 is not found initially → return 4

### Example 3
**Input:** `nums = [1,2,4,8,16]`, `original = 1`  
**Output:** `32`  
**Explanation:** Chain of doublings: 1→2→4→8→16→32

---

## 🔒 Constraints

<div align="center">

`1 <= nums.length <= 1000`  
`1 <= nums[i], original <= 1000`

</div>

---

## 🧩 Approach & Strategy

### ⚡ Key Insights

| Aspect | Handling Strategy |
|--------|------------------|
| **Repeated Search** | Efficient membership checking is crucial |
| **Exponential Growth** | Values double quickly, limiting iterations |
| **Bounded Values** | Maximum possible value is 1000 × 2^iterations |
| **Early Optimization** | Preprocessing data for fast lookups |

### 🔄 Algorithm Strategies

| Strategy | Time Complexity | Space Complexity | Best For |
|----------|----------------|------------------|----------|
| **Hash Set** | O(n) average | O(n) | General purpose |
| **Boolean Array** | O(n) | O(1) fixed | Small value constraints |
| **Sorting + Search** | O(n log n) | O(1) | When avoiding extra space |
| **In-place Search** | O(n) - O(n²) | O(1) | Educational purposes |

---

## 📊 Complexity Analysis

### Hash Set Approach (Recommended)
| Metric | Complexity | Explanation |
|--------|------------|-------------|
| **Time** | O(n + log M) | n for set building, log M for doublings |
| **Space** | O(n) | Storage for hash set |

### Boolean Array Approach (Optimal for Constraints)
| Metric | Complexity | Explanation |
|--------|------------|-------------|
| **Time** | O(n + log M) | n for array setup, log M for doublings |
| **Space** | O(1) | Fixed 1001-element array |

---

# Algorithm Analysis & Implementation Guide

## 💡 Core Concepts

### Mathematical Insight
- **Each doubling operation**: `original = original × 2`
- **Maximum iterations**: `log₂(1000000) ≈ 20` (practical limit)
- **Values grow exponentially**: `1 → 2 → 4 → 8 → 16 → 32 → ...`

### Algorithmic Patterns
- **Membership Testing**: Fast lookup operations
- **Transform-and-Check**: Apply transformation, then verify
- **Termination Condition**: Stop when value not found

### Optimization Opportunities
- **Preprocessing**: Build lookup structure once
- **Early Exit**: Stop when value exceeds bounds
- **Space-Time Tradeoff**: Choose based on constraints

---

## 🧪 Test Cases to Consider

| Scenario | Input | Original | Expected Output |
|----------|-------|----------|----------------|
| Chain Reaction | `[1,2,4,8,16]` | `1` | `32` |
| No Match | `[2,7,9]` | `4` | `4` |
| Single Match | `[5,3,1]` | `3` | `6` |
| Maximum Chain | `[1,2,4,...,512]` | `1` | `1024` |
| Duplicate Values | `[3,3,6,12]` | `3` | `24` |
| Boundary Value | `[1000]` | `1000` | `2000` |

---

## 🎯 Problem-Solving Techniques

### Step-by-Step Reasoning
1. **Identify Core Operation**: Membership testing + transformation
2. **Choose Data Structure**: Based on value constraints
3. **Implement Process Loop**: While found, double and continue
4. **Handle Edge Cases**: No match, single match, long chains

### Common Pitfalls
- ❌ Using linear search repeatedly (O(n²) time)
- ❌ Forgetting value bounds in boolean array approach
- ❌ Not considering duplicate values in array

### Optimization Guidelines
- ✅ Use hash sets for general cases
- ✅ Use boolean arrays for small, bounded values
- ✅ Consider sorting only if space is critical

---

## 📊 Complexity Analysis

| Approach | Time Complexity | Space Complexity | Best For |
|----------|----------------|------------------|----------|
| Hash Set | O(n + k) | O(n) | General cases |
| Boolean Array | O(n + k) | O(max_value) | Bounded values |
| Sorted Array | O(n log n + k log n) | O(1) | Space-critical |

*where n = array size, k = number of doublings (≈ log₂(max_value))*

---

## 📝 Notes

- The maximum number of doublings is logarithmic, making this algorithm highly efficient
- Choice of data structure significantly impacts performance
- Always consider the constraints of your specific problem when optimizing

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

**Problem Type:** Transformation • Search Algorithm

**Last Updated:** 📅 2025-01-20

</div>