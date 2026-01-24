# 191. Number of 1 Bits 🎯

<div align="center">

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-5CB85C?style=for-the-badge&logo=leetcode&logoColor=white)

</div>

## 📖 Problem Overview

Given a positive integer `n`, write a function that returns the **number of set bits** in its binary representation (also known as the **Hamming weight**).

A **set bit** refers to a bit in the binary representation that has a value of **1**.

---

## 🎯 Examples

### Example 1
**Input:** `n = 11`  
**Output:** `3`  
**Explanation:** The input binary string `1011` has a total of three set bits.

### Example 2
**Input:** `n = 128`  
**Output:** `1`  
**Explanation:** The input binary string `10000000` has a total of one set bit.

### Example 3
**Input:** `n = 2147483645`  
**Output:** `30`  
**Explanation:** The input binary string `1111111111111111111111111111101` has a total of thirty set bits.

### Example 4
**Input:** `n = 1`  
**Output:** `1`  
**Explanation:** The binary string `1` has one set bit.

---

## 🔒 Constraints

<div align="center">

`1 <= n <= 2³¹ - 1`

</div>

---

## 🧩 Approach & Strategy

### ⚡ Key Insights

| Aspect | Handling Strategy |
|--------|------------------|
| **Binary Representation** | Process bits individually |
| **Set Bit Detection** | Check if bit is 1 using modulo or AND |
| **Bit Shifting** | Divide by 2 or right shift to process next bit |
| **Count Tracking** | Increment counter for each 1 bit |

### 🔄 Algorithm Strategies

| Strategy | Time Complexity | Space Complexity | Best For |
|----------|----------------|------------------|----------|
| **Loop & Check Each Bit** | O(log n) or O(32) | O(1) | ✅ Simple & Clear |
| **Brian Kernighan's Algorithm** | O(k)* | O(1) | ✅ Optimal for sparse bits |
| **Built-in Popcount** | O(1) | O(1) | 🚀 Hardware optimized |
| **Lookup Table** | O(1) | O(256) | 🎯 Repeated calls |

*k = number of set bits

---

## 📊 Complexity Analysis

| Metric | Complexity | Explanation |
|--------|------------|-------------|
| **Time** | O(log n) or O(32) | Process each bit of 32-bit integer |
| **Space** | O(1) | Only counter variable |

---

# Algorithm Analysis & Implementation Guide

## 💡 Core Concepts

### Binary Representation Fundamentals
- **Set Bit**: A bit position containing 1
- **Binary Structure**: 32-bit integers in most systems
- **Hamming Weight**: Count of 1s in binary representation
- **LSB (Least Significant Bit)**: Rightmost bit, obtained via `n % 2` or `n & 1`

### Bit Manipulation Techniques
- **Check LSB**: `n % 2` or `n & 1` returns 1 if LSB is set
- **Right Shift**: `n / 2` or `n >> 1` shifts all bits right
- **Brian Kernighan's Trick**: `n & (n-1)` clears the rightmost set bit
- **Built-in Functions**: `__builtin_popcount()` (C++), `bin(n).count('1')` (Python)

### Mathematical Insight
```
Example: n = 11 (decimal) = 1011 (binary)

Bit positions:  8  4  2  1
Binary:         1  0  1  1
                ↑     ↑  ↑
              Set bits (count = 3)
```

---

## 🧪 Test Cases to Consider

| Scenario | n (decimal) | n (binary) | Expected Output | Explanation |
|----------|-------------|------------|----------------|-------------|
| Small Number | `11` | `1011` | `3` | Three 1s |
| Power of 2 | `128` | `10000000` | `1` | Single 1 |
| All Bits Set | `2147483645` | `1111...1101` | `30` | Nearly all 1s |
| Minimum | `1` | `1` | `1` | Single bit |
| Odd Number | `7` | `111` | `3` | All lower bits |
| Even Number | `8` | `1000` | `1` | Single high bit |
| Maximum (2³¹-1) | `2147483647` | `0111...1111` | `31` | All bits except sign |
| Alternating Bits | `1431655765` | `01010...0101` | `16` | Half bits set |

---

## 💡 Key Insights

1. **Multiple Valid Approaches**: All three methods are correct
2. **Trade-offs Matter**: Simple loop vs optimal bit tricks
3. **Interview Context**: Know when to use each approach
4. **Hardware Support**: Modern CPUs have popcount instructions
5. **Bit Manipulation Mastery**: This problem teaches fundamental bit ops
6. **Optimization Opportunity**: Brian Kernighan's is faster for sparse bits
7. **Follow-up Importance**: Interviewers often ask about optimization

> **Pro Tip:** Start with the simple loop approach (provided solution) to show you can solve it, then mention Brian Kernighan's algorithm as an optimization. This demonstrates both clarity and depth of knowledge!

---

## 🔬 Performance Comparison

### Iteration Count for Different Values

| n | Binary | Loop Iterations | Kernighan Iterations | Speedup |
|---|--------|----------------|---------------------|---------|
| 1 | `1` | 1 | 1 | 1x |
| 8 | `1000` | 4 | 1 | **4x** |
| 15 | `1111` | 4 | 4 | 1x |
| 128 | `10000000` | 8 | 1 | **8x** |
| 256 | `100000000` | 9 | 1 | **9x** |
| 2³¹-1 | `0111...1111` | 31 | 31 | 1x |

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

**Problem Type:** Bit Manipulation • Binary • Math

**Last Updated:** 📅 2025-01-22

**Perfect For:** Bit Manipulation Fundamentals • Interview Warmup • Algorithm Optimization

</div>