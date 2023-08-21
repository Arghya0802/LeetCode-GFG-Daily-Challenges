// Link: https://leetcode.com/problems/repeated-substring-pattern/description/

class Solution {
private:

bool isOkay(int ind , int k , string &prefix , string &s)
{
    int j = 0 ;

    for(int i = ind ; i < s.size() ; i++)
    {
        if(prefix[j] != s[i] )  return false ;

        j++ ;

        if(j == k)  j = 0 ;    
    }

    return true ;
}

public:
    bool repeatedSubstringPattern(string &s) 
    {
        string prefix = "" ;  int n = s.size() ;

        for(int i = 0 ; i < n - 1 ; i++)
        {
            prefix += s[i] ;  int k = prefix.size() ;

            if(n % k != 0)   continue ;

            if(isOkay(i + 1 , k , prefix , s)  )  return true ;
        }

        return false ;
    }
};

// Time Complexity:  O(N ^ 2)
// Space Complexity: O(N)
