// Link: https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/

// Exactly same as Longest Palindromic Subsequence [a little change in the return function only]

class Solution {
private:
int dp[501][501] ;

int lengthOfLPS(int i , int j , int n , string &s , string &t)
{
    if(i >= n || j >= n)  return 0 ;

    if(dp[i][j] != -1)  return dp[i][j] ;

    int ans = 0 ;

    if(s[i] == t[j])  ans = 1 + lengthOfLPS(i + 1 , j + 1 , n , s , t) ;

    else
    {
        int opS = lengthOfLPS(i + 1 , j , n , s , t) ;
        int opT = lengthOfLPS(i , j + 1 , n , s , t) ;

        ans = max(opS , opT) ;
    }

    return dp[i][j] = ans ;
}

public:
    int minInsertions(string &s) 
    {
        int n = s.size() ;
    
        string rev = s ;    

        reverse(rev.begin() , rev.end() ) ;

        for(int i = 0 ; i < 501 ; i++)
        {
            for(int j = 0 ; j < 501 ; j++)  dp[i][j] = -1 ;
        }

        return n - lengthOfLPS(0 , 0 , n , s , rev) ;
    }
};

// Time Complexity:  O(N ^ 2)
// Space Complexity: O(N ^ 2)
