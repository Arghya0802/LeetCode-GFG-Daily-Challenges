// Link:  https://practice.geeksforgeeks.org/problems/palindrome-string0817/1

class Solution {
    int isPalindrome(String S) 
    {
        int low = 0 ;  int high = S.length() - 1 ;
        
        while(low <= high)
        {
            if(S.charAt(low) != S.charAt(high) )  return 0 ;
            
            low++ ; high--; 
        }
        
        return 1 ; 
    }
};

