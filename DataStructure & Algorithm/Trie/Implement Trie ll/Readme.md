## Implement Trie II

This problem involved about, Ninja has to implement a data structure ”TRIE” from scratch. Ninja has to complete some functions.

1. Trie(): Ninja has to initialize the object of this “TRIE” data structure.

2. insert(“WORD”): Ninja has to insert the string “WORD” into this “TRIE” data structure.

3. countWordsEqualTo(“WORD”): Ninja has to return how many times this “WORD” is present in this “TRIE”.

4. countWordsStartingWith(“PREFIX”): Ninjas have to return how many words are there in this “TRIE” that have the string “PREFIX” as a prefix.

5. erase(“WORD”): Ninja has to delete one occurrence of the string “WORD” from the “TRIE”.

# Problem description

For better problem description, please visit [Code Ninja](https://www.codingninjas.com/studio/problems/implement-trie_1387095), [LeetCode Page](https://leetcode.com/problems/implement-trie-ii-prefix-tree/description/)

**Approach :**<br/>

1. **Insert**: Traverse through each character of the word. For each character, check if it exists in the current node's children. If not, create a new node. Update the prefix count of each node along the traversal path. At the end of the word, increment the word count of the last node.

2. **Count Words Equal To**: Traverse through each character of the word. If the character exists in the trie, move to the next node. If the traversal completes successfully, return the word count of the last node; otherwise, return 0.

3. **Count Words Starting With**: Similar to Count Words Equal To operation, traverse through each character of the prefix. If the traversal completes successfully, return the prefix count of the last node; otherwise, return 0.

4. **Erase**: Traverse through each character of the word. While traversing, reduce the prefix count of each node. At the end of the word, decrement the word count of the last node.

**Complexity Analysis :**<br/>

-   Time-Complexity:

    -   `Insertion: O(m)`, where m is the length of the word to be inserted.
    -   `Count Words Equal To: O(m)`, where m is the length of the given word.
    -   `Count Words Starting With: O(m)`, where m is the length of the given prefix.
    -   `Erase: O(m)`, where m is the length of the word to be erased.

-   Space-Complexity:
    -   The space complexity of the trie depends on the number of words inserted and the average length of the words. In this implementation, each node contains an array of size 26 to store links to child nodes, resulting in a space complexity of `O(n*m)`, where `n` is the number of words and m is the average length of the words.
