# 3. Longest Substring Without Repeating Characters 🔤

<div align="center">

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-F0AD4E?style=for-the-badge&logo=leetcode&logoColor=white)

</div>

## 📖 Problem Overview

Given a string `s`, find the length of the **longest substring** without duplicate characters.

**Key Point:** A **substring** is a contiguous sequence of characters within a string. This is different from a **subsequence**, which doesn't need to be contiguous.

---

## 🎯 Examples

### Example 1
**Input:** `s = "abcabcbb"`  
**Output:** `3`  
**Explanation:** The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.

### Example 2
**Input:** `s = "bbbbb"`  
**Output:** `1`  
**Explanation:** The answer is "b", with the length of 1.

### Example 3
**Input:** `s = "pwwkew"`  
**Output:** `3`  
**Explanation:** The answer is "wke", with the length of 3.  
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

### Example 4
**Input:** `s = ""`  
**Output:** `0`  
**Explanation:** Empty string has no characters.

---

## 🔒 Constraints

<div align="center">

`0 <= s.length <= 5 * 10⁴`  
`s` consists of English letters, digits, symbols and spaces

</div>

---

## 🧩 Approach & Strategy

### ⚡ Key Insights

| Aspect | Handling Strategy |
|--------|------------------|
| **Sliding Window** | Expand right, shrink left when duplicate found |
| **Duplicate Detection** | Need fast lookup to check if character exists |
| **Position Tracking** | Store last seen index for optimal jumping |
| **Contiguous Requirement** | Must maintain unbroken sequence |

### 🔄 Algorithm Strategies

| Strategy | Time Complexity | Space Complexity | Optimal? |
|----------|----------------|------------------|----------|
| **Sliding Window + HashMap** | O(n) | O(min(m, n)) | ✅ **Best - Optimized jumps** |
| **Sliding Window + Set** | O(n) - O(2n) | O(min(m, n)) | ✅ Good - Simple |
| **Brute Force** | O(n³) | O(min(m, n)) | ❌ Too slow |
| **Two Nested Loops** | O(n²) | O(min(m, n)) | ❌ Inefficient |

*where n = string length, m = character set size (typically 128 for ASCII)*

---

## 📊 Complexity Analysis

### HashMap Approach (Optimal - Recommended ✨)

| Metric | Complexity | Explanation |
|--------|------------|-------------|
| **Time** | O(n) | Single pass with optimized jumps |
| **Space** | O(min(m, n)) | Store characters and their indices |

**Why HashMap is Better:**
- ✅ **Optimized Jumps**: When duplicate found, jump `left` pointer directly to `last_seen_index + 1`
- ✅ **No Shrinking Loop**: Unlike set approach, no need to remove characters one by one
- ✅ **Single Pass**: Each character visited at most once by right pointer
- ✅ **Fast Lookup**: O(1) average time for checking and updating positions

### Set Approach (Good Alternative)

| Metric | Complexity | Explanation |
|--------|------------|-------------|
| **Time** | O(n) - O(2n) | Worst case: both pointers visit each character |
| **Space** | O(min(m, n)) | Store unique characters |

**Characteristics:**
- ⚠️ **Sequential Shrinking**: Must remove characters one by one from left
- ⚠️ **Potentially More Operations**: Left pointer may need multiple moves
- ✅ **Simpler Logic**: Easier to understand for beginners

---

# Algorithm Analysis & Implementation Guide

## 💡 Core Concepts

### Mathematical Insight
- **Sliding Window**: Dynamic range [left, right] that expands and contracts
- **Window Validity**: Valid when all characters in [left, right] are unique
- **Maximum Tracking**: Keep updating max length as window expands
- **Jump Optimization**: Skip redundant checks by jumping to safe position

### Algorithmic Patterns
- **Two Pointers**: Left and right boundaries of current window
- **HashMap for Position Tracking**: Character → Last seen index
- **Greedy Expansion**: Always try to expand window to the right
- **Smart Contraction**: Jump left pointer optimally when duplicate found

