# 66. Plus One ➕

<div align="center">

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-5CB85C?style=for-the-badge&logo=leetcode&logoColor=white)

</div>

## 📖 Problem Overview

Given a large integer represented as an integer array `digits`, where each `digits[i]` is the i-th digit of the integer, increment the large integer by one and return the resulting array of digits.

The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

---

## 🎯 Examples

### Example 1
**Input:** `digits = [1,2,3]`  
**Output:** `[1,2,4]`  
**Explanation:** The array represents the integer 123. Incrementing by one gives 123 + 1 = 124.

### Example 2  
**Input:** `digits = [4,3,2,1]`  
**Output:** `[4,3,2,2]`  
**Explanation:** The array represents the integer 4321. Incrementing by one gives 4321 + 1 = 4322.

### Example 3
**Input:** `digits = [9]`  
**Output:** `[1,0]`  
**Explanation:** The array represents the integer 9. Incrementing by one gives 9 + 1 = 10.

---

## 🔒 Constraints

<div align="center">

`1 <= digits.length <= 100`  
`0 <= digits[i] <= 9`  
`digits does not contain any leading 0's`

</div>

---

## 🧩 Approach & Strategy

### ⚡ Key Insights

| Aspect | Handling Strategy |
|--------|------------------|
| **Carry Propagation** | Start from least significant digit and propagate carry leftwards |
| **All Nines Case** | When all digits are 9, array size increases by 1 |
| **Trailing Nines** | Multiple consecutive 9s require carry through multiple digits |
| **Early Termination** | Stop processing once no carry remains |

### 🔄 Algorithm Steps

1. **Process from right to left** - Start from the last digit
2. **Add one to current digit** and check for carry
3. **If digit becomes 10**, set to 0 and continue carry
4. **If digit < 10**, return immediately (no further carry)
5. **If all digits processed with carry**, prepend 1 to array

---

## 📊 Complexity Analysis

| Metric | Complexity | Explanation |
|--------|------------|-------------|
| **Time** | O(n) | Worst case: process all digits once |
| **Space** | O(1) | In-place modification (except all-9s case) |

---

## 🎯 Solution Features

# ✅ Strengths

**Efficient** - Single pass through array
**Early Termination** - Stops when carry is resolved
**In-place - Modifies** original array when possible
**Handles Edge Cases** - Properly manages all-9s scenario

# 🔍 Key Observations

Mathematical approach avoids string conversion overhead
Carry propagation mimics actual addition process
Array resizing only needed for worst-case scenario
Clean separation of normal vs edge case handling

# 📝 Notes & Observations

**Critical Insight:** The only case that increases array size is when all digits are 9
**Optimization:** Early return prevents unnecessary iterations
**Memory Consideration:** Most cases modify array in-place
**Real-world Analog:** Mimics how humans perform mental addition

<div align="center">

**Pattern Recognition:** Array Manipulation • Carry Propagation.

**Last Updated:** 📅 2024-01-15

</div>