// Link: https://leetcode.com/problems/detect-capital/description/

// This problem is pretty straightforward - check the first character and do accordingly

class Solution {
public:
    bool detectCapitalUse(string &word) 
    {
        int n = word.size() ;
        char first = word[0] ;

        if(first >= 'a' && first <= 'z') // If the First Character is in SamllCase, all the letters have to be in Small Case
        {
            for(int i = 1 ; i < n ; i++)
            {
                char ch = word[i] ;

                if(ch >= 'A' && ch <= 'Z')
                    return false ;
            }

            return true ;
        }
        
        // Otherwise, We have 2 options
        // a) The First Character has to be UpperCase, rest all should be in LowerCase
        // b) All the Characters, including First Character, should be in UpperCase
      
        int upper = 1 , lower = 0 ; // We use upper and lower to count the number of Charaters in UpperCase and LowerCase respectively

        for(int i = 1 ; i < n ; i++)
        {
            char ch = word[i] ;

            if(ch >= 'A' && ch <= 'Z') // If any character is in Uppercase, we increment upper
                upper += 1 ;

            else // Otherwise, we increment lower as the Character is in LowerCase
                lower += 1 ;
        }
        
        // If all the characters are in UpperCase(upper == n) OR (n - 1) characters are in LowerCase, our condition is fullfilled, so we return true
      
        return upper == n || lower == (n - 1) ? true : false ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(1)
