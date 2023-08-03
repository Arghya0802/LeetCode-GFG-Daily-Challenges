// Link:  https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

class Solution {
private:
vector<string> ans ;
vector<string> phone ;

void letterCombinations(int ind , string &s , string &digits)
{
    if(ind >= digits.size() )
    {
        if(s.size() > 0) ans.push_back(s) ;  
        
        return ;
    }

    int idx = digits[ind] - '0' ;
    
    for(int i = 0 ; i < phone[idx].size() ; i++)
    {
        s += phone[idx][i] ; 

        letterCombinations(ind + 1 , s , digits) ;

        s.pop_back() ;
    }

    return ;
}

public:
    vector<string> letterCombinations(string &digits) 
    {
        phone = {"" , "" , "abc" , "def" , "ghi" , "jkl" , "mno" , "pqrs" , "tuv" , "wxyz"} ;

        string s = "" ;

        letterCombinations(0 , s , digits) ;    

        return ans ;
    }
};

// Time Complexity:  O(Exponential)
// Space Complexity: O(Exponetial)
