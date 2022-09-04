#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public: 
  void Recursion_Subsequence(int i, string rootString, string copyString)
  {
      if(i >= rootString.size())
      {
          cout<<copyString<<endl;
          return;  
      }
      //store each subsequence
      copyString += rootString[i];
      
      Recursion_Subsequence(i+1, rootString, copyString);
      //after complete first recursion tree completely
      // we need to pop last value
      copyString.pop_back();
      
      //get subsequecy after pop last element
      Recursion_Subsequence(i+1, rootString, copyString);
  }
};

int main(void)
{
    Solution obj;
    
    string str = "312", result = "";
    obj.Recursion_Subsequence(0, str, result);
    
    return 0;
}