# 704. Binary Search 🎯

<div align="center">

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-5CB85C?style=for-the-badge&logo=leetcode&logoColor=white)

</div>

## 📖 Problem Overview

Given an array of integers `nums` which is **sorted in ascending order**, and an integer `target`, write a function to search `target` in `nums`. If `target` exists, then return its index. Otherwise, return `-1`.

**Critical Requirement:** You must write an algorithm with **O(log n)** runtime complexity.

---

## 🎯 Examples

### Example 1
**Input:** `nums = [-1,0,3,5,9,12]`, `target = 9`  
**Output:** `4`  
**Explanation:** 9 exists in nums and its index is 4

### Example 2
**Input:** `nums = [-1,0,3,5,9,12]`, `target = 2`  
**Output:** `-1`  
**Explanation:** 2 does not exist in nums so return -1

### Example 3
**Input:** `nums = [5]`, `target = 5`  
**Output:** `0`  
**Explanation:** Single element found at index 0

---

## 🔒 Constraints

<div align="center">

`1 <= nums.length <= 10⁴`  
`-10⁴ < nums[i], target < 10⁴`  
All the integers in `nums` are **unique**  
`nums` is sorted in **ascending order**

</div>

---

## 🧩 Approach & Strategy

### ⚡ Key Insights

| Aspect | Handling Strategy |
|--------|------------------|
| **Array Pre-sorted** | Leverage binary search for O(log n) |
| **Unique Elements** | No duplicates to handle |
| **Target Found** | Return index immediately |
| **Target Not Found** | Return -1 after search completes |

### 🔄 Algorithm Strategies

| Strategy | Time Complexity | Space Complexity | Meets Requirement? |
|----------|----------------|------------------|-------------------|
| **Binary Search (Iterative)** | O(log n) | O(1) | ✅ Yes (Optimal) |
| **Binary Search (Recursive)** | O(log n) | O(log n) | ✅ Yes |
| **Linear Search** | O(n) | O(1) | ❌ No |
| **Built-in Search** | O(log n) or O(n) | O(1) | ⚠️ Depends on implementation |

---

## 📊 Complexity Analysis

### Binary Search - Iterative (Optimal)

| Metric | Complexity | Explanation |
|--------|------------|-------------|
| **Time** | O(log n) | Halves search space each iteration |
| **Space** | O(1) | Only constant extra variables |

### Binary Search - Recursive

| Metric | Complexity | Explanation |
|--------|------------|-------------|
| **Time** | O(log n) | Halves search space each recursion |
| **Space** | O(log n) | Call stack depth |

> **Best Practice:** Use **iterative binary search** for optimal space complexity and to avoid stack overflow on very large arrays.

---

# Algorithm Analysis & Implementation Guide

## 💡 Core Concepts

### Mathematical Insight
- **Binary Search**: Divide and conquer by halving search space
- **Logarithmic Growth**: Each step eliminates half the remaining elements
- **Middle Point Calculation**: `mid = left + (right - left) / 2` prevents overflow
- **Search Space Reduction**: Compare target with middle element to decide which half to search

### Algorithmic Patterns
- **Two-Pointer Technique**: Maintain left and right boundaries
- **Divide and Conquer**: Split problem into smaller subproblems
- **Invariant Maintenance**: Target (if exists) is always within [left, right)
- **Termination Condition**: Loop until search space is empty

### Optimization Opportunities
- **Iterative vs Recursive**: Iterative saves stack space
- **Boundary Handling**: Use `left < right` or `left <= right` patterns
- **Overflow Prevention**: Use `left + (right - left) / 2` instead of `(left + right) / 2`
- **Early Termination**: Return immediately when target found

---

## 🎯 Problem-Solving Techniques

### Step-by-Step Reasoning

#### Binary Search Algorithm (Recommended ✅)
1. **Initialize Pointers**: Set `left = 0` and `right = nums.length`
2. **Loop While Space Exists**: `while (left < right)`
3. **Calculate Middle**: `mid = left + (right - left) / 2`
4. **Compare with Target**:
   - If `target < nums[mid]`: Search left half → `right = mid`
   - If `target > nums[mid]`: Search right half → `left = mid + 1`
   - If `target == nums[mid]`: Found! → Return `mid`
