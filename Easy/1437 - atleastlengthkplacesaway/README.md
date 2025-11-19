# 1437. Check If All 1's Are at Least Length K Places Away 🔍

<div align="center">

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-5CB85C?style=for-the-badge&logo=leetcode&logoColor=white)

</div>

## 📖 Problem Overview

Given a binary array `nums` and an integer `k`, return `true` if all 1's are at least `k` places away from each other, otherwise return `false`.

The distance between two 1's is measured by the number of elements between them. For two consecutive 1's to be considered at least `k` places apart, there must be at least `k` zeros separating them.

---

## 🎯 Examples

### Example 1
**Input:** `nums = [1,0,0,0,1,0,0,1]`, `k = 2`  
**Output:** `true`  
**Explanation:** Each pair of consecutive 1's has at least 2 zeros between them.

### Example 2  
**Input:** `nums = [1,0,0,1,0,1]`, `k = 2`  
**Output:** `false`  
**Explanation:** The second 1 and third 1 are only separated by 1 zero.

### Example 3
**Input:** `nums = [1,1,1,1,1]`, `k = 1`  
**Output:** `false`  
**Explanation:** Consecutive 1's have 0 zeros between them.

---

## 🔒 Constraints

<div align="center">

`1 <= nums.length <= 10^5`  
`0 <= k <= nums.length`  
`nums[i] is 0 or 1`

</div>

---

## 🧩 Approach & Strategy

### ⚡ Key Insights

| Aspect | Handling Strategy |
|--------|------------------|
| **Distance Counting** | Track the number of zeros between consecutive 1's |
| **State Management** | Maintain a counter that resets at each 1 and increments at each 0 |
| **Early Validation** | Check distance constraint immediately when encountering a 1 |
| **Boundary Handling** | First 1 doesn't require distance validation |

### 🔄 Algorithm Steps

1. **Initialize distance tracker** - Start with maximum valid distance
2. **Iterate through array** - Process each element from left to right
3. **When encountering 0** - Increment the distance counter
4. **When encountering 1**:
   - Check if current distance meets requirement
   - Reset distance counter to zero
5. **Final validation** - Return true if all 1's pass distance checks

---

## 📊 Complexity Analysis

| Metric | Complexity | Explanation |
|--------|------------|-------------|
| **Time** | O(n) | Single linear pass through the array |
| **Space** | O(1) | Constant extra space for counters |

---

## 🎯 Solution Features

### ✅ Strengths

**Single Pass Efficiency** - Processes array in one iteration  
**Early Termination** - Returns false immediately upon constraint violation  
**Memory Optimization** - Uses minimal constant extra space  
**Intuitive Logic** - Clear state transitions between 0's and 1's  

### 🔍 Key Observations

- The problem reduces to monitoring gaps between consecutive 1's
- Distance counter represents zeros since last encountered 1
- First 1 encountered doesn't need distance validation
- When k=0, any configuration is automatically valid
- Counter reset logic ensures proper distance measurement

### 📝 Notes & Observations

**Critical Insight:** Maintain running count of zeros between 1's  
**Edge Case Handling:** Arrays with 0 or 1 ones always satisfy condition  
**Performance Consideration:** Early exit optimizes worst-case scenarios  
**Mathematical Foundation:** Distance requirement translates to counter threshold  

---

## 💡 Core Concept

The solution employs a **sliding window** approach where the window represents the gap between consecutive 1's. By maintaining a running count of zeros and validating against the threshold `k` at each encountered 1, the algorithm efficiently verifies the distance constraint without storing positions or performing multiple passes.

---

## 🧪 Test Cases to Consider

1. **Empty Gap**: `[1,1]`, k=1 → false
2. **Maximum Distance**: `[1,0,0,0,1]`, k=3 → true
3. **Single Element**: `[1]`, any k → true
4. **No Ones**: `[0,0,0]`, any k → true
5. **Boundary Case**: `[1,0,1]`, k=1 → true
6. **K=0**: Any configuration → true
7. **Large Array**: Performance test with 10^5 elements

---

## 🔄 Alternative Approaches

| Approach | Complexity | Pros | Cons |
|----------|------------|------|------|
| **Distance Counter** | O(n) time, O(1) space | Optimal, simple | - |
| **Position Storage** | O(n) time, O(m) space | Clear position tracking | Extra memory |
| **Two Pointers** | O(n) time, O(1) space | Explicit gap measurement | More complex |

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

**Problem Type:** Constraint Checking • Binary Array Processing

**Last Updated:** 📅 2024-01-15

</div>