### Optimization Opportunities
- **HashMap over Set**: Store indices for direct jumping vs sequential removal
- **Max Position Tracking**: Use `max(left, lastIndex + 1)` to handle overlaps
- **Early Exit**: If remaining chars can't beat current max, stop early
- **Character Set Optimization**: Use array instead of map for known small charset

---

## 🧪 Test Cases to Consider

| Scenario | Input | Expected Output | Explanation |
|----------|-------|----------------|-------------|
| All Unique | `"abcdef"` | `6` | Entire string is valid |
| All Same | `"aaaaa"` | `1` | Only single character |
| Empty String | `""` | `0` | No characters |
| Single Character | `"a"` | `1` | One character only |
| Duplicate at End | `"abcda"` | `4` | "abcd" before repeat |
| Complex Pattern | `"pwwkew"` | `3` | "wke" or "kew" |
| Spaces & Symbols | `"a b!c@d#"` | `9` | All characters unique |
| Long Repeating | `"abcabcbb"` | `3` | "abc" repeats |
| Adjacent Duplicates | `"dvdf"` | `3` | "vdf" is longest |

---

## 🎯 Problem-Solving Techniques

### Step-by-Step Reasoning

#### Approach 1: Sliding Window + HashMap (Optimal ⭐)
1. **Initialize Variables**:
   - `unordered_map<char, int>` to store character → last seen index
   - `left = 0`, `maxLength = 0` to track window and result
2. **Iterate with Right Pointer**: Expand window by moving right
3. **Check for Duplicate**:
   - If character exists in map and its index >= left
   - This means it's in current window
4. **Update Left Pointer**: 
   - Jump directly: `left = map[char] + 1`
   - No need to remove characters one by one
5. **Update HashMap**: Store current character's index
6. **Calculate Length**: `maxLength = max(maxLength, right - left + 1)`
7. **Return Result**: Final maxLength after processing all characters

**Key Advantage**: When duplicate found at index `i`, we know all characters before `map[s[i]]` can be skipped. Direct jump saves operations!

#### Approach 2: Sliding Window + Set (Alternative)
1. **Initialize**: `unordered_set<char>` for unique characters, `left = 0`
2. **Expand Right**: Add characters to set while they're unique
3. **Handle Duplicate**: 
   - While character exists in set
   - Remove `s[left]` from set
   - Increment `left`
4. **Track Maximum**: Update max length at each step
5. **Continue**: Process until right pointer reaches end

**Difference**: This approach removes characters sequentially, potentially doing more operations than HashMap approach.

### Common Pitfalls
- ❌ Confusing substring with subsequence
- ❌ Not updating left pointer correctly when duplicate found
- ❌ Forgetting to update character position in map
- ❌ Using `left = map[char] + 1` without checking if index is in current window
- ❌ Not handling empty string edge case
- ❌ Calculating length as `right - left` instead of `right - left + 1`
- ❌ Not considering all possible characters (spaces, symbols, etc.)

### Optimization Guidelines
- ✅ **Use HashMap for position tracking** - enables optimal jumping
- ✅ **Update left wisely**: `left = max(left, map[char] + 1)` prevents backward movement
- ✅ **Single pass is enough** - no need to revisit characters
- ✅ **Consider using array** for known small charset (e.g., `int[128]` for ASCII)
- ✅ **Update map every iteration** regardless of duplicate status
- ✅ **Track max continuously** rather than at the end

---

## 💡 Key Insights

1. **HashMap Optimization Wins**: Storing indices allows direct jumping, avoiding redundant character removals
2. **Sliding Window Pattern**: Perfect for contiguous subarray/substring problems
3. **Greedy is Optimal**: Always expand as much as possible before contracting
4. **Position Matters**: Not just "is character present?" but "where was it last seen?"
5. **Max Check Updates**: Keep comparing and updating max at each valid window
6. **Single Pass Efficiency**: With HashMap, right pointer visits each character exactly once
7. **No Backtracking Needed**: Once left moves forward, it never goes back

