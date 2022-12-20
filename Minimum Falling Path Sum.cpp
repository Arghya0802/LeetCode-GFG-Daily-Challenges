// Link: https://leetcode.com/problems/minimum-falling-path-sum/description/

class Solution {
private:

int minimumFallingPathSum(int currRow , int currCol , int n , vector<vector<int>> &matrix , vector<vector<int>> &dp)
{
    if(currCol < 0 || currCol >= n)
        return 10000 ;

    if(currRow == n - 1)
        return matrix[currRow][currCol] ;

    if(dp[currRow][currCol] != INT_MAX)
        return dp[currRow][currCol] ;

    int currVal = matrix[currRow][currCol] ;

    int op1 = minimumFallingPathSum(currRow + 1 , currCol - 1 , n , matrix , dp) + currVal ;
    int op2 = minimumFallingPathSum(currRow + 1 , currCol , n , matrix , dp) + currVal ;
    int op3 = minimumFallingPathSum(currRow + 1 , currCol + 1 ,n , matrix , dp) + currVal ;

    int ans = min(op1 , min(op2 , op3) ) ;

    return dp[currRow][currCol] = ans ;
}

public:
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int n = matrix.size() ;
        int ans = INT_MAX ;

        vector<vector<int>> dp(n + 1 , vector<int> (n + 1 , INT_MAX) ) ;

        for(int col = 0 ; col < n ; col++)
        {
            int tempAns = minimumFallingPathSum(0 , col , n , matrix , dp) ;

            ans = min(ans , tempAns) ;
        }

        return ans ;
    }
};

// Time Complexity:  O(N ^ 2)
// Space Complexity: O(N ^ 2)
