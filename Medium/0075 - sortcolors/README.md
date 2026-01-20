# 75. Sort Colors 🎨

<div align="center">

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)

</div>

## 📖 Problem Overview

Given an array `nums` with `n` objects colored red, white, or blue, sort them **in-place** so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We use the integers **0**, **1**, and **2** to represent the colors red, white, and blue, respectively.

> 💡 **Challenge:** Solve this problem without using the library's sort function!

---

## 🎯 Examples

### Example 1
**Input:** `nums = [2,0,2,1,1,0]`  
**Output:** `[0,0,1,1,2,2]`  
**Explanation:** All 0s (red) first, then 1s (white), then 2s (blue)

### Example 2  
**Input:** `nums = [2,0,1]`  
**Output:** `[0,1,2]`  
**Explanation:** Single element of each color, sorted in order

---

## 🔒 Constraints

<div align="center">

`n == nums.length`  
`1 ≤ n ≤ 300`  
`nums[i] is either 0, 1, or 2`

</div>

---

## 🧩 Approach & Strategy

### ⚡ Key Insights

| Aspect | Strategy |
|--------|----------|
| **Algorithm** | Dutch National Flag algorithm (3-way partitioning) |
| **Pointers** | Three pointers: `index0` (next 0 position), `i` (current), `index2` (next 2 position) |
| **In-Place** | Swap elements without extra array |
| **One-Pass** | Single traversal through the array |

### 🔄 Algorithm Steps

1. **Initialize Pointers**
   - `index0 = 0` → boundary for placing next 0 (left side)
   - `index2 = n-1` → boundary for placing next 2 (right side)
   - `i = 0` → current element being examined

2. **Process Current Element** (while `i ≤ index2`):
   - **If `nums[i] == 0`**: Swap with `index0`, increment both `index0` and `i`
   - **If `nums[i] == 2`**: Swap with `index2`, decrement `index2` (don't increment `i`!)
   - **If `nums[i] == 1`**: Already in correct region, just increment `i`

3. **Continue** until `i` surpasses `index2`

### 💡 Why Don't We Increment `i` After Swapping with `index2`?

When we swap `nums[i]` with `nums[index2]`, we don't know what value came from `index2`. It could be 0, 1, or 2, so we need to examine it in the next iteration. However, when swapping with `index0`, we know we've already processed that region (it contains 0s or 1s), so we can safely move forward.

---

## 📊 Complexity Analysis

| Metric | Complexity | Explanation |
|--------|------------|-------------|
| **Time** | O(n) | Single pass through array, each element visited at most once |
| **Space** | O(1) | Only constant extra space for pointer variables |

---


## 🛠️ Solution Features

### ✅ Strengths
- **Optimal** - One-pass solution with linear time complexity
- **In-Place** - No extra array needed, modifies input directly
- **Space Efficient** - O(1) space complexity
- **Dutch National Flag** - Classic algorithm by Edsger Dijkstra

### 🎯 Solved In

<div align="center">

![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Java](https://img.shields.io/badge/Java-ED8B00?style=for-the-badge&logo=java&logoColor=white)
![Python](https://img.shields.io/badge/Python-3776AB?style=for-the-badge&logo=python&logoColor=white)
![JavaScript](https://img.shields.io/badge/JavaScript-F7DF1E?style=for-the-badge&logo=javascript&logoColor=black)

</div>

---

## 📝 Notes & Observations

### 🎨 Visual Representation

```
Initial:  [2, 0, 2, 1, 1, 0]
           ↑           ↑
          i=0      index2=5
      index0=0

Step 1:   [0, 0, 2, 1, 1, 2]  // Swapped first 2 with last 0
              ↑        ↑
             i=1   index2=4
         index0=1

Final:    [0, 0, 1, 1, 2, 2]  // All sorted!
```

### 🔑 Key Concepts

- **Partitioning**: Divides array into three regions: [0s | 1s | 2s]
- **Invariant**: At any point, elements before `index0` are 0s, elements after `index2` are 2s
- **Two-Way Swaps**: Elements are swapped into their correct regions
- **Single Pass**: Despite the complex logic, we only traverse the array once

### 🚀 Alternative Approaches

1. **Counting Sort** - Count occurrences of each color, then reconstruct array (two passes)
2. **Built-in Sort** - Use `sort()` function (O(n log n), violates constraints)
3. **Naive Bubble Sort** - Repeatedly swap adjacent elements (O(n²), inefficient)

### ⚠️ Common Pitfalls

- Forgetting to **not increment `i`** after swapping with `index2`
- Incorrect boundary condition (`i <= index2` is crucial)
- Off-by-one errors in pointer initialization

---

## 🎓 Follow-Up Challenge

> **Could you come up with a one-pass algorithm using only constant extra space?**

✅ **Answer:** Yes! The solution above achieves this using the Dutch National Flag algorithm with O(n) time and O(1) space.

---

<div align="center">

**Last Solved:** 📅 2024-12-23  

---

⭐ **Star this repository if you found it helpful!**

</div>