---

## 📈 HashMap vs Set Comparison

| Feature | HashMap (Index Tracking) | Set (Presence Only) |
|---------|-------------------------|---------------------|
| **Duplicate Found** | Jump left directly to safe position | Remove characters one by one |
| **Worst Case Operations** | O(n) - each char visited once | O(2n) - char added and removed |
| **Code Complexity** | Slightly more (track indices) | Simpler (just add/remove) |
| **Memory** | Stores char + index | Stores char only |
| **Best For** | Optimal performance | Learning/simplicity |
| **Jump Logic** | `left = max(left, map[char] + 1)` | `while(set.count(char)) remove(left++)` |

> **Pro Tip**: The HashMap approach with index tracking is the **gold standard** solution used by experienced programmers. It demonstrates understanding of optimization and efficient algorithmic thinking.

---

## 🎓 Why This Approach is Excellent

This implementation using `unordered_map` demonstrates several key strengths:

### 🌟 Code Analysis of This Solution

```cpp
int lengthOfLongestSubstring(string s)
{
    int length = 0;           // Track maximum length found
    int start = 0;            // Left boundary of sliding window

    unordered_map<char, int> mySet;  // Store char -> last seen index
    
    for (int i = 0; i < s.length(); i++)
    {
        // If character seen before AND within current window
        if (mySet.find(s[i]) != mySet.end())
            start = max(start, mySet[s[i]] + 1);  // Smart jump!
        
        mySet[s[i]] = i;                          // Update position
        length = max(length, i - start + 1);      // Track max
    }
    return length;
}
```

### ✅ What Makes This Code Excellent:

1. **Optimal Jump Strategy**: 
   - Uses `start = max(start, mySet[s[i]] + 1)` 
   - Prevents `start` from moving backward
   - Handles overlapping windows correctly

2. **Clean Logic Flow**:
   - Single loop iterating through string once
   - Updates happen in correct order
   - No nested loops or unnecessary operations

3. **Always Update Position**:
   - `mySet[s[i]] = i` happens every iteration
   - Keeps track of most recent position
   - Critical for correct jump calculations

4. **Continuous Max Tracking**:
   - `length = max(length, i - start + 1)` every iteration
   - No need to recalculate at the end
   - Captures maximum at each valid window

5. **True O(n) Complexity**:
   - Each character visited exactly once
   - HashMap operations are O(1) average
   - No character removal operations needed

### 🎯 Interview-Ready Features:

- ✅ **Understanding of optimization** - HashMap with indices beats Set approach
- ✅ **Handles edge cases** - Empty string returns 0, single char works
- ✅ **Prevents backward movement** - `max(start, ...)` is crucial detail
- ✅ **Memory efficient** - Only stores necessary information
- ✅ **Clean variable names** - `start`, `length`, descriptive and clear

### 💎 Key Insight in Your Code:

The line `start = max(start, mySet[s[i]] + 1)` is **critical**! 

Without `max()`, if we encounter a character whose last occurrence was before our current window, we'd incorrectly move `start` backward. For example:
- Window is at [3, 5]
- Find character last seen at index 1
- Without max: start becomes 2 (wrong! moves backward)
- With max: start stays 3 (correct! maintains window)

This shows **deep understanding** of the algorithm!

The HashMap approach is **superior** to the set approach and your implementation is **exactly what interviewers want to see**!

---

## 📝 Related Problems

- **159. Longest Substring with At Most Two Distinct Characters**: Extension with k distinct limit
- **340. Longest Substring with At Most K Distinct Characters**: Generalized version
- **76. Minimum Window Substring**: Similar sliding window technique
- **438. Find All Anagrams in a String**: Fixed-size sliding window
- **567. Permutation in String**: Sliding window with character frequency

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

**Problem Type:** Sliding Window • HashMap • Two Pointers • String

**Last Updated:** 📅 2025-01-22

</div>