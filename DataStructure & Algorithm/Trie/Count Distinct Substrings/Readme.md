## Count Distinct Substrings

This problem involved about, given a string 'S', you are supposed to return the number of distinct substrings(including empty substring) of the given string. You should implement the program using a trie.

# Problem description

For better problem description, please visit [Here](https://www.codingninjas.com/studio/problems/count-distinct-substrings_985292?leftPanelTabValue=PROBLEM)

**Approach :**<br/>

1. Implement a Trie data structure to efficiently store and query substrings.
2. Create a Trie node with an array of Trie pointers, `list`, representing each character ('a' to 'z').
3. Define methods in the Trie class:
    - `containsKey(char ch)`: Check if the Trie node contains a child node for the given character.
    - `insertIntoList(char ch, Trie *node)`: Insert a new Trie node into the `list` at the index corresponding to the given character.
    - `get(char ch)`: Get the Trie node associated with the given character.
4. Iterate through each character of the input string `s`.
5. For each starting index `i` in the string, traverse the substring starting from index `i` to the end of the string.
6. At each position `j`, check if the substring from `i` to `j` is already present in the Trie.
    - If not present, insert the substring into the Trie and increment the count of distinct substrings.
7. Finally, return the count of distinct substrings plus 1 (accounting for the empty string).

**Complexity Analysis:**<br/>

-   Time-Complexity:`O(n^2)` - In Trie each substring from every starting index needs to be inserted.

-   Space-Complexity: It's really hard to get actual space complexity of using trie algorithm
