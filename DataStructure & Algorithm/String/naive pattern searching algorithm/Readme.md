# Naive Pattern Searching

**Description :**

Naive pattern searching is the simplest method among other pattern searching algorithms. <br>
It checks for all character of the main string to the pattern.<br>

This is our main string.<br>
    string str = "ABCDEABC"; <br>
This is our searching pattern string. We have to find this string inside of main string.<br>
    string pattern = "ABC";<br>

**Algorithm : **


   for i := 0 to strLen , do
      for j := 0 to patLen, do
         if str[i+j] != pattern[j], then
            break the loop
      done

      if j == patLen, then
         display the position i, as there pattern found
   done
End

The idea behind of naive algorithm is that, whenever we get any miss-matching character along str[i] != pattern[i].<br>
We need tp break our iteration, and check with it i of next iteration.<br>

**Complexity :**

The time complexity of Naïve Pattern Search method is O(m*n).<br> 
The m is the size of pattern and n is the size of the main string.<br>