5. **Target Not Found**: Exit loop → Return `-1`

**Why This Works:**
- ✅ Each iteration eliminates half the search space
- ✅ Logarithmic time complexity guaranteed
- ✅ Works on sorted arrays with unique elements
- ✅ Constant space usage
- ✅ Handles all edge cases correctly

### Optimization Guidelines
- ✅ Use `left + (right - left) / 2` to prevent overflow
- ✅ Choose one boundary pattern and stick with it consistently
- ✅ Return immediately when target is found
- ✅ Use iterative approach for better space complexity
- ✅ Consider edge cases: empty array, single element, target out of bounds

---

## 🔍 Visual Example

```
Search for target = 9 in nums = [-1, 0, 3, 5, 9, 12]

Initial State:
[-1,  0,  3,  5,  9, 12]
  ↑              ↑
left            right
      mid = 2

Step 1: nums[2] = 3 < 9
Search right half:
[-1,  0,  3,  5,  9, 12]
              ↑      ↑
            left   right
                  mid = 4

Step 2: nums[4] = 9 == 9
Found! Return index 4 ✓

---

Search for target = 2 (not in array)

Initial State:
[-1,  0,  3,  5,  9, 12]
  ↑              ↑
left            right
      mid = 2

Step 1: nums[2] = 3 > 2
Search left half:
[-1,  0,  3,  5,  9, 12]
  ↑   ↑
left right
  mid = 0

Step 2: nums[0] = -1 < 2
Search right:
[-1,  0,  3,  5,  9, 12]
      ↑  ↑
    left right
      mid = 1

Step 3: nums[1] = 0 < 2
Search right:
[-1,  0,  3,  5,  9, 12]
          ↑ ↑
      left=right

Loop exits (left >= right)
Return -1 (not found) ✓
```

---

## 💡 Key Insights

1. **Foundation Algorithm**: Binary search is fundamental to computer science
2. **Sorted Data Requirement**: Only works on sorted arrays
3. **Logarithmic Magic**: Searching 1 million elements takes only ~20 comparisons
4. **Two Boundary Patterns**: Exclusive `[left, right)` or Inclusive `[left, right]` - both work!
5. **Overflow Prevention**: Always use `left + (right - left) / 2`
6. **Interview Favorite**: One of the most commonly asked algorithm questions
7. **Template Pattern**: Master this and apply to many similar problems

> **Pro Tip:** The implementation provided uses the **exclusive right boundary pattern** `[left, right)`. This is slightly cleaner because `right = mid` doesn't need `-1`, and `left = mid + 1` advances naturally. However, the inclusive pattern `[left, right]` is also valid - choose one and be consistent!

## 🔬 Complexity Visualization

| Array Size (n) | Max Comparisons (log₂ n) | Linear Search |
|----------------|-------------------------|---------------|
| 10 | 4 | 10 |
| 100 | 7 | 100 |
| 1,000 | 10 | 1,000 |
| 10,000 | 14 | 10,000 |
| 1,000,000 | 20 | 1,000,000 |
| 1,000,000,000 | 30 | 1,000,000,000 |

> **Amazing Fact:** Binary search can find an element in a **billion-element array** in just **30 comparisons**! 🚀

---

## 🎯 Solved In

<div align="center">

![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![JavaScript](https://img.shields.io/badge/JavaScript-F7DF1E?style=for-the-badge&logo=javascript&logoColor=black)
![Python](https://img.shields.io/badge/Python-3776AB?style=for-the-badge&logo=python&logoColor=white)
![Java](https://img.shields.io/badge/Java-ED8B00?style=for-the-badge&logo=java&logoColor=white)

</div>

---

<div align="center">

**Problem Type:** Binary Search • Array • Divide and Conquer

**Last Updated:** 📅 2025-01-22

**Perfect For:** Algorithm Fundamentals • Interview Preparation • Binary Search Mastery

</div>