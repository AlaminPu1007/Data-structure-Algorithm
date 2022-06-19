# LPS Table

* Name lps indicates longest proper prefix which is also suffix.<br>

A proper prefix is prefix with whole string not allowed.<br>
For example, prefixes of “ABC” are “ ”, “A”, “AB” and “ABC”.<br>
Proper prefixes are “”, “A” and “AB”. Suffixes of the string are “”, “C”, “BC” and “ABC”.<br>

We search for lps in sub-patterns.<br> 
More clearly we focus on sub-strings of patterns that are either prefix and suffix.<br>

for pattern = "aaab"
value of lps table = [0 1 2 0]

i = 1, j = 0, c = 0

lps[0] = 0 // initial value is always 0

while i = 0 to i <= n;

if pattern[j] == pattern[i]
then := lps[++c] = j + 1; // always summition 1 with j(index) value
then := i = i + 1;
then := j = j + 1;

let discuss about this code, if we get any matching value from present j to next i character<br>
we put lps[++c] = j + 1// j = a, i = a// matching <br>

else {

  if j == 0

  then := lps[++c] = 0
  then := i = i + 1
  
   else 
     j = lps[j - 1] // we take the previous value from lps table,	

}

if j = 0, we will not increase of i value,<br>
else we get j value from lps table, with j - 1, we not increase of i value this time.<br>




