# Power Set : Print all the possible subsequences of the String

**Approach :**<br>
To print all the possible subsequence of the given string, we followed power set algorithm.<br>
This algorithm basically follow the procedure of bit manipulation by check whether the i'th bit is set or not.<br>

if(n & (1 << i)) != 0, thats means the bit is set. Whenever the bit is set, we will take that character from our given string at using this i'th position<br>

**Complexity :**<br>
Time Complexity: O(2^n x n)<br>
Reason: O(2^n) for the outer for loop and O(n) for the inner for loop.<br>
Space Complexity: O(1)<br>

**References :**<br>
https://www.geeksforgeeks.org/power-set/<br>
https://takeuforward.org/data-structure/power-set-print-all-the-possible-subsequences-of-the-string/
