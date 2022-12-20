// Link: https://leetcode.com/problems/longest-common-subsequence/description/

class Solution {
private:

int findLCS(int i , int j , int m , int n , string &A , string &B , vector<vector<int>> &dp)
{
    if(i == m || j == n)
        return 0 ;

    if(dp[i][j] != -1)
        return dp[i][j] ;
    
    int ans = 0 ;

    if(A[i] == B[j])
        ans = 1 + findLCS(i + 1 , j + 1 , m , n , A , B , dp) ;

    else
    {
        int op1 = findLCS(i + 1 , j , m , n , A , B , dp) ;
        int op2 = findLCS(i , j + 1 , m , n , A , B , dp) ;

        ans = max(op1 , op2) ;
    }

    return dp[i][j] = ans ;
}

public:
    int longestCommonSubsequence(string &text1, string &text2) 
    {
        int m = text1.size() ;
        int n = text2.size() ;

        vector<vector<int>> dp(m + 1 , vector<int> (n + 1 , -1) ) ;

        int ans = findLCS(0 , 0 , m , n , text1 , text2 , dp) ;

        return ans ;
    }
};

// Time Complexity:  O(N ^ 2)
// Space Complexity: O(N ^ 2)
