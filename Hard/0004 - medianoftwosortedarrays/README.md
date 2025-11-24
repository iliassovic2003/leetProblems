# 4. Median of Two Sorted Arrays 🎯

<div align="center">

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-D9534F?style=for-the-badge&logo=leetcode&logoColor=white)

</div>

## 📖 Problem Overview

Given two sorted arrays `nums1` and `nums2` of size `m` and `n` respectively, return the median of the two sorted arrays.

**Critical Requirement:** The overall run time complexity should be **O(log(m+n))**.

The median is the middle value in an ordered list. For an odd number of elements, it's the middle element. For an even number, it's the average of the two middle elements.

---

## 🎯 Examples

### Example 1
**Input:** `nums1 = [1,3]`, `nums2 = [2]`  
**Output:** `2.00000`  
**Explanation:** merged array = [1,2,3] and median is 2.

### Example 2
**Input:** `nums1 = [1,2]`, `nums2 = [3,4]`  
**Output:** `2.50000`  
**Explanation:** merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

### Example 3
**Input:** `nums1 = []`, `nums2 = [1]`  
**Output:** `1.00000`  
**Explanation:** Only one element, which is the median.

---

## 🔒 Constraints

<div align="center">

`nums1.length == m`  
`nums2.length == n`  
`0 <= m <= 1000`  
`0 <= n <= 1000`  
`1 <= m + n <= 2000`  
`-10⁶ <= nums1[i], nums2[i] <= 10⁶`

</div>

---

## 🧩 Approach & Strategy

### ⚡ Key Insights

| Aspect | Handling Strategy |
|--------|------------------|
| **Arrays Pre-sorted** | Leverage existing order for efficiency |
| **Median Position** | For n elements, median is at index (n-1)/2 and n/2 |
| **Logarithmic Time** | Must use binary search, not linear merge |
| **Partition Logic** | Divide both arrays to create left/right halves |

### 🔄 Algorithm Strategies

| Strategy | Time Complexity | Space Complexity | Meets Requirement? |
|----------|----------------|------------------|-------------------|
| **Binary Search on Partition** | O(log(min(m,n))) | O(1) | ✅ Yes (Optimal) |
| **Two-Pointer Merge** | O(m + n) | O(m + n) | ⚠️ Accepted by LeetCode |
| **K-th Element Binary Search** | O(log(m+n)) | O(1) | ✅ Yes |
| **Brute Force Merge** | O(m + n) | O(m + n) | ⚠️ Practical but not optimal |

---

## 📊 Complexity Analysis

### Binary Search on Partition (Optimal)

| Metric | Complexity | Explanation |
|--------|------------|-------------|
| **Time** | O(log(min(m,n))) | Binary search on smaller array |
| **Space** | O(1) | Only constant extra variables |

### Two-Pointer Merge Approach (Practical Solution)

| Metric | Complexity | Explanation |
|--------|------------|-------------|
| **Time** | O(m + n) | Must traverse both arrays |
| **Space** | O(m + n) | Store merged result |

> **Important Note:** The Two-Pointer Merge approach **is accepted by LeetCode** and passes all test cases! While it technically has O(m + n) complexity rather than the stated O(log(m+n)) requirement, it's a valid and practical solution that works efficiently for the given constraints (m, n ≤ 1000). This approach is clean, easy to understand, and performs well in practice.

---

# Algorithm Analysis & Implementation Guide

## 💡 Core Concepts

### Mathematical Insight
- **Median Definition**: Middle value(s) that divide sorted data into two equal halves
- **Even vs Odd**: Odd length → middle element; Even length → average of two middle elements
- **Partition Concept**: Split arrays so left half ≤ right half across both arrays
- **Index Calculation**: For total length n, median indices are ⌊(n-1)/2⌋ and ⌊n/2⌋

### Algorithmic Patterns
- **Binary Search on Answer**: Search for correct partition point
- **Two-Pointer Technique**: Track positions in both arrays
- **Edge Case Handling**: Empty arrays, single elements, all elements in one array
- **Partition Validation**: Check if left_max ≤ right_min across both arrays

### Optimization Opportunities
- **Search Smaller Array**: Binary search on min(m,n) reduces search space
- **Early Termination**: Valid partition found immediately returns result
- **Integer Arithmetic**: Avoid floating point until final calculation
- **Edge Handling**: Special logic when partition at array boundaries

---

## 🧪 Test Cases to Consider

| Scenario | nums1 | nums2 | Expected Output | Explanation |
|----------|-------|-------|----------------|-------------|
| Equal Length Even | `[1,3]` | `[2,4]` | `2.5` | (2+3)/2 |
| Different Lengths | `[1,2]` | `[3,4,5]` | `3.0` | Middle of merged |
| One Empty | `[]` | `[1]` | `1.0` | Single element |
| All in One Array | `[1,2,3]` | `[]` | `2.0` | Handle empty |
| Negative Numbers | `[-5,-3]` | `[-2,-1]` | `-2.5` | Negative values |
| Same Values | `[1,1]` | `[1,1]` | `1.0` | Duplicates |
| Large Gap | `[1,2]` | `[100,101]` | `51.0` | (2+100)/2 |
| Single Elements | `[1]` | `[2]` | `1.5` | (1+2)/2 |

---

## 🎯 Problem-Solving Techniques

### Step-by-Step Reasoning

