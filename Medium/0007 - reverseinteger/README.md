# 7. Reverse Integer 🔄

<div align="center">

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)

</div>

## 📖 Problem Overview

Given a signed 32-bit integer `x`, return `x` with its digits reversed. If reversing `x` causes the value to go outside the signed 32-bit integer range **[-2³¹, 2³¹ - 1]**, then return `0`.

> 💡 **Assume the environment does not allow you to store 64-bit integers (signed or unsigned).**

---

## 🎯 Examples

### Example 1
**Input:** `x = 123`  
**Output:** `321`  
**Explanation:** Digits reversed from `123` to `321`

### Example 2  
**Input:** `x = -123`  
**Output:** `-321`  
**Explanation:** Negative sign preserved, digits reversed from `123` to `321`

### Example 3
**Input:** `x = 120`  
**Output:** `21`  
**Explanation:** Trailing zero disappears when reversed

---

## 🔒 Constraints

<div align="center">

`-2³¹ ≤ x ≤ 2³¹ - 1`

</div>

---

## 🧩 Approach & Strategy

### 🎨 Visual Representation
Original: 123
Step 1: 3 (remainder 12)
Step 2: 32 (remainder 1)
Step 3: 321 (remainder 0)
Result: 321

### ⚡ Key Insights

| Aspect | Handling Strategy |
|--------|------------------|
| **Negative Numbers** | Preserve sign, work with absolute value |
| **Trailing Zeros** | Automatically eliminated during reversal |
| **Integer Overflow** | Check boundaries before updating result |
| **32-bit Limit** | Return 0 if outside [-2147483648, 2147483647] |

### 🔄 Algorithm Steps

1. **Extract Sign** - Determine if number is positive or negative
2. **Process Digits** - While number ≠ 0:
   - Get last digit: `digit = x % 10`
   - Remove last digit: `x = x / 10`
   - **Overflow Check** - Verify result stays within 32-bit bounds
   - Build reversed number: `result = result * 10 + digit`
3. **Apply Sign** - Restore original sign to result

---

## 📊 Complexity Analysis

| Metric | Complexity | Explanation |
|--------|------------|-------------|
| **Time** | O(log₁₀x) | Proportional to number of digits |
| **Space** | O(1) | Constant extra space used |

---

## 🛠️ Solution Features

### ✅ Strengths
- **Efficient** - Mathematical approach avoids string conversion
- **Robust** - Handles all edge cases including integer overflow
- **Clean** - Simple and readable logic
- **Optimized** - Minimal memory usage

### 🎯 Solved In
<div align="center">

![Java](https://img.shields.io/badge/Java-ED8B00?style=for-the-badge&logo=java&logoColor=white)
![Python](https://img.shields.io/badge/Python-3776AB?style=for-the-badge&logo=python&logoColor=white)
![JavaScript](https://img.shields.io/badge/JavaScript-F7DF1E?style=for-the-badge&logo=javascript&logoColor=black)
![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)

</div>

---

## 📝 Notes & Observations

- **Critical**: Overflow check must happen **before** updating the result
- **Edge Case**: `-2147483648` (minimum integer) requires careful handling
- **Mathematical approach** is preferred over string manipulation for efficiency

---

<div align="center">

**Last Solved:** 📅 2025-11-14  

---

</div>
