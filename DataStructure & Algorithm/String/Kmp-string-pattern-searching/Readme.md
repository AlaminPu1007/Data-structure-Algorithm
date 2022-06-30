
# KMP Algorithm (Knuth Morris Pratt Algorithm)

** Overview : **

KMP algorithm is used to find a "Pattern" in a "Text". This algorithm compares character by character from left to right. <br>
But whenever a mismatch occurs, it uses a preprocessed table called "LPS Table" to skip characters comparison while matching.<br>

** More about LPS Table:  **
https://github.com/AlaminPu1007/Data-structure-Algorithm/blob/master/DataStructure%20%26%20Algorithm/String/LPS-Table/Readme.md


The KMP algorithm was the first-ever string matching algorithm that ran in linear time. <br>
Most of the naive string matching algorithms run in O(n*m) time, <br>
while the KMP algorithm runs in O(m + n) time where n is the length of the string, <br>
and m is the length of the pattern. <br>

The KMP matching algorithm uses degenerating property (pattern having same sub-patterns appearing more than once in the pattern) of the pattern and improves the worst case complexity to O(n).<br>
The basic idea behind KMP’s algorithm is: whenever we detect a mismatch (after some matches), we already know some of the characters in the text of the next window. <br>
We take advantage of this information to avoid matching the characters that we know will anyway match.<br>

** More about KMP : **
https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/

** Complexity :**

Time complexity - O(n + m) <br>

** Source :**
i) https://www.scaler.com/topics/data-structures/kmp-algorithm/<br>
ii)https://www.google.com/ <br>