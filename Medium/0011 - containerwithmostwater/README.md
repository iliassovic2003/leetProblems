# 11. Container With Most Water 💧

<div align="center">

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)

</div>

## 📖 Problem Overview

Given an integer array `height` of length `n`, where each element represents the height of a vertical line at position `i`, find two lines that together with the x-axis form a container that can hold the most water.

> 💡 **The container cannot be slanted** - water level is determined by the shorter of the two lines.

---

## 🎯 Examples

### Example 1
**Input:** `height = [1,8,6,2,5,4,8,3,7]`  
**Output:** `49`  
**Explanation:** Lines at indices 1 (height=8) and 8 (height=7) form the largest container with area = min(8,7) × (8-1) = 7 × 7 = 49

### Example 2  
**Input:** `height = [1,1]`  
**Output:** `1`  
**Explanation:** Only two lines available, area = min(1,1) × (1-0) = 1 × 1 = 1

---

## 🔒 Constraints

<div align="center">

`n == height.length`  
`2 ≤ n ≤ 10⁵`  
`0 ≤ height[i] ≤ 10⁴`

</div>

---

## 🧩 Approach & Strategy

### ⚡ Key Insights

| Aspect | Strategy |
|--------|----------|
| **Water Level** | Determined by the shorter line: `min(height[left], height[right])` |
| **Container Width** | Distance between two lines: `right - left` |
| **Area Formula** | `area = min(height[left], height[right]) × (right - left)` |
| **Optimization** | Two-pointer technique: start wide, move inward intelligently |

### 🔄 Algorithm Steps

1. **Initialize Pointers** - Place `left` at start (0) and `right` at end (n-1)
2. **Calculate Area** - Compute current container area
3. **Update Maximum** - Track the largest area found so far
4. **Move Pointer** - Move the pointer pointing to the shorter line inward:
   - If `height[left] < height[right]` → move `left++`
   - Otherwise → move `right--`
5. **Repeat** - Continue until pointers meet

### 💡 Why Move the Shorter Line?

Moving the pointer at the shorter line gives us a chance to find a taller line, potentially increasing area. Moving the taller line would only decrease width while keeping the limiting height the same or worse.

---

## 📊 Complexity Analysis

| Metric | Complexity | Explanation |
|--------|------------|-------------|
| **Time** | O(n) | Single pass through array with two pointers |
| **Space** | O(1) | Only constant extra space for variables |

---

## 🛠️ Solution Features

### ✅ Strengths
- **Optimal** - Linear time complexity with two-pointer technique
- **Greedy** - Makes locally optimal choices that lead to global optimum
- **Space Efficient** - No additional data structures needed
- **Elegant** - Simple logic with clear reasoning

### 🎯 Solved In
<div align="center">

![Java](https://img.shields.io/badge/Java-ED8B00?style=for-the-badge&logo=java&logoColor=white)
![Python](https://img.shields.io/badge/Python-3776AB?style=for-the-badge&logo=python&logoColor=white)
![JavaScript](https://img.shields.io/badge/JavaScript-F7DF1E?style=for-the-badge&logo=javascript&logoColor=black)
![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)

</div>

---

## 📝 Notes & Observations

- **Greedy Strategy**: Moving the shorter line is always the optimal choice
- **Proof**: If we move the taller line, we definitely lose width and cannot gain height (limited by shorter line)
- **Alternative Approach**: Brute force O(n²) checks all pairs - highly inefficient
- **Edge Case**: When all heights are equal, any two lines work; algorithm handles this naturally

---

<div align="center">

**Last Solved:** 📅 2025-11-29  

---

</div>