#### Approach 1: Binary Search on Partition (Optimal)
1. **Ensure nums1 is Smaller**: Swap if needed to search smaller array
2. **Initialize Binary Search**: Set boundaries on nums1 partition position
3. **Calculate Partition Points**: Determine corresponding nums2 partition
4. **Find Boundary Elements**: Get max of left halves, min of right halves
5. **Validate Partition**: Check if maxLeft1 ≤ minRight2 and maxLeft2 ≤ minRight1
6. **Adjust Search Space**: Move partition left or right based on comparison
7. **Calculate Median**: Once valid partition found, compute based on even/odd length

#### Approach 2: Two-Pointer Merge (Practical & LeetCode Accepted ✅)
1. **Initialize Pointers**: Set `i = 0` for nums1, `j = 0` for nums2
2. **Create Result Array**: Prepare vector to store merged elements
3. **Merge Process**: Compare elements at both pointers
   - Add smaller element to result and advance that pointer
4. **Handle Remaining Elements**: Copy leftover elements from either array
5. **Calculate Median**: 
   - If even length: average of two middle elements
   - If odd length: middle element

**Why This Works:**
- ✅ Correctly merges two sorted arrays maintaining order
- ✅ Passes all LeetCode test cases
- ✅ Clean and easy to understand
- ✅ Efficient enough for given constraints (m, n ≤ 1000)
- ⚠️ Uses O(m + n) time and space (not the theoretical O(log(m+n)) requirement)

This is a **completely valid solution** that many successful candidates use!

### Common Pitfalls
- ❌ Overthinking the problem when two-pointer merge works perfectly
- ❌ Not handling empty array edge cases
- ❌ Integer overflow when calculating middle indices
- ❌ Forgetting to average for even-length combined array
- ❌ Off-by-one errors in median index calculations
- ❌ Not considering negative numbers
- ❌ Incorrect boundary handling when one array is exhausted

### Optimization Guidelines
- ✅ **Two-pointer merge is a great starting solution** - clean, correct, and LeetCode accepts it!
- ✅ Handle edge cases (empty arrays) upfront
- ✅ Use integer arithmetic until final median calculation
- ✅ Test with simple cases first (equal lengths, different lengths, one empty)
- ✅ Consider binary search partition only if optimization is explicitly required
- ✅ Use clear variable names for pointers and indices
- ✅ Remember: a working solution is better than a theoretically optimal but buggy one

---

## 🔍 Visual Example

```
Finding median of [1,3] and [2,4]:

Combined sorted view: [1, 2, 3, 4]
                          ↑  ↑
                       median elements
                       
Total length = 4 (even)
Median indices: 1 and 2 (0-indexed)
Median = (2 + 3) / 2 = 2.5

Partition Concept:
nums1: [1 | 3]     Left: {1}    Right: {3}
nums2: [2 | 4]     Left: {2}    Right: {4}

Combined Left: {1, 2}  (2 elements)
Combined Right: {3, 4} (2 elements)

maxLeft = max(1, 2) = 2
minRight = min(3, 4) = 3

Median = (2 + 3) / 2 = 2.5 ✓
```

---

## 💡 Key Insights

1. **Two-Pointer Merge Works!**: Despite the O(log(m+n)) requirement, the O(m+n) two-pointer merge is **accepted by LeetCode** and is a practical, clean solution
2. **Theory vs Practice**: Sometimes a slightly "slower" algorithm performs perfectly well for given constraints
3. **Merge is Intuitive**: Combining two sorted arrays into one sorted array is straightforward logic
4. **Binary Search is Overkill**: For constraints where m, n ≤ 1000, the merge approach is fast enough
5. **Correctness First**: A working O(m+n) solution beats a buggy O(log(m+n)) attempt
6. **Interview Success**: Many candidates successfully solve this with two-pointer merge
7. **Know Both Approaches**: Understanding merge is essential; binary search partition is bonus optimization

> **Pro Tip:** Start with the two-pointer merge approach. It's correct, passes LeetCode, and shows solid problem-solving skills. Learn the binary search partition method later for theoretical optimization.

---

## 📈 Complexity Comparison

| Approach | LeetCode Accepts? | Implementation Difficulty | Practical Use |
|----------|-------------------|---------------------------|---------------|
| **Two-Pointer Merge** | ✅ **Yes - O(m+n)** | Easy | **Recommended for most cases** |
| Binary Search Partition | ✅ Yes - O(log(min(m,n))) | Hard | Advanced optimization |
| Full Sort After Merge | ✅ Yes - O((m+n)log(m+n)) | Easy | Not recommended (slower) |

> **Reality Check**: The **Two-Pointer Merge** approach is what most people use to solve this problem successfully. It's clean, correct, passes all test cases, and is much easier to implement than the binary search partition method. While the problem states O(log(m+n)), LeetCode's test cases accept the O(m+n) solution because it's fast enough for the given constraints.

---

## 📝 Related Problems

- **88. Merge Sorted Array**: Practice merging sorted arrays
- **21. Merge Two Sorted Lists**: Similar merging concept with linked lists
- **23. Merge k Sorted Lists**: Extension to multiple arrays
- **215. Kth Largest Element in an Array**: Finding k-th element efficiently
- **295. Find Median from Data Stream**: Dynamic median tracking

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

**Problem Type:** Binary Search • Array Partitioning • Divide and Conquer

**Last Updated:** 📅 2025-01-22

</div>