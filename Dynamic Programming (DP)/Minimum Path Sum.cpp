// Link: https://leetcode.com/problems/minimum-path-sum/description/

class Solution {
private:

int dfs(int currRow , int currCol , int m , int n , vector<vector<int>> &grid , vector<vector<int>> &dp)
{
    if(currRow < 0 || currRow >= m || currCol < 0 || currCol >= n)
        return 10000 ;

    if(currRow == m - 1 && currCol == n - 1)
        return grid[currRow][currCol]  ;

    if(dp[currRow][currCol] != -1)
        return dp[currRow][currCol] ;

    int right = dfs(currRow , currCol + 1 , m , n , grid , dp) + grid[currRow][currCol] ;
    int down  = dfs(currRow + 1 , currCol , m , n , grid , dp) + grid[currRow][currCol] ;

    return dp[currRow][currCol] = min(right , down) ;
}

public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m = grid.size() ;
        int n = grid[0].size() ;

        vector<vector<int>> dp(m + 1 , vector<int> (n + 1 , -1)) ;

        int ans = dfs(0 , 0 , m , n , grid , dp) ;    

        return ans ;
    }
};

// Time Complexity:  O(M * N)
// Space Complexity: O(M * N)
