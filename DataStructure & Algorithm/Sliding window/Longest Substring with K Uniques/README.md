# Longest Substring with K Uniques

This problem involved about, you are given a string s consisting only lowercase alphabets and an integer k. Your task is to find the length of the longest substring that contains exactly k distinct characters.

## Problem description

For better problem description, please visit [LeetCode Page](https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1)

**Key Insights :**<br/>

1. `Sliding Window Technique`: We'll maintain a window that can expand and shrink based on the number of unique characters.
2. `Character Frequency Tracking`: Use a hash map to track the frequency of characters in the current window.
3. `Window Adjustment`: When we exceed `k` unique characters, we'll shrink the window from the left until we're back to `k` unique characters.

**Algorithm Steps :**<br/>

1. `Initialize`:
    - Left pointer `left` to track window start
    - Hash map `Map` to track character frequencies
    - Result variable `res` to store maximum length found
2. `Expand Window`:
    - For each character, add to frequency map
3. `Shrink Window`:
    - When unique characters exceed `k`, move left pointer
    - Decrement count of leftmost character
    - Remove character from map if count reaches zero
4. `Update Result`:
    - After ensuring window has ≤ `k` unique characters, update maximum length
5. `Return` the maximum length found

**Complexity Analysis :**<br/>

-   Time-Complexity: `O(n)` - where n is string length.
-   Space-Complexity: `O(k)` - to store character frequencies.
