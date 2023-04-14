// Link:

class Solution {
private:

int longestPalinSubseq(int i , int j , int n , string &s , string &t , vector<vector<int>> &dp)
{
    if(i >= n || j >= n)  return 0 ;

    if(dp[i][j] != -1)  return dp[i][j] ;
    
    int ans = 0 ;

    if(s[i] == t[j])
        ans = 1 + longestPalinSubseq(i + 1 , j + 1 , n , s , t , dp) ;

    else
    {
        int op1 = longestPalinSubseq(i + 1 , j , n , s , t , dp) ;
        int op2 = longestPalinSubseq(i , j + 1 , n , s , t , dp) ;

        ans = max(op1 , op2) ;
    }

    return dp[i][j] = ans ;
}

public:
    int longestPalindromeSubseq(string &s) 
    {
        int n = s.size() ;
        string rev = s ;

        vector<vector<int>> dp(n + 1 , vector<int> (n + 1 , -1) ) ;

        reverse(rev.begin() , rev.end()) ;

        return longestPalinSubseq(0 , 0 , n , s , rev , dp) ;    
    }
};

// Time Complexity:  O(N ^ 2)
// Space Complexity: O(N ^ 2)
