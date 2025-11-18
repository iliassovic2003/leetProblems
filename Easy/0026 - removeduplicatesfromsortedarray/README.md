# 26. Remove Duplicates from Sorted Array 🧹

<div align="center">

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-5CB85C?style=for-the-badge&logo=leetcode&logoColor=white)

</div>

## 📖 Problem Overview

Given an integer array `nums` sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be maintained.

The first `k` elements of the array should contain the unique elements in sorted order. The remaining elements beyond index `k-1` can contain any values and are ignored.

---

## 🎯 Examples

### Example 1
**Input:** `nums = [1,1,2]`  
**Output:** `2, nums = [1,2,_]`  
**Explanation:** Your function should return `k = 2`, with the first two elements of nums being 1 and 2 respectively.

### Example 2  
**Input:** `nums = [0,0,1,1,1,2,2,3,3,4]`  
**Output:** `5, nums = [0,1,2,3,4,_,_,_,_,_]`  
**Explanation:** Your function should return `k = 5`, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.

---

## 🔒 Constraints

<div align="center">

`1 <= nums.length <= 3 * 10⁴`  
`-100 <= nums[i] <= 100`  
`nums is sorted in non-decreasing order`

</div>

---

## 🧩 Approach & Strategy

### ⚡ Key Insights

| Aspect | Handling Strategy |
|--------|------------------|
| **Sorted Property** | Leverage sorted nature to detect duplicates efficiently |
| **Two Pointer Technique** | Use slow and fast pointers for in-place modification |
| **In-place Requirement** | Modify array without extra space for unique elements |
| **Relative Order** | Maintain original order of unique elements |

### 🔄 Algorithm Steps

1. **Initialize Pointer** - Start with slow pointer at index 0
2. **Iterate with Fast Pointer** - Traverse array from index 1 to end
3. **Detect Unique Elements** - When `nums[fast] != nums[slow]`, increment slow pointer
4. **Update Unique Position** - Copy unique element to `nums[slow]`
5. **Return Count** - Return `slow + 1` as number of unique elements

---

## 📊 Complexity Analysis

| Metric | Complexity | Explanation |
|--------|------------|-------------|
| **Time** | O(n) | Single pass through the array |
| **Space** | O(1) | In-place modification, no extra data structures |

---

## 🎯 Solution Features

### ✅ Strengths

**Efficient** - Single pass O(n) time complexity  
**Memory Optimal** - O(1) extra space usage  
**In-place Modification** - No array copying required  
**Maintains Order** - Preserves relative order of unique elements  
**Simple Logic** - Easy to understand and implement  

### 🔍 Key Observations

**Two Pointer Mastery** - Classic application of slow/fast pointer technique  
**Sorted Advantage** - Leverages sorted property for duplicate detection  
**Early Stop Potential** - Can terminate early if array processed  
**Judge Flexibility** - Only first k elements need to be correct  

---

## 💡 Common Pitfalls

| Pitfall | Solution |
|---------|----------|
| Using extra O(n) space | Implement two-pointer in-place approach |
| Modifying array size | Work within original array bounds |
| Breaking sorted order | Maintain relative order during updates |
| Overcomplicating logic | Stick to simple comparison and copy |

---

## 🛠️ Implementation Notes

**Critical Insight:** The slow pointer always points to the last unique element  
**Edge Cases:** Empty array, single element, all duplicates, no duplicates  
**Optimization:** Early return for arrays with 0 or 1 elements  
**Testing:** Verify with custom judge constraints and assertions  


# 🎯 Solved In
<div align="center">

![Java](https://img.shields.io/badge/Java-ED8B00?style=for-the-badge&logo=java&logoColor=white)
![Python](https://img.shields.io/badge/Python-3776AB?style=for-the-badge&logo=python&logoColor=white)
![JavaScript](https://img.shields.io/badge/JavaScript-F7DF1E?style=for-the-badge&logo=javascript&logoColor=black)
![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)

</div>

---

## 🔄 Related Patterns

- **Two Pointers** - Slow and fast pointer technique
- **In-place Array Modification** - Space-optimized operations
- **Sorted Array Manipulation** - Leveraging sorted property

<div align="center">

---
**Pattern Recognition:** Two Pointers • In-place Modification • Array Manipulation

**Last Updated:** 📅 2024-01-15

</div>
